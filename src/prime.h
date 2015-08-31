#ifndef PRIME_H__
#define PRIME_H__
#include <list>
#include <vector>
#include <set>
#include <map>
#include "stats.h"
#include <iostream>


template<class Ind>
std::set<Ind> primeSet(Ind num)
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
std::list<Ind> primeList(Ind num)
{
	std::vector<bool> cons(num+1,true);
	Ind p = 2;
	while(p*p<=num)
	{
		for(Ind k = p*p; k <= num; k += p)
		{
			cons[k] = false;
		}
		for(Ind i = p+1 ; i < num; ++i)
		{
			if(cons[i]){
				p = i;
				break;
			}
		}
	}
	std::list<Ind> primes;
	for(Ind i = 2; i <= num ; ++ i)
		if(cons[i])
			primes.emplace_back(i);
	return primes;
}

template<class Ind>
using Factor = std::map<Ind,int>;

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
				return ;
			}
		}
		f[r] = 1;
	};
	Factor<Ind> fac;
	impl(n,fac);
	return fac;
}

/** get the divisors */
template<class Ind>
using Divisors = std::set<Ind>;

template<class Ind>
Divisors<Ind> division(Ind n, const std::set<Ind>& primes)
{
	auto f = factor(n,primes);
	std::function<void(Ind,typename Factor<Ind>::iterator,Divisors<Ind>&)> impl = [n,&f,primes,&impl](Ind l,typename Factor<Ind>::iterator iter,Divisors<Ind>& divs)
	{
		if (iter==f.end())
		{
			if (l!=n)
				divs.insert(l);
		}
		else
		{
			Ind r = 1;
			for(int i = 0 ; i <= iter->second ; ++ i)
			{
				auto it = iter;
				++ it;
				impl(l*r,it,divs);
				r *= iter->first;
			}
		}
	};
	Divisors<Ind> result;
	impl(1,f.begin(),result);
	return result;
}

template<class Ind>
Ind divSummation(const Divisors<Ind>& divs)
{
	Ind sum = 0;
	std::for_each(divs.begin(),divs.end(),[&sum](auto i){sum += i;});
	return sum;
}
#endif