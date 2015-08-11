#include "prime.h"
#include "../stats.h"
#include <iostream>
#include <string>
#include <map>


template<class Ind>
using Pair = std::map<Ind,std::set<Ind> >;

template<class Ind>
Pair<Ind> findPair(Ind num)
{
	auto primes = primeList(num);
	Pair<Ind> result;
	for (auto&& p:primes)
	{
		std::string str = std::to_string(p);
		int l = str.size();
		for(int i = 1 ; i <= l-1 ; ++ i)
		{
			if(str[i]=='0')
				continue;
			Ind p1 = atol(std::string(str,0,i).c_str());
			Ind p2 = atol(std::string(str,i).c_str());
			if(primes.find(p1)!= primes.end() && primes.find(p2)!= primes.end() )
			{
				if(result.find(p1)==result.end())
				{
					result[p1] = std::set<Ind> ();
				}
				result[p1].insert(p2);
			}
		}
	}
	return result;
}

template<class Ind>
void analyzePair(Pair<Ind>& pairs)
{
	/** n pairs exists? */
	// regularize pairs
	Pair<Ind> nps;
	int mp = -1;
	int mi = -1;
	for(auto iter = pairs.begin(); iter != pairs.end() ; ++ iter)
	{
		// nps[iter->first] = std::set<Ind>();
		std::set<Ind> s;
		for(auto&& p:iter->second)
		{
			if(pairs.find(p)==pairs.end())
				continue;
			if(pairs[p].find(iter->first)!=pairs[p].end())
				s.insert(p);
		}
		if(s.size()>=4)
		{
			nps[iter->first] = s;
			if(mp<static_cast<int>(nps[iter->first].size()))
			{
				mi = iter->first;
				mp = nps[iter->first].size();
			}
		}
	}
	std::set<Ind> cans;
	Ind minnum = 10000000;
	for(auto iter = nps.begin() ; iter != nps.end() ; ++ iter)
	{
		bool has_cans = false;
		std::set<Ind> cs;
		for(auto&&p : iter->second)
		{
			if(nps.find(p)==nps.end())
				continue;
			std::set<Ind> tests;
			std::set_intersection(iter->second.begin(),iter->second.end(),nps[p].begin(),nps[p].end(), std::inserter(tests,tests.begin()));
			for(auto&& p1:tests)
			{
				for(auto&& p2:tests)
				{
					for(auto&& p3:tests)
					{
						if(nps[p1].find(p2)!=nps[p1].end() && nps[p1].find(p3)!=nps[p1].end() && nps[p2].find(p3)!= nps[p2].end())
						{
							if(minnum>(iter->first+p+p1+p2+p3))
								minnum = iter->first+p+p1+p2+p3;
						}
					}
				}
			}
		}
	}
	std::cout<<"minumal sum is "<<minnum<<std::endl;
}

int main(int argc, char *argv[])
{
	TimeStats ts;
	long num = 100000000;
	auto pairs = findPair(num);
	analyzePair(pairs);
	ts.toc();
	std::cout<<ts.milliseconds()<<" ms"<<std::endl;
}