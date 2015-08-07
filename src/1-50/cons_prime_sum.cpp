#include "prime.h"
#include <iostream>

/** answer is 997651 */
int main(int argc, char* argv[])
{
	long num = 1e6;
	std::set<long> primes = primeList(num);
	long mp;
	int ml;
	for ( auto sp = primes.begin() ; sp != primes.end() ; ++ sp )
	{
		long sum = 0;
		long len = 0;
		for ( auto ap = sp ; ap != primes.end() ; ++ ap)
		{
			++ len;
			sum += *ap;
			if(sum>num)
				break;
			else
			{
				if(primes.find(sum)!=primes.end())
				{
					if(len>ml)
					{
						ml = len;
						mp = sum;
					}
				}
			}
		}
	}
	std::cout<<primes.size()<<std::endl;
	std::cout<<mp<<' '<<ml<<std::endl;
}