#include <iostream>
#include <list>

template<class Ind>
Ind findNextPrime(std::list<Ind>& primes, Ind maxPrime);

/** return the minimal prime factor of a number */
template<class Ind>
Ind primeFactor(std::list<Ind>& primes, Ind n)
{
	for(auto iter = primes.begin(); iter != primes.end(); ++ iter)
	{
		if((n%(*iter))==0)
			return *iter;
	}
	Ind maxPrime = primes.back();
	while(maxPrime*maxPrime<n)
	{
		maxPrime = findNextPrime(primes,maxPrime);
		if((n%maxPrime)==0)
			return maxPrime;
	}
	return n;
}

template<class Ind>
Ind findNextPrime(std::list<Ind>& primes, Ind maxPrime)
{
	Ind i = primes.back()+1;
	while(true)
	{
		if (primeFactor(primes, i)==i)
		{
			primes.emplace_back(i);
			return i;
		}
		++i;
	}
}

constexpr int number = 10001;
int main(int argc, char* argv[])
{
	std::list<long> primes;
	primes.emplace_back(2);
	long maxp = 2;
	while(primes.size()<number)
	{
		maxp = findNextPrime(primes,maxp);
	}
	std::cout<<maxp<<std::endl;
}