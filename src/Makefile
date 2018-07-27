inc = -I. -I../external/catch/include
lib = -L.

CXX=g++
CXXFLAGS=-g -std=c++17 -Wall -pedantic -m64
LD_FLAGS = $(lib)

CPP_APP_FILES := $(wildcard applications/*.cpp)
OBJ_APP_FILES := $(addprefix ../obj/,$(notdir $(CPP_APP_FILES:.cpp=.o)))

CPP_DATASTRUCTURES_FILES := $(wildcard data_structures/*.cpp)
OBJ_DATASTRUCTURES_FILES := $(addprefix ../obj/,$(notdir $(CPP_DATASTRUCTURES_FILES:.cpp=.o)))

CPP_ALGORITHMS_FILES := $(wildcard Algorithms/*.cpp)
OBJ_ALGORITHMS_FILES := $(addprefix ../obj/,$(notdir $(CPP_ALGORITHMS_FILES:.cpp=.o)))

CPP_UNIT_TEST_FILES := $(wildcard unit_tests/*.cpp)
OBJ_UNIT_TEST_FILES := $(addprefix ../obj/,$(notdir $(CPP_UNIT_TEST_FILES:.cpp=.o)))

all: create_test_dir ../bin/test/unit_tests

create_test_dir:
	mkdir -p ../bin/test

debug_tests:
	@ for x in ../bin/test/*; do ./$$x -b --durations yes --use-colour yes; done

run_tests:
	@ for x in ../bin/test/*; do ./$$x --durations yes --use-colour yes; done

../obj/%.o: */%.cpp
	$(CXX) $(CXXFLAGS) $(inc) -c -o $@ $<

../bin/test/unit_tests: $(OBJ_UNIT_TEST_FILES) $(OBJ_ALGORITHMS_FILES) $(OBJ_DATASTRUCTURES_FILES) $(OBJ_APP_FILES)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LD_FLAGS)

clean:
	rm -rf ../obj/* ; rm -rf ../bin/*
