//--------------------------------------------------------------------------------------
// Copyright 2021 Massachusetts Institute of Technology
// SPDX short identifier: BSD-2-Clause
//
// File Name:      v2c_top.v
// Program:        Common Evaluation Platform (CEP)
// Description:    System Level testbench driver
// Notes:          
//
//--------------------------------------------------------------------------------------

`include "suite_config.v"
`include "cep_hierMap.incl"
`include "cep_adrMap.incl"
`include "v2c_cmds.incl"
`include "v2c_top.incl"

module v2c_top (
  input               clk,
  output reg [31:0]   __simTime = 0
);

  parameter MY_SLOT_ID  = `SYSTEM_SLOT_ID;
  parameter MY_CPU_ID   = `SYSTEM_CPU_ID;

  //--------------------------------------------------------------------------------------
  // Define system driver supported DPI tasks prior to the inclusion of sys_common.incl
  //--------------------------------------------------------------------------------------    
  // WRITE32_64
  `define SHIPC_WRITE32_64_TASK WRITE32_64_DPI()
  task WRITE32_64_DPI;
    reg [63:0] d;
    begin
      d[63:32] = inBox.mPar[0];
      d[31:0]  = inBox.mPar[1];

      `COSIM_TB_TOP_MODULE.write_mainmem_backdoor(inBox.mAdr, d);
    end
  endtask // WRITE32_64_DPI

  // READ32_64
  `define SHIPC_READ32_64_TASK READ32_64_DPI()
  task READ32_64_DPI;
    reg [63:0] d;
    begin
      `COSIM_TB_TOP_MODULE.read_mainmem_backdoor(inBox.mAdr, d);      
      
      inBox.mPar[0] = d[63:32];
      inBox.mPar[1] = d[31:0];      
    end
  endtask // READ32_64_DPI
  //--------------------------------------------------------------------------------------



  //--------------------------------------------------------------------------------------
  // SHIPC Support Common Codes
  //
  // These includes must remain within the verilog module and
  // is dependent on the SHIPC_CLK macro.
  //--------------------------------------------------------------------------------------
  `define   SHIPC_CLK   clk
  `include "sys_common.incl"
  `include "dump_control.incl"      
  `undef    SHIPC_CLK
  //--------------------------------------------------------------------------------------



  //--------------------------------------------------------------------------------------
  // System Driver supported DVT tasks
  //--------------------------------------------------------------------------------------
  always @(posedge dvtFlags[`DVTF_SET_IPC_DELAY]) begin
    `logI("Setting ipcDelay to %0d", ipcDelay);
    ipcDelay = dvtFlags[`DVTF_PAT_LO];
    dvtFlags[`DVTF_SET_IPC_DELAY] = 0;
  end
  
  reg     program_loaded = 0;

  always @(posedge `DVT_FLAG[`DVTF_SET_PROGRAM_LOADED]) begin
    `logI("Program is now loaded");
    program_loaded = `DVT_FLAG[`DVTF_PAT_LO];
    `DVT_FLAG[`DVTF_SET_PROGRAM_LOADED] = 0;
  end // always @(posedge `DVT_FLAG[`DVTF_SET_PROGRAM_LOADED])

  always @(posedge `DVT_FLAG[`DVTF_TOGGLE_CHIP_RESET_BIT]) 
  begin
    wait (`PBUS_RESET==0);
    @(negedge `PBUS_CLOCK);
    #2000;
    `logI("Asserting pbus_Reset");
    force `PBUS_RESET = 1;
    repeat (10) @(negedge `PBUS_CLOCK);
    #2000;
    release `PBUS_RESET;      
    `DVT_FLAG[`DVTF_TOGGLE_CHIP_RESET_BIT] = 0;
  end // always @(posedge `DVT_FLAG[`DVTF_TOGGLE_CHIP_RESET_BIT]) 

  always @(posedge `DVT_FLAG[`DVTF_TOGGLE_DMI_RESET_BIT]) 
  begin
    `logI("Forcing topMod_debug_ndreset");
    force `DEBUG_NDRESET = 1;
    repeat (10) @(negedge `PBUS_CLOCK);
    release `DEBUG_NDRESET;
    `DVT_FLAG[`DVTF_TOGGLE_DMI_RESET_BIT] = 0;
  end // always @(posedge `DVT_FLAG[`DVTF_TOGGLE_DMI_RESET_BIT]) 

  always @(posedge `DVT_FLAG[`DVTF_GET_SOCKET_ID_BIT]) 
  begin
    `logI("DVTF_GET_SOCKET_ID_BIT");
    `ifdef OPENOCD_ENABLE
      `DVT_FLAG[`DVTF_PAT_HI:`DVTF_PAT_LO] = jtag_getSocketPortId();
    `endif
    `logI("SocketId = 0x%08x",`DVT_FLAG[`DVTF_PAT_HI:`DVTF_PAT_LO]);
    `DVT_FLAG[`DVTF_GET_SOCKET_ID_BIT] = 0;
  end // always @(posedge `DVT_FLAG[`DVTF_GET_SOCKET_ID_BIT])

  // Force CHIP_ID's when operating in BFM_MODE (otherwise these parameters don't exist)
  `ifdef BFM_MODE
    defparam `CORE0_TL_PATH.CHIP_ID = 0;
    defparam `CORE1_TL_PATH.CHIP_ID = 1;
    defparam `CORE2_TL_PATH.CHIP_ID = 2;
    defparam `CORE3_TL_PATH.CHIP_ID = 3;
  `endif

  reg enableWrTrace   = 0;
  reg enableRdTrace   = 0;   
  
  always @(posedge `DVT_FLAG[`DVTF_DISABLE_MAIN_MEM_LOGGING]) begin
    enableWrTrace = 0;
    enableRdTrace = 0;      
    `DVT_FLAG[`DVTF_DISABLE_MAIN_MEM_LOGGING] = 0;
  end
  
  always @(posedge `DVT_FLAG[`DVTF_ENABLE_MAIN_MEM_LOGGING]) begin
    enableWrTrace = 1;
    enableRdTrace = 1;            
    `DVT_FLAG[`DVTF_ENABLE_MAIN_MEM_LOGGING] = 0;
  end
  always @(posedge `DVT_FLAG[`DVTF_ENABLE_MAIN_MEMWR_LOGGING]) begin
    enableWrTrace = 1;
    `DVT_FLAG[`DVTF_ENABLE_MAIN_MEMWR_LOGGING] = 0;
  end
  always @(posedge `DVT_FLAG[`DVTF_ENABLE_MAIN_MEMRD_LOGGING]) begin
    enableRdTrace = 1;            
    `DVT_FLAG[`DVTF_ENABLE_MAIN_MEMRD_LOGGING] = 0;
  end
  

//--------------------------------------------------------------------------------------









  //--------------------------------------------------------------------------------------
  // System Driver support tasks when running the RISCV_TESTS
  //--------------------------------------------------------------------------------------
  // This is to handle single threading core: one core active at a time
  `ifdef RISCV_TESTS
    initial begin
      `logI("==== ISA RISCV_TESTS is active ===");      
    end
   
    int virtualMode = 0;
   
    always @(posedge dvtFlags[`DVTF_SET_VIRTUAL_MODE]) begin
      dvtFlags[`DVTF_SET_VIRTUAL_MODE] = 0;
    end
   
    int         curCore         = 0;
    reg         singleThread    = 0;
    reg [3:0]   coreActiveMask  = 0;

    // Utility to force a single threaded (one core) operation
    always @(posedge dvtFlags[`DVTF_FORCE_SINGLE_THREAD]) begin
      coreActiveMask = dvtFlags[`DVTF_PAT_HI:`DVTF_PAT_LO] ;
      singleThread = 1;
      `logI("==== Force-ing Single Thread coreMask=0x%x===",coreActiveMask);
      dvtFlags[`DVTF_FORCE_SINGLE_THREAD] = 0;
    end
   
    always @(posedge dvtFlags[`DVTF_PASS_IS_TO_HOST]) begin
      `CORE0_DRIVER.checkToHost = 1;
      `CORE1_DRIVER.checkToHost = 1;
      `CORE2_DRIVER.checkToHost = 1;
      `CORE3_DRIVER.checkToHost = 1;
      dvtFlags[`DVTF_PASS_IS_TO_HOST] = 0; // self-clear
    end   
   
    // Force all cores into reset
    task ResetAllCores;
      begin
        force `CORE0_PATH.reset = 1;
        force `CORE1_PATH.reset = 1;
        force `CORE2_PATH.reset = 1;
        force `CORE3_PATH.reset = 1;
   
        repeat (2) @(posedge clk);
   
        release `CORE0_PATH.reset;  
        release `CORE1_PATH.reset;  
        release `CORE2_PATH.reset;  
        release `CORE3_PATH.reset;  
      end
    endtask // ResetAllCores
   
    // Force single-threaded operation
    always @(posedge singleThread) begin
   
      // Put all the cores into reset
      force `CORE0_PATH.reset =1; 
      force `CORE1_PATH.reset =1;
      force `CORE2_PATH.reset =1;
      force `CORE3_PATH.reset =1;

      // Ensure the program is loaded
      @(posedge `COSIM_TB_TOP_MODULE.program_loaded);
      
      // Allow caches to get out of reset but not the core!!!
      release `CORE0_PATH.reset; 
      release `CORE1_PATH.reset;
      release `CORE2_PATH.reset;
      release `CORE3_PATH.reset;
      force `CORE0_PATH.core.reset = 1; 
      force `CORE1_PATH.core.reset = 1;
      force `CORE2_PATH.core.reset = 1;
      force `CORE3_PATH.core.reset = 1;      
      
      // Cycle through all the cores
      for (int c = 0; c < 4; c = c + 1) 
      begin
   
        if (coreActiveMask[c]) begin
          case (c)

          // Core 0 is active
          0: begin
            `logI("Releasing CORE0 Reset....");
            if (virtualMode) begin
              ResetAllCores();
            end
            release `CORE0_PATH.core.reset; 
            @(posedge (`CORE0_DRIVER.PassStatus || `CORE0_DRIVER.FailStatus));
          end // Core 0 is active

          // Core 1 is active
          1: begin
            `logI("Releasing CORE1 Reset....");  
            if (virtualMode) begin
              ResetAllCores();
            end     
            release `CORE1_PATH.core.reset;
            @(posedge (`CORE1_DRIVER.PassStatus || `CORE1_DRIVER.FailStatus));
          end  // Core 1 is active

          // Core 2 is active
          2: begin
            `logI("Releasing CORE2 Reset....");  
            if (virtualMode) begin
              ResetAllCores();              
            end     
            release `CORE2_PATH.core.reset;
            @(posedge (`CORE2_DRIVER.PassStatus || `CORE2_DRIVER.FailStatus));
          end // Core 2 is active
        
          // Core 3 is active
          3: begin
            `logI("Releasing CORE3 Reset....");  
            if (virtualMode) begin
              ResetAllCores();
            end     
            release `CORE3_PATH.core.reset;
            @(posedge (`CORE3_DRIVER.PassStatus || `CORE3_DRIVER.FailStatus));
          end // Core 3 is active      
      
          endcase
        end // end if (coreActiveMask[c])
      end // for (int c=0;c<4;c=c+1)
    end // always @(posedge singleThread)
  `endif // endif `ifdef RISCV_TESTS
  //--------------------------------------------------------------------------------------

   
endmodule // v2c_top
