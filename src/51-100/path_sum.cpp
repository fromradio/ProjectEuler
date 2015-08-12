#include <iostream>
#include <fstream>
#include <set>
#include <climits>
#include <vector>

long MAX_LONG = LONG_MAX;

std::vector<int> readMatrix( const char* filename, int n)
{
	std::ifstream fin(filename);
	if(!fin)
	{
		std::cerr<<"Error: file not exists, null vector is returned!"<<std::endl;
		return std::vector<int>();
	}
	std::vector<int> mat(n*n);
	for (int i = 0 ; i < n ; ++ i)
	{
		for(int j = 0 ; j < n-1 ; ++ j)
		{
			fin>>mat[i*n+j];
			char c;
			fin>>c;
		}
		fin>>mat[i*n+n-1];
		// fin>>mat[i];
		// char c;
		// fin>>c;
	}
	return mat;
}

void computePath(const std::vector<int>& mat, int n)
{
	std::vector<long> dist(n*n,-1);
	std::vector<int> prev(n*n,-1);
	std::vector<bool> unvisit(n*n,true);
	dist[0] = mat[0];
	auto findu = [&dist, &unvisit,n]()->int{
		long mind = MAX_LONG;
		int ind = -1;
		for (int i = 0 ; i < n*n ; ++ i){
			if(mind > dist[i]&&unvisit[i]&&dist[i]!=-1)
			{
				mind = dist[i];
				ind = i;
			}
		}
		return ind;
	};
	int u = 0;
	while (u != -1 )
	{
		unvisit[u] = false;
		int i = u/n;
		int j = u%n;
		if(i<(n-1))
		{
			if(dist[u+n]==-1)
			{
				dist[u+n] = dist[u] + mat[u+n];
				prev[u+n] = u;
			}
			else if(dist[u+n]>dist[u]+mat[u+n])
			{
				dist[u+n] = dist[u] + mat[u+n];
				prev[u+n] = u;
			}
		}
		if(j<(n-1))
		{
			if((dist[u+1]==-1)||(dist[u+1]>dist[u]+mat[u+1]))
			{
				dist[u+1] = dist[u]+mat[u+1];
				prev[u+1] = u;
			}
		}
		u = findu();
	}
	std::cout<<dist[n*n-1]<<std::endl;
	int p = n*n-1;
	long d = 0;
	while(p!=0)
	{
		std::cout<<"("<<p/n<<','<<p%n<<") ";
		d += mat[p];
		p = prev[p];
	}
	std::cout<<std::endl;
	std::cout<<"distance "<<d<<std::endl;
}

int main(int argc, char* argv[])
{
	if (argc != 3 )
	{
		std::cerr<<"There should be 3 arguments "<<std::endl;
		return -1;
	}
	int num = atoi(argv[2]);
	std::vector<int> mat = readMatrix(argv[1],num);
	// std::for_each(mat.begin(),mat.end(),[](auto i){std::cout<<i<<' ';});
	// std::cout<<std::endl;
	computePath(mat,num);
}