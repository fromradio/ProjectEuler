#include <iostream>
#include <functional>

constexpr int upbound = 4000000; // 4 million


void FibonacciFilter(int b,std::function<void(int)> filter)
{
	std::function<void(int,int)> impl = [&impl,b,filter](int i1, int i2)->void{
		if (i1>b)
			return;
		else{
			filter(i1);
			impl(i2,i1+i2);
		}
	};
	impl(1,2);
}

int main(int argc, char* argv[])
{
	int sum = 0;
	auto filter = [&sum](int i){
		if ((i%2)==0)
			sum += i;
	};
	if(argc==1)
	{
		FibonacciFilter(upbound,filter);
		std::cout<<sum<<std::endl;
	}
	else if(argc==2)
	{
		int b = atoi(argv[1]);
		FibonacciFilter(b,filter);
		std::cout<<sum<<std::endl;
	}
}
