#ifndef PRIME_H__
#define PRIME_H__
#include <list>
#include <vector>
#include <set>

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

#endif