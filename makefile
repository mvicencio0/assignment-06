# -----------------------------------------------------------------------------
# Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
# Released under the [MIT License] (http://opensource.org/licenses/MIT)
# -----------------------------------------------------------------------------

EXE := $(wildcard *.cpp)
EXE := $(EXE:%.cpp=%)

CXXFLAGS := -std=c++11
# CXXFLAGS += -pedantic
# CXXFLAGS += -Weverything

# -----------------------------------------------------------------------------
.PHONY: all clean

all: $(EXE)

clean:
	rm $(EXE)

