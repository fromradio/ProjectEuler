#include <iostream>
#include <cmath>
#include <climits>
#include <vector>


bool isPalindrome(int n, int base)
{
	std::vector<int> ws;
	int c = 0, d=n;
	do{
		c = d%base;
		d = d/base;
		ws.emplace_back(c);
	}while(d!=0);
	int w = ws.size();
	bool bp = true;
	for ( int ii = 0 ; ii < w/2; ++ ii)
	{
		if(ws[ii]!=ws[w-1-ii])
		{
			bp = false;
			break;
		}
	}
	return bp;
}

int main(int argc, char *argv[])
{
	std::cout<<INT_MAX<<std::endl;
	std::cout<<LONG_MAX<<std::endl;
	int count = 0;
	for(int i = 0 ; i < 1000000 ; ++ i)
	{
		if(isPalindrome(i,10))
		{
			if(isPalindrome(i,2))
				count += i;
		}
	}
	std::cout<<count<<std::endl;
	std::cout<<isPalindrome(585,10)<<std::endl;
	std::cout<<isPalindrome(585,2)<<std::endl;
}