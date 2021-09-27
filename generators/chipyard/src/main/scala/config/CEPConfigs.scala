package chipyard

import freechips.rocketchip.config.{Config}
import freechips.rocketchip.diplomacy.{AsynchronousCrossing}
//
// Define the default configuration for the CEP
// Addresses and other parameter overrides are definied in ConfigFragments.scala
// AbstractCEPConfig is definied in AbstractConfig.scala
//

class CEPRocketConfig extends Config(
  // Instantiate four Rocket Cores 
  new freechips.rocketchip.subsystem.WithNBigCores(4) ++

  // Add the CEP Accelerator Cores
  new chipyard.config.WithAES ++
  new chipyard.config.WithDES3 ++
  new chipyard.config.WithIIR ++
  new chipyard.config.WithIDFT ++
  new chipyard.config.WithGPS ++
  new chipyard.config.WithMD5 ++
  new chipyard.config.WithIIR ++
  new chipyard.config.WithFIR ++
  new chipyard.config.WithSHA256 ++
  new chipyard.config.WithRSA ++
  new chipyard.config.WithCEPRegisters ++
  new chipyard.config.WithScratchpad ++
  new chipyard.config.WithSROT ++

  // Moved IO declerations from AbstractCEPConfig to here for readability
  new chipyard.config.WithUART(address = 0x64000000L) ++
  new chipyard.config.WithGPIO(address = 0x64002000L, width = 8) ++

  // Override external memory size to be equal to that of the U500 on the VC707 (1 GB)
  new freechips.rocketchip.subsystem.WithExtMemSize((1 << 30) * 1L) ++

  // Set the remainder of the configuration items
  new chipyard.config.AbstractCEPConfig
)

