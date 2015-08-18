#include "prime.h"
#include <cmath>
#include <iostream>
#include "../stats.h"

const int num = 1000000;
const int np = num/2;


std::vector<std::vector<int>> primeFactor(int n, const std::set<int>& primes)
{
	std::vector<std::vector<int>> facs(n+1);
	for (auto p:primes)
	{
		for(int i = 2*p; i <= n ; i += p)
			facs[i].emplace_back(p);
	}

	std::function<void(int,int,int,const std::vector<int>&,std::vector<int>&)> tranverse = [&tranverse](int l,int i,int m,const std::vector<int>& f, std::vector<int>& lf)
	{
		if(l == 0)
		{
			lf.emplace_back(m);
			return ;
		}
		else
		{
			for(int j = i+1 ; j <= f.size() - l ; ++ j)
				tranverse(l-1,j,m*f[j],f,lf);
		}
	};

	long whole_count = 0;
	for (int i = 2 ; i <= n ; ++ i)
	{
		int count = i-1;
		int t = -1;
		for(int l = 1 ; l <= facs[i].size() ; ++ l)
		{
			std::vector<int> lf;
			tranverse(l,-1,1,facs[i],lf);
			for(auto f:lf)
				count += t*(i/f-1);
			t = -t;
		}
		whole_count+=count;
	}
	std::cout<<whole_count<<std::endl;
	return facs;
}


int main(int argc, char*argv[])
{
	TimeStats ts;
	auto primes = primeList(np);
	auto facs = primeFactor(num,primes);
	ts.toc();
	std::cout<<ts.milliseconds()<<" ms"<<std::endl;
}