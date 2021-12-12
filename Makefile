##############################################
#Project Makefile Dragoncnn (speak Dragonsin)#
##############################################

#Get project directory
ROOT:=$(realpath $(dir $(firstword $(MAKEFILE_LIST))))

CXX := clang
CXXFLAGS:= -std=c++20 -march=native -O3

ifeq ($(DESTDIR),)
DESTDIR := $(ROOT)/build
endif

all:
	make -C src all

install:
	make -C src install

