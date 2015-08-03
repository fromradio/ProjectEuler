#include <list>
#include <vector>
#include <set>

std::set<long> primeList(long num)
{
	std::vector<bool> cons(num+1,true);
	long p = 2;
	while(p*p<=num)
	{
		for(long k = p*p; k<= num; k+=p)
		{
			cons[k] = false;
		}
		for(long i = p+1; i < num; ++ i)
		{
			if(cons[i]){
				p = i;
				break;
			}
		}
	}
	std::set<long> l;
	for (long i = 2; i <= num; ++i)
		if(cons[i])
			l.insert(i);
	return l;
}