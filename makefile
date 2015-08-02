
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

palin: bin/palin
bin/palin: obj/palin.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/palin.o: src/largest_palindrome.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

multiple: bin/multiple
bin/multiple: obj/multiple.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/multiple.o: src/smallest_multiple.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

sumdiff: bin/sumdiff
bin/sumdiff: obj/sumdiff.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/sumdiff.o: src/sum_square_difference.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

10001prime: bin/10001prime
bin/10001prime: obj/10001prime.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/10001prime.o: src/10001st_prime.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

lproduct: bin/lproduct
bin/lproduct: obj/lproduct.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/lproduct.o: src/largest_product.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 10
sumprime: bin/sumprime
bin/sumprime: obj/sumprime.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/sumprime.o: src/sum_of_prime.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

#12
tri: bin/tri
bin/tri: obj/tri.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/tri.o: src/triangle_number.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

#13
largesum: bin/largesum
bin/largesum: obj/largesum.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/largesum.o: src/large_sum.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

#14
lcollatz: bin/lcollatz
bin/lcollatz: obj/lcollatz.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/lcollatz.o: src/longest_collatz.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

#16
pdigit: bin/pdigit
bin/pdigit: obj/pdigit.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/pdigit.o: src/power_digit.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@