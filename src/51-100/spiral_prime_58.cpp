#include "prime.h"
#include <iostream>
#include <climits>

constexpr long limit = 1e9;


int main(int argc, char *argv[])
{
	std::cout<<LONG_MAX<<std::endl;
	auto primes = primeList(limit);
	long side = 3;
	long f = 3;
	long ps = 0;
	long n =1;
	double ratio;
	while (true)
	{
		if(f>(*primes.rbegin()))
		{
			std::cout<<"out of range "<<ratio<<std::endl;
			break;
		}
		if(primes.find(f)!=primes.end())
			ps += 1;
		f += (side-1);
		if(primes.find(f)!=primes.end())
			ps += 1;
		f += (side-1);
		if(primes.find(f)!=primes.end())
			ps += 1;
		f += (side-1);
		if(primes.find(f)!=primes.end())
			ps += 1;
		n += 4;
		ratio = static_cast<double>(ps)/n;
		if(ratio<0.1)
		{
			std::cout<<side<<std::endl;
			break;
		}
		side += 2;
		f += (side-1);
	}
}