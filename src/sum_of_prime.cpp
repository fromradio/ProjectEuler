#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <chrono>
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
	Ind i = primes.back()+2;
	while(true)
	{
		if (primeFactor(primes, i)==i)
		{
			primes.emplace_back(i);
			return i;
		}
		i += 2;
	}
}

/** a much better way */
int count = 0; // how many operations

long primeCondition(long num)
{
	std::vector<bool> cons(num+1,true);
	long sq = static_cast<long>(std::sqrt(num));
	for (long i = 2; i < sq ; ++i){
		for(long k = i*i; k <= num ; k+=i){
			++ count;
			cons[k] = false;
		}
	}
	long sum = 0;
	for (long i = 2; i <= num; ++i)
		if(cons[i]) sum+=i;
	return sum;
}

/** maybe a better way */
long primeConditionBetter(long num)
{
	std::vector<bool> cons(num+1,true);
	long p = 2;
	while(p*p<=num)
	{
		for(long k = p*p; k<= num; k+=p)
		{
			cons[k] = false;
		}
		for(long i = p+1; i < num; ++ i)
		{
			if(cons[i]){
				p = i;
				break;
			}
		}
	}
	long sum = 0;
	for (long i = 2; i <= num; ++i)
		if(cons[i]) sum+=i;
	return sum;
}

int main(int argc, char*argv[])
{
	std::chrono::time_point<std::chrono::high_resolution_clock> t1 = std::chrono::high_resolution_clock::now();
	std::cout<<primeConditionBetter(2e6)<<std::endl;
	std::chrono::time_point<std::chrono::high_resolution_clock> t2 = std::chrono::high_resolution_clock::now();
	std::cout<<count<<" operations"<<std::endl;
	std::cout<<std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()<<" ms"<<std::endl;
}