#include <iostream>
#include <vector>
#include <fstream>

int maxPathSum(int n, const std::vector<int>& path)
{
	if((n*(n+1))/2!= path.size())
	{
		std::cerr<<n<<' '<<path.size()<<std::endl;
		throw std::invalid_argument("wrong argument");
		return -1;
	}
	std::vector<int> vs (n,0) , pvs(n,0);
	int k = 1;
	pvs[0] = path[0];
	for(int i = 1 ; i < n ; ++ i)
	{
		vs[0] = path[k] + pvs[0];
		vs[i] = path[k+i] + pvs[i-1];
		for(int j = 1 ; j <= i - 1; ++ j)
		{
			vs[j] = std::max(pvs[j],pvs[j-1]) + path[k+j];
		}
		pvs = vs;
		k += (i+1);
	}
	return *std::max_element(vs.begin(),vs.end());
}

int main(int argc, char *argv[])
{
	if (argc!=3)
		throw std::invalid_argument("wrong argument number");
	std::ifstream fin(argv[1]);
	if(!fin)
	{
		std::cerr<<"file does not exsist"<<std::endl;
		return -1;
	}

	std::vector<int> path;
	int i;
	while(fin>>i)
		path.emplace_back(i);
	std::cout<<maxPathSum(atoi(argv[2]),path)<<std::endl;
}