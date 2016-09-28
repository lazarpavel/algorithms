inc = -I. -I../external/catch/include
lib = -L.

CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -pedantic -m64
LD_FLAGS = $(lib)

CPP_ALGORITHMS_FILES := $(wildcard Algorithms/*.cpp)
OBJ_ALGORITHMS_FILES := $(addprefix ../obj/,$(notdir $(CPP_ALGORITHMS_FILES:.cpp=.o)))

CPP_ALGORITHMS_TEST_FILES := $(wildcard AlgorithmsTest/*.cpp)
OBJ_ALGORITHMS_TEST_FILES := $(addprefix ../obj/,$(notdir $(CPP_ALGORITHMS_TEST_FILES:.cpp=.o)))

all: create_test_dir ../bin/test/AlgorithmsTest

create_test_dir:
	mkdir -p ../bin/test

debug_tests:
	@ for x in ../bin/test/*; do ./$$x -b --durations yes --use-colour yes; done

run_tests:
	@ for x in ../bin/test/*; do ./$$x --durations yes --use-colour yes; done

../obj/%.o: */%.cpp
	$(CXX) $(CXXFLAGS) $(inc) -c -o $@ $<

../bin/test/AlgorithmsTest: $(OBJ_ALGORITHMS_TEST_FILES) $(OBJ_ALGORITHMS_FILES)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LD_FLAGS)

clean:
	rm -rf ../obj/* ; rm -rf ../bin/*
