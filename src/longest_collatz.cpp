#include <iostream>

long chainLength(long num)
{
	long l = 0;
	long resi = num;
	while (resi!=1)
	{
		if((resi%2)==0)
			resi = resi/2;
		else
			resi = 3*resi + 1;
		++l;
	}
	return l;
}

int main(int argc, char* argv[])
{
	long mi = -1;
	long mp = -1;
	for(int i = 1 ; i < 1e6 ; ++i)
	{
		long l = chainLength(i);
		if(mp<l)
		{
			mi = i;
			mp = l;
		}
	}
	std::cout<<mi<<' '<<mp<<std::endl;
}