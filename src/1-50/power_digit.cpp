#include <iostream>
#include <string>

int c2i(char c)
{
	return c-'0';
}

char i2c(int i)
{
	return i+'0';
}
void stringPower(std::string& str)
{
	int n = 0;
	for (auto c = str.begin(); c != str.end(); ++c)
	{
		int i = c2i(*c);
		int t = i*2;
		(*c) = i2c((t%10)+n);
		n = t/10;
	}
	if(n>0)
		str.push_back(i2c(n));
}

int digit(int num)
{
	int i = 1;
	std::string str("2");
	while(i<num)
	{
		stringPower(str);
		++i;
	}
	std::cout<<str<<std::endl;
	int r = 0;
	for(auto c = str.begin(); c != str.end(); ++c)
	{
		r += c2i(*c);
	}
	return r;
}

int main(int argc, char *argv[])
{
	std::cout<<digit(1000)<<std::endl;
}