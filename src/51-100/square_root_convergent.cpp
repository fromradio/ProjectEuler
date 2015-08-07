#include <iostream>
#include "../LargeNumber.h"
#include <limits.h>
#include <math.h>


struct Expansion
{
	largeNumber a;
	largeNumber b;
};

bool exceed(const Expansion& e)
{
	// return (static_cast<int>(log10(e.b))>static_cast<int>(log10(e.a)));
	return e.b.digit()>e.a.digit();
}

int sequence(int level)
{
	int num = 0;
	std::function<void(Expansion,int)> impl = [&impl,level,&num](Expansion e, int l )->void
	{
		if(exceed(e))
		{
			num ++;
		}
		if( l == level )
			return ;
		Expansion ee;
		ee.a = e.a + e.b;
		ee.b = ee.a + e.a;
		impl(ee,l+1);
	};
	impl(Expansion{2,3},1);
	return num;
}

/** answer is 153 */
int main(int argc ,char * argv[])
{
	std::cout<<sequence(1000)<<std::endl;
}