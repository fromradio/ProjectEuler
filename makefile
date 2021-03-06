
CXX = g++

CXXFLAGS = -g -Wall -O3 -std=c++14

DIR_INC = 

DIR_LIB = 

LIB = 

DIR_OBJ = ./obj 

DIR_BIN = ./bin

src50 = src/1-50

src100 = src/51-100

src150 = src/101-150

# 1
multipliers: bin/multipliers
bin/multipliers: obj/multipliers.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/multipliers.o: $(src50)/multipliers_three_and_five.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 2
evenfib: bin/evenfib
bin/evenfib: obj/evenfib.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/evenfib.o: $(src50)/even_fibonacci.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 3
primefac: bin/primefac
bin/primefac: obj/primefac.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/primefac.o: $(src50)/prime_factor.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 4
palin: bin/palin
bin/palin: obj/palin.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/palin.o: $(src50)/largest_palindrome.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 5
multiple: bin/multiple
bin/multiple: obj/multiple.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/multiple.o: $(src50)/smallest_multiple.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 6
sumdiff: bin/sumdiff
bin/sumdiff: obj/sumdiff.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/sumdiff.o: $(src50)/sum_square_difference.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 7
10001prime: bin/10001prime
bin/10001prime: obj/10001prime.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/10001prime.o: $(src50)/10001st_prime.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 8
lproduct: bin/lproduct
bin/lproduct: obj/lproduct.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/lproduct.o: $(src50)/largest_product.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 10
sumprime: bin/sumprime
bin/sumprime: obj/sumprime.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/sumprime.o: $(src50)/sum_of_prime.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

#12
tri: bin/tri
bin/tri: obj/tri.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/tri.o: $(src50)/triangle_number.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

#13
largesum: bin/largesum
bin/largesum: obj/largesum.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/largesum.o: $(src50)/large_sum.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

#14
lcollatz: bin/lcollatz
bin/lcollatz: obj/lcollatz.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/lcollatz.o: $(src50)/longest_collatz.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

#14
lattice: bin/lattice
bin/lattice: obj/lattice.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/lattice.o: $(src50)/lattice_path.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

#16
pdigit: bin/pdigit
bin/pdigit: obj/pdigit.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/pdigit.o: $(src50)/power_digit.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 67
pathsum: bin/pathsum
bin/pathsum: obj/pathsum.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/pathsum.o: $(src50)/path_sum.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 25
fabnum: bin/fabnum
bin/fabnum: obj/fabnum.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/fabnum.o: $(src50)/fab_number.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 31
coinsum: bin/coinsum
bin/coinsum: obj/coinsum.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/coinsum.o: $(src50)/coin_sum.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 27
quadprime: bin/quadprime
bin/quadprime: obj/quadprime.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/quadprime.o: $(src50)/quadratic_prime.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 37
truncprime: bin/truncprime
bin/truncprime: obj/truncprime.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/truncprime.o: $(src50)/trunc_prime.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 39
inttri: bin/inttri
bin/inttri: obj/inttri.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/inttri.o: $(src50)/inter_triangle.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 34
digitfac: bin/digitfac
bin/digitfac: obj/digitfac.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/digitfac.o: $(src50)/digit_factorials.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 36
doublepali: bin/doublepali
bin/doublepali: obj/doublepali.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/doublepali.o: $(src50)/double_palindrome_36.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 45
tph: bin/tph
bin/tph: obj/tph.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/tph.o: $(src50)/tri_pen_hex.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 47
disfac: bin/disfac
bin/disfac: obj/disfac.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/disfac.o: $(src50)/dis_prime_factor.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 43
subdiv: bin/subdiv
bin/subdiv: obj/subdiv.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/subdiv.o: $(src50)/sub_string_div.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 50
consprime: bin/consprime
bin/consprime: obj/consprime.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/consprime.o: $(src50)/cons_prime_sum.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 57
sqrtcon: bin/sqrtcon
bin/sqrtcon: obj/sqrtcon.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/sqrtcon.o: $(src100)/square_root_convergent.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 57
spprime: bin/spprime
bin/spprime: obj/spprime.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/spprime.o: $(src100)/spiral_prime_58.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 60
primepair: bin/primepair
bin/primepair: obj/primepair.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/primepair.o: $(src100)/prime_pair.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 72
frac: bin/frac
bin/frac: obj/frac.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/frac.o: $(src100)/fraction_72.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 75
singtri: bin/singtri
bin/singtri: obj/singtri.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/singtri.o: $(src100)/sing_int_tri.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 75
pathsum2: bin/pathsum2
bin/pathsum2: obj/pathsum2.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/pathsum2.o: $(src100)/path_sum.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 77
primesum: bin/primesum
bin/primesum: obj/primesum.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/primesum.o: $(src100)/prime_sum.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 94
aleqtri: bin/aleqtri
bin/aleqtri: obj/aleqtri.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/aleqtri.o: $(src100)/almost_eq_tri.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 95
amichain: bin/amichain
bin/amichain: obj/amichain.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/amichain.o: $(src100)/ami_chains.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@

# 102
optpoly: bin/optpoly
bin/optpoly: obj/optpoly.o
	$(CXX) $< $(DIR_LIB) -o $@ $(LIB)
obj/optpoly.o: $(src150)/opt_poly.cpp
	$(CXX) $(CXXFLAGS) $(DIR_INC) -c $< -o $@