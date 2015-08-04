#include "prime.h"
#include <cmath>
#include <iostream>


/** n**2 + a*n + b */
int primeNumber(int a, int b, const std::set<long>& primes)
{
	int i = 0;
	while (true)
	{
		long n = i*i+a*i+b;
		if((*primes.rbegin())<n)
			return -1;
		if(primes.find(n)==primes.end())
			break;
		++ i;
	}
	return i+1;
}

/** answer is -59231 */
int main(int argc, char *argv[])
{
	std::set<long> bchoices = primeList(1000);
	long c = 1e6;
	std::set<long> primeset = primeList(c);
	int ma = -1000;
	int mb = -1000;
	int mnum = -1;
	for(auto bi = bchoices.begin(); bi != bchoices.end() ; ++ bi)
	{
		int b = *bi;
		int lb = static_cast<int>(std::sqrt(b));
		for(int a = -b ; a < 1000 ;  )
		{
			int num = primeNumber(a,b,primeset);
			if(num==-1)
			{
				std::cout<<"over"<<std::endl;
				c = 2*c;
				primeset = primeList(c);
			}
			else if(num>mnum)
			{
				mnum = num;
				ma = a;
				mb = b;
				a += 2;
			}
			else
			{
				a += 2;
			}
		}
	}
	std::cout<<ma<<' '<<mb<<' '<<ma*mb<<' '<<mnum<<std::endl;
}