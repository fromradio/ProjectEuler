#include<iostream>
#include<list>

#include<cmath>
constexpr long number = 600851475143;

// the minimal factor has to be prime
template<class Ind>
Ind minimalFactor(Ind n)
{
	Ind b = static_cast<Ind>(std::sqrt(n));
	for ( Ind i = 2 ; i <= b; ++ i)
		if((n%i)==0)
			return i;
	return n;
}

// 
template<class Ind>
void factorDecomposition(Ind n, std::list<Ind>& facs)
{
	Ind fac = minimalFactor(n);
	facs.emplace_back(fac);
	if(fac==n)
		return;
	else
		factorDecomposition(n/fac,facs);
}

template<class Ind>
Ind maxFactor(Ind n)
{
	std::list<Ind> facs;
	factorDecomposition(n,facs);
	return *std::max_element(facs.begin(),facs.end());
}

int main(int argc, char* argv[])
{
	if(argc==1)
		std::cout<<maxFactor(number)<<std::endl;
	else if(argc==2)
	{
		int num = atoi(argv[1]);
		std::cout<<maxFactor(num)<<std::endl;
	}
}