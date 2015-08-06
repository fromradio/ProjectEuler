#include "prime.h"
#include <iostream>
#include <math.h>


int disNumber(int num, std::set<int>& primes)
{
	std::function<void(int,std::set<int>&facs)> impl = [&impl,num,primes](int resi,std::set<int>& facs)
	{
		if(resi==1) 
		{
			return;
		}
		int sq = sqrt(resi);
		auto iter = primes.begin();
		int fac = 1;
		while(true)
		{
			if(*iter > sq)
			{
				fac = resi;
				break;
			}
			else if((resi%(*iter))==0)
			{
				fac = *iter;
				break;
			}
			++ iter;
		}
		facs.insert(fac);
		impl(resi/fac,facs);
	};
	std::set<int> facs;
	impl(num,facs);
	return facs.size();
}


/** the answer is 134043 */
int main(int argc, char *argv[])
{
	std::set<int> primes = primeList(400);
	int n = 1;
	while(true)
	{
		// std::cout<<n<<std::endl;
		if(disNumber(n,primes)==4&&disNumber(n+1,primes)==4&&disNumber(n+2,primes)==4&&disNumber(n+3,primes)==4)
		{
			std::cout<<n<<std::endl;
			break;
		}
		if(n>1000000)
			std::cout<<"..."<<std::endl;
		++n;
	}
	// std::cout<<disNumber(10,primes)<<std::endl;
}

