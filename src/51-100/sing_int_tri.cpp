#include "prime.h"
#include <iostream>
#include <map>
#include <math.h>
#include "../stats.h"

const long num = 1500000;
const long sn = static_cast<long>(sqrt(num));
// const std::set<long> primes = primeList(num);

typedef std::map<long,long> 	Factor;

void factor(long n, const std::set<long>& primes,Factor &facs)
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

bool SingularTriangle(const Factor& fac,long n)
{
	std::function<void(const Factor&, long,std::set<long>&)> impl = [n,&impl](const Factor& fac,long c,std::set<long>& tris)
	{
		if(c>=n)
			return;
		if(c>n/2)
			tris.insert(c);
		if(fac.empty())
			return;
		long key = fac.begin()->first;
		Factor f1(fac),f2(fac);
		if(f1[key]==1)
		{
			f1.erase(key);
		}
		else
			f1[key]-=1;
		f2.erase(key);
		impl(f1,c*key,tris);
		impl(f2,c,tris);
	};
	Factor f(fac);
	std::set<long> ts;
	impl(f,1,ts);
	int s = ts.size()/2;
	if(s==1)
		return true;
	else
		return false;
	// return ts.size();
}

template<class Ind>
Ind gcd(Ind a, Ind b)
{
    Ind temp;
    while (b != 0)
    {
        temp = a % b;

        a = b;
        b = temp;
    }
    return a;
}/** 快速求解：
  * 	利用Euclid's formula，所有三元组可以表示为m*m-n*n,
  * 2*m*n, m*m+n*n 或者这个的倍数，其中m, n互素。
  */
long fastSingularIntegerTriangle(long limit)
{
	int choices[limit+1];
	for ( int i = 0 ; i < limit + 1 ; ++ i)
		choices[i] = 0;
	bool even = true;
	for ( int m = 2 ; m < sqrt(limit/2) ; ++ m)
	{
		for (int n= even; n < m ; n += 2)
		{
			if(gcd(m,n)==1)
			{
				long k = 2*m*(n+m);
				for (long t = k ; t <= limit ; t += k)
					choices[t] ++;
			}
		}
		even = !even;
	}
	long count=0;
	for(long i = 2 ; i <= limit ; ++ i)
		if(choices[i]==1)
			++ count;
	return count;
}

int main(int argc, char*argv[])
{
	// int n = 0;
	TimeStats ts;
	std::cout<<fastSingularIntegerTriangle(num)<<std::endl;
	// for (long i = 2 ; i <= num ; i += 2)
	// {
	// 	if((i%10000)==0)
	// 		std::cout<<i<<' '<<n<<std::endl;
	// 	Factor f;
	// 	factor(i,primes,f);
	// 	for(auto fi = f.begin(); fi != f.end(); ++ fi)
	// 		fi->second *= 2;
	// 	f[2] -= 1;
	// 	if(SingularTriangle(f, i))
	// 	{
	// 		n ++;
	// 	}
	// }
	// ts.toc();
	// std::cout<<n<<std::endl;
	std::cout<<ts.milliseconds()<<" ms"<<std::endl;
}