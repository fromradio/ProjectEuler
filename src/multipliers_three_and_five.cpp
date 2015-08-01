#include <iostream>

constexpr int number = 1000;

int multipliers(int n)
{
	int sum=0;
	for(int i = 0; i < n ; ++ i)
	{
		if((i%3)==0||(i%5)==0)
			sum += i;
	}
	return sum;
}

int main(int argc, char *argv[])
{
	if(argc == 1)
		std::cout<<multipliers(number)<<std::endl;
	else if(argc == 2)
	{
		int num = atoi(argv[1]);
		std::cout<<multipliers(num)<<std::endl;
	}
}