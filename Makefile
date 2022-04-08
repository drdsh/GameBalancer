# SPDX-FileCopyrightText: 2022 Daniel S. Haag
#
# SPDX-License-Identifier: MIT

##############################################
#Project Makefile Game Balancer              #
##############################################

#Get project directory
ROOT:=$(realpath $(dir $(firstword $(MAKEFILE_LIST))))

CXX      := clang++
CXXFLAGS := -std=c++20 -march=native -O3 -fmodules -Xclang -emit-module-interface
ifeq ($(DESTDIR),)
DESTDIR := $(ROOT)/build
endif

.phony: all install

all:
	make -C src all
