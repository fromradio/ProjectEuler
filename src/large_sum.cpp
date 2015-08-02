#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	long long r = 0;
	std::ifstream fin("bin/largesum.data");
	if(!fin){
		std::cerr<<"open error"<<std::endl;
		return -1;
	}
	for( int i = 0 ; i < 100 ; ++ i)
	{
		std::string str;
		std::getline(fin,str);
		long long k = atoll(std::string(str,0,13).c_str());
		r+=k;
	}
	std::cout<<r<<std::endl;
}