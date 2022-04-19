# SPDX-FileCopyrightText: 2022 Daniel S. Haag
#
# SPDX-License-Identifier: MIT

##############################################
#Project Makefile Game Balancer              #
##############################################

#Get project directory
ROOT:=$(realpath $(dir $(firstword $(MAKEFILE_LIST))))

.phony: all clean

all:
	make -C src all

clean:
	rm -rf bin
	make -C src clean
