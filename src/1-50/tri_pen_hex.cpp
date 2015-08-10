#include <math.h>
#include <iostream>

/** answer is 1533776805 */
int main(int argc, char*argv[])
{
	long n = 286;
	while (true)
	{
		long k = n*(n+1)/2;
		++ n;
		long k1 = static_cast<long>(sqrt(1+24*k));
		long k2 = static_cast<long>(sqrt(1+8*k));
		if(k1*k1==(1+24*k)&&k2*k2==(1+8*k))
		{
			if(((1+k1)%6)==0&&((1+k2)%4)==0)
			{
				std::cout<<n-1<<' '<<k<<std::endl;
				break;
			}
		}
	}
}