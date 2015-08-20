#include "prime.h"
#include <iostream>

int waysOfSum(long n, const std::set<long>& primes)
{
	std::function<int(long,std::set<long>::const_iterator)>impl = [&primes,&impl](long resi,std::set<long>::const_iterator iter)
	{
		if (resi==0)
			return 1;
		if(iter==primes.end())
		{
			return 0;
		}
		else if(resi<0)
			return 0;
		std::set<long>::const_iterator it = iter;
		++it;
		return impl(resi,it)+impl(resi-(*iter),iter);
	};
	return impl(n,primes.begin());
}

void test(std::set<long>::const_iterator i, const std::set<long>& s)
{
	if(i==s.end())
		return;
	else
	{
		std::cout<<(*i)<<std::endl;
		test(++i,s);
	}
}

int main(int argc, char *argv[])
{
	long num = 1000;
	auto primes= primeList(num);
	for (int i = 0 ; i < num ; ++ i)
	{
		if(waysOfSum(i,primes)>5000)
		{
			std::cout<<i<<std::endl;
			break;
		}
	}
}