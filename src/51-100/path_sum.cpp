#include <iostream>
#include <fstream>
#include <set>
#include <climits>
#include <vector>
#include "../stats.h"

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

std::vector<long> computePath(const std::vector<int>& mat, int n, int start = 0, int ways = 2)
{
	std::vector<long> dist(n*n,-1);
	std::vector<int> prev(n*n,-1);
	std::vector<bool> unvisit(n*n,true);
	dist[start] = mat[start];
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
	int u = start;
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
		if(ways >= 3 )
		{
			if(i>0)
			{
				if((dist[u-n]==-1)||(dist[u-n]>dist[u]+mat[u-n]))
				{
					dist[u-n] = dist[u]+mat[u-n];
					prev[u-n] = u;
				}
			}
		}
		if(ways == 4)
		{
			if(j>0)
			{
				if((dist[u-1]==-1)||(dist[u-1]>dist[u]+mat[u-1]))
				{
					dist[u-1] = dist[u]+mat[u-1];
					prev[u-1] = u;
				}
			}
		}
		u = findu();
	}
	return dist;
}

void computePathThree(const std::vector<int>& mat, int num)
{
	std::vector<long> dis;
	for(int i = 0 ; i < num ; ++ i)
	{
		auto d = computePath(mat,num,i*num,3);
		for(int j = 0 ; j < num ; ++ j)
			dis.emplace_back(d[j*num+num-1]);
	}
	std::cout<<*std::min_element(dis.begin(),dis.end())<<std::endl;;
}

int main(int argc, char* argv[])
{
	if (argc != 4  && argc != 3)
	{
		std::cerr<<"There should be 3 or 4 arguments "<<std::endl;
		return -1;
	}
	int num = atoi(argv[2]);
	std::vector<int> mat = readMatrix(argv[1],num);
	int method = 0;
	if (argc==4)
		method = atoi(argv[3]);
	if(method != 0 && method != 1 && method != 2)
	{
		std::cerr<<"Wrong method!"<<std::endl;
		return -1;
	}
	TimeStats ts;
	if(method==0)
	{
		auto dis = computePath(mat,num,0);
		std::cout<<dis[num*num-1]<<std::endl;
	}
	else if(method==1)
		computePathThree(mat,num);
	else if(method==2)
	{
		auto dis = computePath(mat,num,0,4);
		std::cout<<dis[num*num-1]<<std::endl;
	}
	ts.toc();
	std::cout<<ts.milliseconds()<<" ms"<<std::endl;
}