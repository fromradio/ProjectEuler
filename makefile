
CXX = g++

CXXFLAGS = -g -Wall -O3 -std=c++14

DIR_INC = 

DIR_LIB = 

LIB = 

DIR_OBJ = ./obj 

DIR_BIN = ./bin

multipliers: bin/multipliers
bin/multipliers: obj/multipliers.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/multipliers.o: src/multipliers_three_and_five.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

evenfib: bin/evenfib
bin/evenfib: obj/evenfib.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/evenfib.o: src/even_fibonacci.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

primefac: bin/primefac
bin/primefac: obj/primefac.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/primefac.o: src/prime_factor.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@