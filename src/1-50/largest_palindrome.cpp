#include <iostream>
#include <math.h>
#include <vector>

/** brute force program */
void findPalindrome()
{
	int maxp=-1;
	for(int i = 100; i <= 999; ++i )
	{
		for(int j=100; j <= 999; ++j)
		{
			int k = i*j;
			int c = 0, d=k;
			std::vector<int> ws;
			do{
				c = d%10;
				d = d/10;
				ws.emplace_back(c);
			}while(d!=0);
			int w = ws.size();
			bool bp = true;
			for(int ii = 0 ; ii < w/2 ; ++ ii)
			{
				if(ws[ii]!=ws[w-1-ii])
				{
					bp = false;
					break;
				}
			}
			if(bp)
			{
				maxp = maxp<k?k:maxp;
			}
		}
	}
	std::cout<<maxp<<std::endl;
}

int main(int argc, char* argv[])
{
	findPalindrome();
}