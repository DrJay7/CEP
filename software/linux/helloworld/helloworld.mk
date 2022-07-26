#************************************************************************
# Copyright 2022 Massachusets Institute of Technology
# SPDX short identifier: BSD-2-Clause
#
# File Name:      helloworld.mk
# Program:        Common Evaluation Platform (CEP)
# Description:    Buildroot makefile
# Notes:          
#************************************************************************

MAINPROGRAM					?= helloworld
PACKAGE    					= $(shell echo $(MAINPROGRAM) | tr '[:lower:]' '[:upper:]')

$(PACKAGE)_VERSION 			= 1.0.0
$(PACKAGE)_LICENSE 			= BSD-2-Clause
$(PACKAGE)_DEPENDENCIES 	= libgpiod lncurses
$(PACKAGE)_SITE 			= $(TOPDIR)/../../../../../../linux/$(MAINPROGRAM)
$(PACKAGE)_SITE_METHOD 		= local
$(PACKAGE)_INSTALL_STAGING 	= NO
$(PACKAGE)_INSTALL_TARGET 	= YES

$(eval $(cmake-package))
