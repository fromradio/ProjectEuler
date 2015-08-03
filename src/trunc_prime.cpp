#include "prime.h"
#include <iostream>
#include <string>

std::string addNum(int n, const std::string& num)
{
	if(n>=1&&n<=9)
	{
		return std::to_string(n)+num;
	}
	std::cerr<<"error n between 1 and 9"<<std::endl;
	return num;
}

bool stringPrime(const std::string& num, std::set<long>& primes)
{
	long n = atol(num.c_str());
	// while((*primes.rbegin())<n){
	// 	std::cout<<"grow"<<std::endl;
	// 	primes = primeList(2*n);
	// }
	if(primes.find(n)==primes.end())
		return 0;
	else
		return 1;
}

bool checkReversePrime(const std::string& num, std::set<long>& primes)
{
	int s = num.size();
	for(int i = 0 ; i < s - 1 ; ++i)
	{
		// std::cout<<std::string(num,0,i+1)<<std::endl;
		if(!stringPrime(std::string(num,0,i+1),primes))
			return false;
	}
	return true;
}

void growPrime(std::set<long>& truncprimes,const std::string& num,std::set<long>& primes)
{
	if(!stringPrime(num,primes))
		return;
	if(checkReversePrime(num,primes))
	{
		truncprimes.insert(atol(num.c_str()));
	}
	growPrime(truncprimes,"9"+num,primes);
	growPrime(truncprimes,"7"+num,primes);
	growPrime(truncprimes,"5"+num,primes);
	growPrime(truncprimes,"3"+num,primes);
	growPrime(truncprimes,"2"+num,primes);
	growPrime(truncprimes,"1"+num,primes); 
}

/** answer is 748317 */
int main(int argc, char *argv[])
{
	long pb = 1e7;
	std::set<long> primeset = primeList(pb);
	std::set<long> truncprimes;
	growPrime(truncprimes,"7",primeset);
	growPrime(truncprimes,"3",primeset);
	long sum = 0;
	std::for_each(truncprimes.begin(),truncprimes.end(),[&sum](auto& i){sum+=i;});
	std::cout<<truncprimes.size()<<std::endl;
	std::cout<<sum-10<<std::endl;
}