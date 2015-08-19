#include <iostream>
#include <cmath>

const double c1 = 1.0/sqrt(3.0);
const double c2 = 2.0-sqrt(3.0);

long num = 1e9;
long mnum = static_cast<long>(sqrt(num))/2;

long is_true(long m)
{
	/** a = m*m+n*n, b = 2*(m*m-n*n) */
	long n = static_cast<long>(c1*m);
	long a = m*m+n*n;
	long result = 0;
	if(a%2==0)
	{

		n = n+1;
		a = m*m+n*n;
	}
	long b = 2*(m*m-n*n);
	if((a-b)==1||(b-a)==1)
	{
		if(a+a+b<num)
		{
			result += (a+a+b);
		}
	}
	n = static_cast<long>(c2*m);
	a = m*m+n*n;
	if(a%2==0)
	{
		n = n+1;
		a = m*m+n*n;
	}
	b = 4*m*n;
	if((a-b)==1||(b-a)==1)
	{
		if(a+a+b<num)
		{
			result += (a+a+b);
		}
	}
	return result;
}

int main(int argc, char* argv[])
{
	long count = 0;
	for ( int m = 2 ; m < mnum ; ++ m)
	{
		count += is_true(m);
	}
	std::cout<<count<<std::endl;
}