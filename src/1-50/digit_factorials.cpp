#include <math.h>
#include <iostream>
#include <cassert> 

template<class Ind>
long long fac(Ind n)
{
	std::function<long long(Ind,long long)> impl = [&impl](Ind n, long long c)->long long
	{
		assert(n>=0);
		if(n==0)
			return 1;
		if(n==1)
			return c;
		else
			return impl(n-1,c*n);
	};
	return impl(n,1);
}

template<class Ind>
bool isDigitFac(Ind num)
{
	int d = static_cast<int>(log10(num)) + 1;
	Ind in = num;
	Ind sum = 0;
	for(int i = 0 ; i < d; ++ i)
	{
		Ind digit = in % 10;
		sum += fac(digit);
		in = (in - digit) /10;
	}
	return sum==num;
}

/** the answer is 40730 */
int main(int argc, char *argv[])
{
	long long sum = 0;
	for(long long i = 3 ; i < 1e7 ; ++ i)
	{
		if(isDigitFac(i))
			sum += i;
	}
	std::cout<<sum<<std::endl;
}