[//]: # (Copyright 2022 Massachusetts Institute of Technology)
[//]: # (SPDX short identifier: BSD-2-Clause)

# Common Evaluation Platform v4.0

[![DOI](https://zenodo.org/badge/108179132.svg)](https://zenodo.org/badge/latestdoi/108179132)
[![License](https://img.shields.io/badge/License-BSD%202--Clause-orange.svg)](https://opensource.org/licenses/BSD-2-Clause)

<p align="center">
    <img src="./cep_docs/cep_logo.jpg" width="375" height="159">
</p>
<p align="center">
    <img src="./cep_docs/version4.0.jpg" width="146" height="82">
</p>
<p align="center">
   Copyright 2022 Massachusetts Institute of Technology
</p>

The Common Evaluation Platform (CEP) is an SoC design that contains only license-unencumbered, freely available components.  The CEP includes a range of accelerator cores coupled with a key delivery mechanism, and parametrically-defined challenge modules which can be synthesized to support developmental testing. The implementation of the CEP includes a comprehensive verification environment to ensure modifications do not impede intended functionality. It is intended to be targeted to either an FPGA or ASIC implementation. 

Beginning with CEP v4.0, the platform has been ported to the UCB Chipyard Framework.  The original Chipyard Readme can be found [here](./README.Chipyard.md).

## Pre-requisites (validated test/build configurations):
The following items describe the configuration of the system that CEP has been developed and tested on:
* Ubuntu 18.04 LTS x86_64 with Modelsim Questa Sim-64 v2019.1 (for co-simulation)
* Red Hat Enterprise Linux 7 with Cadence XCELIUMAGILE20.09.001, VMANAGERAGILE20.06.001
* Xilinx Vivado 2020.1 (needed for building FPGA targets)
  - Plus Digilent Adept Drivers for programming the FPGA target, https://reference.digilentinc.com/reference/software/adept/start?redirect=1#software_downloads)
* Terminal emulator (such as `minicom`)
* bash

Other configurations may work, but they have not been explicitly verified.

## Setting up your environment

To build the CEP, several packages and toolsets must be installed and built.  The typical steps are listed below.  Additional information can be found in the Chipyard Documentation at https://chipyard.readthedocs.io/

A note about proxies: If your system is behind a proxy, you'll want to ensure your environment is properly configured.  Exact details vary by system, but the proxy needs to be available to apt / yum, curl, and sbt (Simple Build Tool for Scala)

* Install git if not already present on your system
  * Ubuntu - `sudo apt install git`
  * RHEL7  - `sudo yum install git`
* Clone the CEP repository, change to the directory of the clone
  * `git clone https://github.com/mit-ll/CEP.git`
* Install package dependencies.  Copies of these files can also be found in the Chipyard Documentation listed above
  * Ubuntu - `./scripts/ubuntu-reqs.sh`
  * RHEL7  - `./scripts/centos-reqs.sh`
* Initialize all the git submodules (including FPGA-related submodules)
  * `./scripts/init-submodules-no-riscv-tools.sh`
  * `./scripts/init-fpga.sh`
* Build the RISC-V Toolchain.  
  * Depending on your available hardware, you can expedite the build by executing `export MAKEFLAGS=-jN` prior to running the build script.  N is the number of cores you can devote to the build
  * `./scripts/build-toolchains.sh riscv-tools`
* It is advisable to move the compiled toolchain outside of the current repo if you plan to have multiple CEP working directories.  Complete directions are beyond the scope of this document, but they do
  include moving the `riscv-tools-install` directory and `env-riscv-tools.sh` file.  Modification of the aforementioned file as well as `env.sh` will required for smooth operation

## Repository Directory Structure
Providing a complete directory structure is impractical, but some items are highlighted here.

```
<CEP_ROOT> 
  |- ./sims/cep_cosim/ -  
  |     Defines the CEP co-simulation evironment for performing "chip" level simulations of the CEP in 
  |     either bare metal or bus functional model (BFM) mode.  
  |- ./generators/mitll-blocks/
  |   |- src/main/scala - Contains all the custom CEP Chisel code
  |   |- src/main/resources/vsrc/ - SystemVerilog / Verilog associated with the CEP build
  |   |   |- generated_dsp_code - Location to place the `dft_top.v` and `idft_top.v'
  |   |   |- opentitan  - Soft-link to the opentitan submodule located at ./opentitan
  |   |   |- aeees      - Challenge module.  Read the README.md in this directory for more information.
  |   |   |- auto-fir   - Challenge module.  Read the README.md in this directory for more information.
  |   |   |- shaaa      - Challenge module.  Read the README.md in this directory for more information.
```

### Cosim notes
### Generated DSP code notes

<p align="center">
   <img src="./cep_docs/cep_v4.0_architecture.jpg" width="1114" height="450">
</p>
<p align="center">
    <img src="./cep_docs/related_logos.jpg" width="442" height="120">
</p>


### Please check the [Release Notes](./RELEASE_NOTES.md) to understand what has changed and a list of known issues.

## Licensing

As the CEP has been developed with input from many sources, multiple licenses apply.  Please refer to the following files for licensing info. 
* [CEP License](./LICENSE.md)
* [CEP Components Licenses](./LICENSE.md)
* [Chipyard License](./LICENSE.md)
* [SiFive License](./LICENSE.SiFive.md)

## DISTRIBUTION STATEMENT A. Approved for public release: distribution unlimited.

© 2022 MASSACHUSETTS INSTITUTE OF TECHNOLOGY

Subject to FAR 52.227-11 – Patent Rights – Ownership by the Contractor (May 2014)
SPDX-License-Identifier: BSD-2-Clause

This material is based upon work supported by the Name of Sponsor under Air Force Contract No. FA8721-05-C-0002 and/or FA8702-15-D-0001. Any opinions, findings, conclusions or recommendations expressed in this material are those of the author(s) and do not necessarily reflect the views of the Name of Sponsor.

The software/firmware is provided to you on an As-Is basis