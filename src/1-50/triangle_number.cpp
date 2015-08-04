#include <iostream>
#include <map>
#include <list>
#include <chrono>
#include <vector>

/** a very fast growing prime number set */
void growingPrimeSet(std::list<long>& primes,long mp, long np)
{
	std::vector<long> conditions(np*np-mp*mp-1,true);
	for(auto iter= primes.begin();iter!=primes.end();++iter)
	{
		if((*iter)>=np)
			break;
		long bi = (mp*mp/(*iter)+1)*(*iter);
		for(long k = bi ; k < np*np ; k+=(*iter))
		{
			conditions[k-mp*mp-1] = false;
		}
	}
	for(long k = mp*mp+1; k < np*np ; ++k)
	{
		if(conditions[k-mp*mp-1]){
			primes.emplace_back(k);
		}
	}
}

void factor(long n, const std::list<long>& primes,std::map<long,int>&facs)
{
	if(n==1)
		return;
	for (auto iter = primes.begin(); iter != primes.end(); ++ iter)
	{
		if((n%(*iter))==0)
		{
			if(facs.find(*iter)==facs.end())
				facs[*iter] = 1;
			else
				facs[*iter] += 1;
			factor(n/(*iter),primes,facs);
			return;
		}
	}
}

long findTriangleNumber(long k,std::list<long>& primes,std::list<long>::iterator& iter)
{
	long trinum = k*(k+1)/2;
	while(primes.back()*primes.back()<trinum)
	{
		growingPrimeSet(primes,*iter,*(++iter));
	}
	std::map<long,int> fac;
	factor(trinum,primes,fac);
	long r = 1;
	for (auto mi = fac.begin(); mi != fac.end() ; ++ mi)
	{
		r *= (mi->second+1);
	}
	return r;
}

int main(int argc, char* argv[])
{
	std::list<long> primes;
	primes.emplace_back(2);
	primes.emplace_back(3);
	auto iter = primes.begin();
	long k = 2;
	while (findTriangleNumber(k,primes,iter)<500)
	{
		++k;
	}
	std::cout<<k<<' '<<k*(k+1)/2<<std::endl;
}