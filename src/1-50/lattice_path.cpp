#include <functional>

int main(int argc, char *argv[])
{
	std::function<int(int,int)> impl = [&impl](int m,int n)
	{
		if (m==0)
			return 1;
		else if(n==0)
			return 1;
		else
			return impl(m-1,n)+impl(m,n-1);
	};
	printf("%d",impl(20,20));
}