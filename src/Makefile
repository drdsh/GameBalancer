##############################################
#Source Makefile Game Balancer               #
#                                            #
#Since this is essentially a single tool,    #
#it is compiled in a very monolith way       #
#without shared libraries                    #
##############################################

include ../Makefile

MODULES  := $(wildcard */)
OBJECTS  := $(patsubst %.cpp,%.o,$(wildcard */*.cpp))
CXXFLAGS += $(addprefix -fprebuilt-module-path=${ROOT}/src, ${MODULES})

../bin/GameBalancer ${OBJECTS} GameBalancer.cpp
	mkdir ..
	${CXX} -o ../bin/GameBalancer ${OBJECTS} GameBalancer.cpp

#Override all target included in ../Makefile
all: ${OBJECTS} ../bin/GameBalancer
