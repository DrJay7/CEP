#//************************************************************************
#// Copyright 2021 Massachusetts Institute of Technology
#// SPDX short identifier: BSD-2-Clause
#//
#// File Name:      common.make
#// Program:        Common Evaluation Platform (CEP)
#// Description:    Top level common.make for CEP Cosimulation
#// Notes:          
#//
#//************************************************************************

# Avoid redundant inclusions of common.make
ifndef $(COMMON_MAKE_CALLED)
COMMON_MAKE_CALLED			= 1

# The following flags / variables can be overridden by lower level makefiles or the command line
QUESTASIM_PATH				?= /opt/questa-2019.1/questasim/bin
MODELSIM        			?= 1
CADENCE 					?= 0
NOWAVE          			?= 0
PROFILE         			?= 0
COVERAGE        			?= 0
USE_GDB       				?= 0
TL_CAPTURE      			?= 0

$(info )
$(info CEP_COSIM: ----------------------------------------------------------------------)
$(info CEP_COSIM:        Common Evaluation Platform Co-Simulation Environment           )
$(info CEP_COSIM: ----------------------------------------------------------------------)

# RISCV *must* be defined
ifndef RISCV
$(error CEP_COSIM: RISCV is unset. You must set RISCV yourself, or through the Chipyard auto-generated env file)
endif

# Currently only MODELSIM (Questasim) and CADENCE (XCellium) are supported
# The following check ensures one and only one is set
ifeq (${MODELSIM},1)
CADENCE        				= 0
else ifeq (${CADENCE},1)
MODELSIM       				= 0
else
$(error "CEP_COSIM: Only MODELSIM (QuestaSim) and CADENCE (XCellium) are currently supported")
endif

# Perform DUT_SIM_MODE Check
ifeq "$(findstring BFM,${DUT_SIM_MODE})" "BFM"
DUT_SIM_MODE = BFM_MODE
else ifeq "$(findstring BARE,${DUT_SIM_MODE})" "BARE"
DUT_SIM_MODE = BARE_MODE
else
$(error CEP_COSIM: ${DUT_SIM_MODE} is invalid)
endif

# Validate the Chipyard verilog has been build by looking for the generated makefile
ifeq (,$(wildcard $(COSIM_TOP_DIR)/CHIPYARD_BUILD_INFO.make))
$(error "CEP_COSIM: CHIPYARD_BUILD_INFO.make does not exist. run make -f Makefile.chipyard in $(COSIM_TOP_DIR)")
endif

# Include the file that contains info about the chipyard build
include $(COSIM_TOP_DIR)/CHIPYARD_BUILD_INFO.make

# The following DEFINES control how the software is
# compiled and if will be overriden by lower level
# Makefiles as needed.

# Enables virtual memory support when operating in BARE mode
ENABLE_VIRTUAL  			= 0

# Set some default flag values
ENABLE_VIRTUAL				= 0
USE_DPI         			= 1
RANDOMIZE     				= 1
UPDATE_INFO   				= 1
TEST_INFO     				= testHistory.txt

# Misc. variable definitions
WORK_DIR        			:= ${TEST_SUITE_DIR}/${TEST_SUITE_NAME}_work
COSIM_COVERAGE_PATH			:= ${TEST_SUITE_DIR}/coverage

# Additional Co-Simulation Paths
SHARE_DIR					:= ${COSIM_TOP_DIR}/share
PLI_DIR						:= ${COSIM_TOP_DIR}/pli
SIMDIAG_DIR					:= ${COSIM_TOP_DIR}/simDiag
DVT_DIR         			:= ${COSIM_TOP_DIR}/dvt
BHV_DIR         			:= ${DVT_DIR}/behav_models
LIB_DIR						:= ${COSIM_TOP_DIR}/lib

# can be override by other Makefile
XX_LIB_DIR					:= ${LIB_DIR}
V2C_TAB_FILE				:= ${PLI_DIR}/v2c.tab
BUILD_HW_MAKEFILE			:= ${COSIM_TOP_DIR}/cep_buildHW.make
BUILD_SW_MAKEFILE			:= ${COSIM_TOP_DIR}/cep_buildSW.make
CADENCE_MAKE_FILE 			:= ${COSIM_TOP_DIR}/cadence.make
VPP_LIB 					:= ${XX_LIB_DIR}/libvpp.so
VPP_SV_LIB 					:= ${XX_LIB_DIR}/libvpp
RISCV_LIB 					:= ${XX_LIB_DIR}/riscv_lib.a
BIN_DIR 					:= ${COSIM_TOP_DIR}/bin
RISCV_TEST_DIR 				:= ${REPO_TOP_DIR}/software/riscv-tests
ISA_TEST_TEMPLATE 			:= ${TEST_SUITE_DIR}/testTemplate

# Pointers to various binaries
GCC     					= /usr/bin/g++
AR 							= /usr/bin/ar
RANLIB  					= /usr/bin/ranlib
LD 							= ${GCC}
VPP_CMD						= ${BIN_DIR}/vpp.pl
V2C_CMD						= ${BIN_DIR}/v2c.pl

#--------------------------------------------------------------------------------------
# Questasim only related items
#--------------------------------------------------------------------------------------
ifeq (${MODELSIM},1)
VLOG_CMD					= ${QUESTASIM_PATH}/vlog
VCOM_CMD					= ${QUESTASIM_PATH}/vcom
VOPT_CMD					= ${QUESTASIM_PATH}/vopt
VSIM_CMD 					= ${QUESTASIM_PATH}/vsim
VLIB_CMD					= ${QUESTASIM_PATH}/vlib
VMAP_CMD					= ${QUESTASIM_PATH}/vmap
VMAKE_CMD					= ${QUESTASIM_PATH}/vmake
VCOVER_CMD					= ${QUESTASIM_PATH}/vcover
VSIM_DO_FILE				= ${TEST_DIR}/vsim.do

# Quick sanity check if vsim exists
ifeq (,$(shell which ${VSIM_CMD}))
$(error CEP_COSIM: vsim not found.  Check QUESTASIM_PATH)
endif

# Provide some status of the user contronable parameters
$(info )
$(info CEP_COSIM: Running with the following variables:)
$(info CEP_COSIM:   RISCV          = $(RISCV))
$(info CEP_COSIM:   MODELSIM       = $(MODELSIM))
$(info CEP_COSIM:   CADENCE        = $(CADENCE))
$(info CEP_COSIM:   DUT_SIM_MODE   = ${DUT_SIM_MODE})
$(info CEP_COSIM:   NOWAVE         = ${NOWAVE})
$(info CEP_COSIM:   PROFILE        = ${PROFILE})
$(info CEP_COSIM:   COVERAGE       = ${COVERAGE})
$(info CEP_COSIM:   USE_GDB        = ${USE_GDB})
$(info CEP_COSIM:   TL_CAPTURE     = ${TL_CAPTURE})
$(info CEP_COSIM:   ENABLE_VIRTUAL = ${ENABLE_VIRTUAL})
$(info )

# Create default local vsim do file if not there: one with sim for interactive and one for regression
define VSIM_DO_BODY
set NumericStdNoWarnings 1
set StdArithNoWarnings 1
#
# Procedure to turn on/off wave and continue
# they are called from inside Verilog
#
proc wave_on {} {
     echo "Enable logging";	
     log -ports -r /* ;
}

proc wave_off {} {
     echo "Stop logging"	
     nolog -all;
}
proc dump_coverage {} {
     echo "Dumping Coverage";
     coverage save ../coverage/${TEST_NAME}.ucdb
}
#
# just run
#
run -all;
#
# should never get here anyway!!
#
quit
endef

export VSIM_DO_BODY

${VSIM_DO_FILE}:
	@if test ! -f $@; then	\
	echo "$$VSIM_DO_BODY" > $@; \
	fi

endif
#--------------------------------------------------------------------------------------



#--------------------------------------------------------------------------------------
# To detect if any important flag has changed since last run
#--------------------------------------------------------------------------------------
PERSUITE_CHECK = ${TEST_SUITE_DIR}/.PERSUITE_${DUT_SIM_MODE}_${NOWAVE}_${PROFILE}_${COVERAGE}_${USE_DPI}

${PERSUITE_CHECK}: .force
	if test ! -f ${PERSUITE_CHECK}; then rm -f ${TEST_SUITE_DIR}/.PERSUITE_*; touch ${PERSUITE_CHECK}; fi
#--------------------------------------------------------------------------------------



#--------------------------------------------------------------------------------------
# Include additional makefiles as needed
#--------------------------------------------------------------------------------------
# Include both the Hardware and Software makefiles
include ${BUILD_HW_MAKEFILE}
#include ${BUILD_SW_MAKE_FILE}

# Include the Cadence toolset specific file, if enabled
ifeq (${CADENCE},1)
include ${CADENCE_MAKE_FILE}
endif
#--------------------------------------------------------------------------------------


#--------------------------------------------------------------------------------------
# Variable and Build target tasked with running the simulation
#--------------------------------------------------------------------------------------

# Establish the MODELSIM command line for running simulation (which will be override when operating in CADENCE mode)
VSIM_CMD_LINE = "${VSIM_CMD} -work ${WORK_DIR} -t 100ps -tab ${V2C_TAB_FILE} -pli ${VPP_LIB} -sv_lib ${VPP_SV_LIB} -do ${VSIM_DO_FILE} ${COSIM_VSIM_ARGS} ${WORK_DIR}.${CHIPYARD_TOP_MODULE_OPT} -batch -logfile ${TEST_DIR}/${TEST_DIR_NAME}.log +myplus=0"

.vrun_flag: ${TEST_SUITE_DIR}/_info ${XX_LIB_DIR}/.buildLibs ${VSIM_DO_FILE} c_dispatch ${RISCV_WRAPPER_ELF}
ifeq (${COVERAGE},1)
	@if test ! -d ${COSIM_COVERAGE_PATH}; then	\
		mkdir  ${COSIM_COVERAGE_PATH};		\
	fi
endif
	${VPP_CMD} ${TEST_DIR}/c_dispatch ${RANDOMIZE} ${UPDATE_INFO} ${TEST_INFO} ${USE_GDB} ${TEST_DIR}/${TEST_NAME}.log ${COVERAGE} \"${VSIM_CMD_LINE}\"
#--------------------------------------------------------------------------------------


# ISA Auto test generation
makeTest: ${TEST_SUITE_DIR}/${TEST_NAME}${SFX}/${TEST_NAME}${SFX}.dump
	@echo "Done"

# override at command line ONLY!!!
SINGLE_THREAD=0
VIRTUAL_MODE=0
PASS_IS_TO_HOST=0;

${TEST_SUITE_DIR}/${TEST_NAME}${SFX}/${TEST_NAME}${SFX}.dump : ${RISCV_TEST_DIR}/isa/${TEST_NAME}
	@if test ! -d ${TEST_SUITE_DIR}/${TEST_NAME}${SFX}; then	\
		mkdir  ${TEST_SUITE_DIR}/${TEST_NAME}${SFX}; \
	fi
	@cp -f ${ISA_TEST_TEMPLATE}/Makefile        ${TEST_SUITE_DIR}/${TEST_NAME}${SFX}/.
	@cp -f ${ISA_TEST_TEMPLATE}/*.h             ${TEST_SUITE_DIR}/${TEST_NAME}${SFX}/.
	@cp -f ${ISA_TEST_TEMPLATE}/c_module.cc     ${TEST_SUITE_DIR}/${TEST_NAME}${SFX}/.
	@rm -f ${TEST_SUITE_DIR}/${TEST_NAME}${SFX}/c_dispatch.cc
ifeq (${SINGLE_THREAD},1)
	@echo "#define SINGLE_THREAD_ONLY" >> ${TEST_SUITE_DIR}/${TEST_NAME}${SFX}/c_dispatch.cc
endif
ifneq (${SINGLE_CORE_ONLY},)
	@echo "#define SINGLE_CORE_ONLY ${SINGLE_CORE_ONLY}" >> ${TEST_SUITE_DIR}/${TEST_NAME}${SFX}/c_dispatch.cc
endif
ifeq (${VIRTUAL_MODE},1)
	@echo "#define MAX_TIMEOUT 200"    >> ${TEST_SUITE_DIR}/${TEST_NAME}${SFX}/c_dispatch.cc
	@echo "#define VIRTUAL_MODE"       >> ${TEST_SUITE_DIR}/${TEST_NAME}${SFX}/c_dispatch.cc
else
	@echo "#define MAX_TIMEOUT 200"    >> ${TEST_SUITE_DIR}/${TEST_NAME}${SFX}/c_dispatch.cc
endif
ifeq (${PASS_IS_TO_HOST},1)
	@echo "#define PASS_IS_TO_HOST"    >> ${TEST_SUITE_DIR}/${TEST_NAME}${SFX}/c_dispatch.cc
endif
	@cat ${ISA_TEST_TEMPLATE}/c_dispatch.cc >>        ${TEST_SUITE_DIR}/${TEST_NAME}${SFX}/c_dispatch.cc
	@cp -f ${RISCV_TEST_DIR}/isa/${TEST_NAME}      ${TEST_SUITE_DIR}/${TEST_NAME}${SFX}/riscv_wrapper.elf
	@cp -f ${RISCV_TEST_DIR}/isa/${TEST_NAME}.dump ${TEST_SUITE_DIR}/${TEST_NAME}${SFX}/${TEST_NAME}${SFX}.dump
	@${BIN_DIR}/createPassFail.pl ${RISCV_TEST_DIR}/isa/${TEST_NAME}.dump ${TEST_SUITE_DIR}/${TEST_NAME}${SFX}/PassFail.hex



#--------------------------------------------------------------------------------------
# Moselsim coverage related build targets
#--------------------------------------------------------------------------------------
merge::
ifeq (${MODELSIM},1)
	@if test -d ${COSIM_COVERAGE_PATH}; then	\
		(cd ${COSIM_COVERAGE_PATH}; ${VCOVER_CMD} merge -out ${TEST_SUITE}.ucdb ${COSIM_COVERAGE_PATH}/*.ucdb;) \
	fi
endif

# use "coverage open <file>.ucdb" under vsim to open and view
MODELSIM_TOP_COVERAGE  = ${COSIM_TOP_DIR}/coverage
MODELSIM_COV_DO_SCRIPT = ${COSIM_TOP_DIR}/modelsim_coverage.do

mergeAll:: .force
ifeq (${MODELSIM},1)
	@if test ! -d ${MODELSIM_TOP_COVERAGE}; then	\
	   mkdir  ${MODELSIM_TOP_COVERAGE};		\
	fi
	@rm -rf ${MODELSIM_TOP_COVERAGE}/*
	@for i in ${TEST_GROUP}; do	\
	   (cd $${i}; make merge; cp coverage/$${i}.ucdb ${MODELSIM_TOP_COVERAGE}/.);	\
	done
	@(cd ${MODELSIM_TOP_COVERAGE};  ${VSIM_CMD} -64 -do ${MODELSIM_COV_DO_SCRIPT})
endif
#--------------------------------------------------------------------------------------



#--------------------------------------------------------------------------------------
# Misc build targets
#--------------------------------------------------------------------------------------
clean: cleanAll

cleanAll:
	-rm -f ${CHIPYARD_TOP_FILE_bfm}
	-rm -f ${CHIPYARD_TOP_FILE_bare}
	-rm -f ${COSIM_TOP_DIR}/testSuites/*/.cosim_build_list
	-rm -f ${COSIM_TOP_DIR}/testSuites/*/*/vsim.do
	-rm -rf ${COSIM_TOP_DIR}/testSuites/*/*_work
	-rm -f ${COSIM_TOP_DIR}testSuites/.PERSUITE*

	-rm -rf ${COSIM_TOP_DIR}/*/*.o* ${COSIM_TOP_DIR}/*/*/*.bo* ${COSIM_TOP_DIR}/*/*/*.o*
	-rm -rf ${COSIM_TOP_DIR}/*/*/status
	-rm -rf ${COSIM_TOP_DIR}/bareMetalTests/*/*.elf ${COSIM_TOP_DIR}/bareMetalTests/*/*.dump
	-rm -rf ${COSIM_TOP_DIR}/*/.build*
	-rm -rf ${LIB_DIR}/*/*.o* ${LIB_DIR}/*.a ${LIB_DIR}/*.so
	-rm -rf ${COSIM_TOP_DIR}/*/*/C2V*
	-rm -rf ${COSIM_TOP_DIR}/*/xcelium.d ${COSIM_TOP_DIR}/*/.cadenceBuild ${COSIM_TOP_DIR}/*/*/cov_work ${COSIM_TOP_DIR}/*/*/xrun.log
	-rm -rf ${COSIM_TOP_DIR}/*/cad_coverage
	-rm -rf ${COSIM_TOP_DIR}/*/coverage

# Use to force rebuilds for rules that include this dependency
.force:
#--------------------------------------------------------------------------------------



#--------------------------------------------------------------------------------------
# Usage Summary
#--------------------------------------------------------------------------------------
define MAKE_USAGE_HELP_BODY
Usage summary:
make [NOWAVE=0|1] [COVERAGE=0|1] [PROFILE=0|1] [USE_GDB=0|1] <all|summary|cleanAll|merge|usage>

Options:
  NOWAVE=1      : turn off wave capturing. Default is ON for interactive. OFF for regression
  USE_GDB=1     : run the test under "gdb" debugger. Default is OFF. Should only be used for interactive session.
  COVERAGE=1    : run the test with coverage capture enable. Default is OFF
  PROFILE=1     : run the test with profiling turn on. Default is OFF
  TL_CAPTURE=1  : turn on Title-Link comand sequence capturing to be used for BARE Metal (and Unit-level testbench)
  
Targets:
  all        : run the test. Default target (empty string = same as "all")
  summary    : print out regression summary (run at the top or suite directories.
  cleanAll   : clean up and force a rebuild of every thing
  merge      : merge coverage reports
  usage      : print this help lines

  see <common.make> for more options and targets

endef

export MAKE_USAGE_HELP_BODY

usage:
	@echo "$$MAKE_USAGE_HELP_BODY"
#--------------------------------------------------------------------------------------

# ifdef $(COMMON_MAKE_CALLED)
endif 
