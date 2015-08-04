#include <iostream>
#include <list>
/** recursion solution */
int coin(int p, std::list<int> coins)
{
	if(coins.empty())
		return 0;
	if(p>coins.front())
		return coin(p-coins.front(),coins) + coin(p, [&coins]()->std::list<int>{coins.pop_front();return coins;}());
	else if(p==coins.front())
		return 1;
	else
		return 0;
}

/** answer is 73682 */
int main(int argc, char* argv[])
{
	std::list<int> coins{1,2,5,10,20,50,100,200};
	std::cout<<coin(200,coins)<<std::endl;
}