#ifndef PRIME_H__
#define PRIME_H__
#include <list>
#include <vector>
#include <set>
#include <map>

template<class Ind>
std::set<Ind> primeList(Ind num)
{
	std::vector<bool> cons(num+1,true);
	Ind p = 2;
	while(p*p<=num)
	{
		for(Ind k = p*p; k<= num; k+=p)
		{
			cons[k] = false;
		}
		for(Ind i = p+1; i < num; ++ i)
		{
			if(cons[i]){
				p = i;
				break;
			}
		}
	}
	std::set<Ind> l;
	for (Ind i = 2; i <= num; ++i)
		if(cons[i])
			l.insert(i);
	return l;
}

template<class Ind>
using Factor = std::map<Ind,int>;

// #include <iostream>
template<class Ind>
Factor<Ind> factor(Ind n, const std::set<Ind>& primes)
{
	std::function<void(long,Factor<Ind>&)> impl = [primes,&impl](long r,Factor<Ind>& f)
	{
		if(r==1)
			return;
		for(auto iter = primes.begin(); iter != primes.end() ; ++ iter)
		{
			if((r%(*iter))==0)
			{
				if(f.find(*iter)==f.end())
					f[*iter] = 1;
				else
					f[*iter] += 1;
				impl(r/(*iter),f);
				break;
			}
		}
	};
	Factor<Ind> fac;
	impl(n,fac);
	return fac;
}



#endif