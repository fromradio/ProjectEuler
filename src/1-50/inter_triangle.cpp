#include "prime.h"
#include <iostream>
#include <map>

const std::set<int> primes = primeList(1000);

typedef std::map<int,int> 	Factor;

int factor2int(const Factor& fac)
{
	int r = 1;
	for (auto i=fac.begin(); i != fac.end(); ++ i)
	{
		for (int j = 0 ; j < i->second ; ++j )
		{
			r*= i->first;
		}
	}
	return r;
}

void AllFactors(int lim,const Factor& fac, std::list<Factor>& facs)
{
	for(auto i:primes)
	{
		if(i <= lim)
		{
			Factor nf(fac);
			if(nf.find(i)==nf.end())
				nf[i] = 1;
			else
				nf[i] += 1;
			facs.emplace_back(nf);
			AllFactors(lim/i,nf,facs);
		}
		else
			break;
	}
}

int trinum(const Factor& fac,int n)
{
	std::function<void(const Factor&, int,std::set<int>&)> impl = [n,&impl](const Factor& fac,int c,std::set<int>& tris)
	{
		if(c==100)
			std::cout<<"here"<<n<<std::endl;

		if(c>=n)
			return;
		if(c>n/2)
			tris.insert(c);
		if(fac.empty())
			return;
		int key = fac.begin()->first;
		Factor f1(fac),f2(fac);
		if(f1[key]==1)
		{
			f1.erase(key);
		}
		else
			f1[key]-=1;
		f2.erase(key);
		if(c==100)
			std::cout<<c<<' '<<n<<std::endl;
		impl(f1,c*key,tris);
		impl(f2,c,tris);
	};
	Factor f(fac);
	std::set<int> ts;
	impl(f,1,ts);
	return ts.size();
}


/** answer is 84 with 8 triangles */
int main(int argc, char *argv[])
{
	Factor fac;
	std::list<Factor> facs;
	AllFactors(1000,fac,facs);
	std::cout<<facs.size()<<std::endl;
	auto b = facs.back();
	int m,mi;
	for(auto i = facs.begin(); i != facs.end() ; ++ i)
	{
		Factor f(*i);
		if(f.find(2)==f.end())
			continue;
		for(auto fi = f.begin(); fi != f.end(); ++ fi)
			fi->second *= 2;
		f[2] -= 1;
		int tn = trinum(f,factor2int(*i));
		if(tn>m)
		{
			m = tn;
			mi = factor2int(*i);
		}
	}
}