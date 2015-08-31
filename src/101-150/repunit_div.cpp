#include "../prime.h"

template<class Ind>
Ind powerMod(Ind base, Ind power, Ind dom)
{
	Ind count = 0;
	Ind mod=1;
	do{
		mod = (base*mod)%dom;
		++ count;
	}while(count<power);
	return mod;
}


int main(int argc, char *argv[])
{
	int num = 10;
	auto primes = primeSet(4*num*num);
	auto tprimes = primeSet(2*num);
	primes.erase(2);
	primes.erase(5);
	for(auto&& p:primes)
	{
		if(p<num*num)
			continue;
		auto divs = division(p-1,tprimes);
		int a=p-1;
		for(auto div:divs)
		{
			if(powerMod(10,div,p)==1)
			{
				a = div;
				break;
			}
		}
		std::cout<<p<<' '<<a<<std::endl;
		if(a>num*num)
			break;
	}
}