#include <iostream>

int sumDifference(int n)
{
	int r = 0;
	for ( int i = 1 ; i <= n ; ++ i )
		for ( int j = 1 ; j < i ; ++ j )
			r += 2*i*j;
	return r;
}	
int main(int argc, char *argv[])
{
	std::cout<<sumDifference(100)<<std::endl;
}