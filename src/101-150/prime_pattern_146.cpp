#include "../prime.h"
#include "../stats.h"
#include <iostream>
#include <cmath>

bool isSquare(long n)
{
	long s = static_cast<long>(std::sqrt(n));
	return s*s==n;
}


int main(int argc, char *argv[])
{ 
	// long num = 150000000;
	long num = 1000000;
	TimeStats ts;
	auto primes = primeList(num);
	std::cout<<primes.size()<<std::endl;
	ts.toc();
	// std::list<int> r;
	int stats = 0;
	long curr;
	for(auto p:primes)
	{
		if(isSquare(p-1))
				std::cout<<p<<std::endl;
		if(stats==1)
		{
			// std::cout<<p<<' '<<curr+3<<std::endl;
			if(p==curr+3)
			{
				stats=2;
			}
			else
			{
				stats=0;
			}
		}
		else if(stats==2)
		{
			if(isSquare(p-1))
				std::cout<<p<<std::endl;
			if(p==curr+7)
			{
				stats=3;
			}
			else
			{
				stats=0;
			}
		}
		else if(stats==3)
		{
			if(isSquare(p-1))
				std::cout<<p<<std::endl;
			if(p==curr+9)
				stats=4;
			else
				stats=0;
		}
		else if(stats==4)
		{
			if(isSquare(p-1))
				std::cout<<p<<std::endl;
			if(p==curr+13)
				stats=5;
			else
				stats=0;
		}
		else if(stats==5)
		{
			if(p==curr+27)
			{
				std::cout<<curr<<std::endl;
				stats=0;
			}
			else
				stats=0;
		}
		if(stats==0)
		{
			if(isSquare(p-1))
			{
				stats = 1;
				curr = p-1;
			}
		}
	}

	std::cout<<ts.milliseconds()<<"ms"<<std::endl;
}