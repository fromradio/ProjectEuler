#include<iostream>
#include<list>

#include<cmath>
constexpr long number = 600851475143;

int count = 0;
// the minimal factor has to be prime
template<class Ind>
Ind minimalFactor(Ind n)
{
	Ind b = static_cast<Ind>(std::sqrt(n));
	for ( Ind i = 2 ; i <= b; ++ i)
	{
		++ count;
		if((n%i)==0)
			return i;
	}
	return n;
}

// 
template<class Ind>
void factorDecomposition(Ind n, std::list<Ind>& facs)
{
	Ind fac = minimalFactor(n);
	facs.emplace_back(fac);
	if(fac==n)
		return;
	else
		factorDecomposition(n/fac,facs);
}

template<class Ind>
Ind maxFactor(Ind n)
{
	std::list<Ind> facs;
	factorDecomposition(n,facs);
	return *std::max_element(facs.begin(),facs.end());
}


template<class Ind>
Ind findNextPrime(std::list<Ind>& primes, Ind maxPrime);

/** return the minimal prime factor of a number */
template<class Ind>
Ind primeFactor(std::list<Ind>& primes, Ind n)
{
	for(auto iter = primes.begin(); iter != primes.end(); ++ iter)
	{
		count ++;
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

template<class Ind>
Ind maximalFactor(Ind n)
{
	std::list<Ind> primes;
	primes.emplace_back(2);
	Ind mf,resi;
	resi = n;
	do{
		mf = primeFactor(primes,resi);
		resi = resi/mf;
	} while(resi != 1);
	return mf;
}

int main(int argc, char* argv[])
{
	if(argc==1)
		std::cout<<maximalFactor(number)<<" with "<<count<<" operations"<<std::endl;
	else if(argc==2)
	{
		int num = atoi(argv[1]);
		std::cout<<maxFactor(num)<<" with "<<count<<" operations"<<std::endl;
	}
}