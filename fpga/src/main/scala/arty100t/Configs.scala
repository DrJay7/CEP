// See LICENSE for license details.
package chipyard.fpga.arty100t

import chisel3._

import sys.process._
import math.min

import org.chipsalliance.cde.config._
import freechips.rocketchip.subsystem._
import freechips.rocketchip.devices.debug._
import freechips.rocketchip.devices.tilelink._
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.system._
import freechips.rocketchip.tile._

import sifive.blocks.devices.uart._
import sifive.blocks.devices.gpio._
import sifive.fpgashells.shell.{DesignKey}

import testchipip.{SerialTLKey}

import chipyard.{BuildSystem}
import chipyard.iobinders.{OverrideIOBinder, OverrideLazyIOBinder}

import mitllBlocks.cep_addresses._

// don't use FPGAShell's DesignKey
class WithNoDesignKey extends Config((site, here, up) => {
  case DesignKey => (p: Parameters) => new SimpleLazyModule()(p)
})

class WithUARTIOPassthrough extends OverrideIOBinder({
  (system: HasPeripheryUARTModuleImp) => {
    val io_uart_pins_temp = system.uart.zipWithIndex.map { case (dio, i) => IO(dio.cloneType).suggestName(s"uart_$i") }
    (io_uart_pins_temp zip system.uart).map { case (io, sysio) =>
      io <> sysio
    }
    (io_uart_pins_temp, Nil)
  }
})
class WithGPIOIOPassthrough extends OverrideIOBinder({
  (system: HasPeripheryGPIOModuleImp) => {
    val io_gpio_pins_temp = system.gpio.zipWithIndex.map { case (dio, i) => IO(dio.cloneType).suggestName(s"gpio_$i") }
    (io_gpio_pins_temp zip system.gpio).map { case (io, sysio) =>
      io <> sysio
    }
    (io_gpio_pins_temp, Nil)
  }
})

class WithArty100TGPIO extends Config((site, here, up) => {
  case PeripheryGPIOKey => {
    if (Arty100TGPIOs.width > 0) {
      require(Arty100TGPIOs.width <= 64) // currently only support 64 GPIOs (change addrs to get more)
      val gpioAddrs = Seq(BigInt(0x64002000), BigInt(0x64007000))
      val maxGPIOSupport = 32 // max gpios supported by SiFive driver (split by 32)
      List.tabulate(((Arty100TGPIOs.width - 1)/maxGPIOSupport) + 1)(n => {
        GPIOParams(address = gpioAddrs(n), width = min(Arty100TGPIOs.width - maxGPIOSupport*n, maxGPIOSupport))
      })
    }
    else {
      List.empty[GPIOParams]
    }
  }
})

class WithCEPBootrom extends Config((site, here, up) => {
  case BootROMLocated(x) => up(BootROMLocated(x)).map { p =>
    val freqMHz = ((up(PeripheryBusKey).dtsFrequency.get).toDouble * 1e6).toLong
    val make = s"make -B -C fpga/src/main/resources/arty100t/cep_sdboot PBUS_CLK=${freqMHz} bin"
    require (make.! == 0, "Failed to build bootrom")
    p.copy(hang = 0x10000, contentFileName = s"./fpga/src/main/resources/arty100t/cep_sdboot/build/sdboot.bin")
  }
})

class WithArty100TTweaks extends Config(
  new chipyard.harness.WithAllClocksFromHarnessClockInstantiator ++
  new WithArty100TUARTTSI ++
  new WithArty100TDDRTL ++
  new WithNoDesignKey ++
  new chipyard.harness.WithHarnessBinderClockFreqMHz(50) ++
  new chipyard.config.WithMemoryBusFrequency(50.0) ++
  new chipyard.config.WithSystemBusFrequency(50.0) ++
  new chipyard.config.WithPeripheryBusFrequency(50.0) ++
  new chipyard.harness.WithAllClocksFromHarnessClockInstantiator ++
  new chipyard.clocking.WithPassthroughClockGenerator ++
  new chipyard.config.WithNoDebug ++ // no jtag
  new chipyard.config.WithNoUART ++ // use UART for the UART-TSI thing instad
  new chipyard.config.WithTLBackingMemory ++ // FPGA-shells converts the AXI to TL for us
  new freechips.rocketchip.subsystem.WithExtMemSize(BigInt(256) << 20) ++ // 256mb on ARTY
  new freechips.rocketchip.subsystem.WithoutTLMonitors)


class RocketArty100TCEPConfig extends Config(
  // Add the CEP registers
  new chipyard.config.WithCEPRegisters ++
//  new chipyard.config.WithAES ++
//  new chipyard.config.WithSROTFPGAAESOnly ++

  // Insert with CEP bootrom
  new WithCEPBootrom ++

  // Overide the chip info 
  new WithDTS("mit-ll,cep-arty100t", Nil) ++

  // Add GPIO (LEDs have been explicitly removed from the Arty100T test harness)
//  new WithArty100TGPIOBinder ++
//  new WithGPIOIOPassthrough ++
//  new WithArty100TGPIO ++

  // Include the Arty100T Tweaks with CEP Registers enabled (passed to the bootrom build)
  new WithArty100TTweaks ++

  // Remove the L2 cache
  new chipyard.config.WithBroadcastManager ++ // no l2

  new chipyard.RocketConfig)

class RocketArty100TConfig extends Config(
  new WithArty100TTweaks ++
  new chipyard.config.WithBroadcastManager ++ // no l2
  new chipyard.RocketConfig)

class UART230400RocketArty100TConfig extends Config(
  new WithArty100TUARTTSI(uartBaudRate = 230400) ++
  new RocketArty100TConfig)

class UART460800RocketArty100TConfig extends Config(
  new WithArty100TUARTTSI(uartBaudRate = 460800) ++
  new RocketArty100TConfig)

class UART921600RocketArty100TConfig extends Config(
  new WithArty100TUARTTSI(uartBaudRate = 921600) ++
  new RocketArty100TConfig)

class NoCoresArty100TConfig extends Config(
  new WithArty100TTweaks ++
  new chipyard.config.WithMemoryBusFrequency(50.0) ++
  new chipyard.config.WithPeripheryBusFrequency(50.0) ++  // Match the sbus and pbus frequency
  new chipyard.config.WithBroadcastManager ++ // no l2
  new chipyard.NoCoresConfig)

