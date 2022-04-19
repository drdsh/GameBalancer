# SPDX-FileCopyrightText: 2022 Daniel S. Haag
#
# SPDX-License-Identifier: MIT

#############################################
#Source Makefile Game Balancer
#Since this is essentially a single tool it is compiled in a very monolith
#way without shared libraries
##############################################

CXX       := g++
CXXFLAGS  := -std=c++20 -march=native -O3 -fmodules-ts -fconcepts-diagnostics-depth=2
MODULES   := $(sort $(dir $(wildcard *)))
OBJECTS   := $(patsubst %.cpp,%.o,$(wildcard */*.cpp))

#Dependencies
CXXFLAGS  += -I /usr/include/eigen3

# FYI: As of now, module partitions are not yet possible. Therefore, the
# directories here contain multiple modules that are only coupled by using the
# same namespace

# Program binary
../bin/GameBalancer: ${OBJECTS} GameBalancer.cpp
	mkdir -p ../bin
	echo ${OBJECTS}
	${CXX} ${CXXFLAGS} -o ../bin/GameBalancer ${OBJECTS} GameBalancer.cpp

.phony: all clean
all: ../bin/GameBalancer

clean:
	rm -f */*.o
	rm -rf gcm.cache


# Explicit dependencies
GameBasics/GameBasics.o: GameBasics/Concepts.o GameBasics/Game.o
GameBasics/Game.o: GameBasics/Concepts.o
