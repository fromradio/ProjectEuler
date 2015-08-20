#include "prime.h"
#include <iostream>
#include <cmath>

const long num = 1000000;
std::set<long> primes = primeList(static_cast<long>(sqrt(num)));

/** -1 for no chain */
int chainLength(long i, std::vector<bool>& mark)
{
	std::function<int(long,int,std::list<long>& chain)> impl = [&mark,&impl,i](long curr, int len,std::list<long>& chain)->int
	{
		chain.emplace_back(curr);
		if(curr>num)
			return -1;
		if (!mark[curr])
			return -1;
		else
			mark[curr] = false;
		
		if(curr == 1)
			return -1;
		long next = divSummation(division(curr,primes));
		auto iter = std::find(chain.begin(),chain.end(),next);
		if(iter == chain.end())
			return impl(next,len+1,chain);
		else
		{
			chain.emplace_back(next);
			return std::distance(iter,chain.end());
		}
	};
	std::list<long> chain;
	int len = impl(i,0,chain);
	if (len!=-1)
	{
		std::for_each(chain.begin(),chain.end(),[](auto i){std::cout<<i<<' ';});
		std::cout<<std::endl;
	}
	return len;
}

int main(int argc, char* argv[])
{
	int max_len = -1;
	long max_ind = -1;
	std::vector<bool> mark(num+1,true);
	for ( long i = 1 ; i <= num ; ++ i)
	{ 
		if(!mark[i])
			continue;
		int len = chainLength(i,mark);
		if(len > max_len)
		{
			max_len = len;
			max_ind = i;
		}
	}
	std::cout<<max_len<<' '<<max_ind<<std::endl;
	// std::cout<<divSummation(divs)<<std::endl;
}   