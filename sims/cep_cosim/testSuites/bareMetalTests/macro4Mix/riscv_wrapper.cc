//--------------------------------------------------------------------------------------
// Copyright 2022 Massachusets Institute of Technology
// SPDX short identifier: BSD-2-Clause
//
// File Name:      riscv_wrapper.cc
// Program:        Common Evaluation Platform (CEP)
// Description:    RISC-V template for MacroMix
// Notes:          
//
//--------------------------------------------------------------------------------------




//
// For bareMetal mode ONLY
//
#ifdef BARE_MODE
  #include "cep_apis.h"
  #include "portable_io.h"
  #include "CEP.h"
  #include "cepRegTest.h"

  // Include the test vectors related to this test
  #include "SROT_playback.h"
  #include "RSA_playback.h"
  #include "DES3_playback.h"
  #include "DFT_playback.h"
  #include "IDFT_playback.h"

  #ifdef __cplusplus
  extern "C" {
  #endif

  int cep_readNspin(int coreIndex, uint32_t pAddress,uint64_t pData,uint64_t mask, int timeOut) {
    uint64_t rdDat;
    while (timeOut > 0) {
      rdDat = cep_read64(coreIndex, pAddress);
      if (((rdDat ^ pData) & mask) == 0) {
        break;
      }
      USEC_SLEEP(100);
      timeOut--;
    };
    return (timeOut <= 0) ? 1 : 0;  
  }

  void thread_entry(int cid, int nc) {
    
    int errCnt    = 0;
    int testId[4] = {0x00, 0x11, 0x22, 0x33};
    int coreId    = read_csr(mhartid);
    int revCheck  = 1;
    int verbose   = 0;
    int maxTO     = 5000;
    uint64_t upper;
    uint64_t lower;
    
    // Set the current core's status to running
    set_cur_status(CEP_RUNNING_STATUS);

    // There is no Crypto++ support for RISC-V, so pre-recorded vectors will be used
    if (coreId == 0) {
      upper = SROT_adrBase + SROT_adrSize;
      lower = SROT_adrBase;
      errCnt += cep_playback(SROT_playback, upper, lower, SROT_totalCommands, 0);
      cep_write64(CEP_VERSION_REG_INDEX, cep_scratch4_reg, CEP_OK2RUN_SIGNATURE);
      upper = RSA_adrBase + RSA_adrSize;
      lower = RSA_adrBase;
      errCnt += cep_playback(RSA_playback, upper, lower, RSA_totalCommands, 0);    
    }
    else if (coreId == 1) {
      errCnt += cep_readNspin(CEP_VERSION_REG_INDEX, cep_scratch4_reg, CEP_OK2RUN_SIGNATURE, 0xFFFFFFFF, maxTO); 
      if (errCnt) goto cleanup;
      upper = DES3_adrBase + DES3_adrSize;
      lower = DES3_adrBase;
      errCnt += cep_playback(DES3_playback, upper, lower, DES3_totalCommands, 0);    
    }
    else if (coreId == 2) {
      errCnt += cep_readNspin(CEP_VERSION_REG_INDEX, cep_scratch4_reg, CEP_OK2RUN_SIGNATURE, 0xFFFFFFFF, maxTO); 
      if (errCnt) goto cleanup;
      upper = DFT_adrBase + DFT_adrSize;
      lower = DFT_adrBase;
      errCnt += cep_playback(DFT_playback, upper, lower, DFT_totalCommands, 0);    
    }
    else if (coreId == 3) {
      errCnt += cep_readNspin(CEP_VERSION_REG_INDEX, cep_scratch4_reg, CEP_OK2RUN_SIGNATURE, 0xFFFFFFFF, maxTO); 
      if (errCnt) goto cleanup;
      upper = IDFT_adrBase + IDFT_adrSize;
      lower = IDFT_adrBase;
      errCnt += cep_playback(IDFT_playback, upper, lower, IDFT_totalCommands, 0);    
    }  

    // Set the core status
cleanup:
    set_status(errCnt, testId[coreId]);

    // Exit with the error count
    exit(errCnt);
  }

  #ifdef __cplusplus
  }
  #endif
  
#endif // #ifdef BARE_MODE
