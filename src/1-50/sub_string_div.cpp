#include <iostream>
#include <string>
#include <map>
#include <functional>

char numchars[] = {'0','1','2','3','4','5','6','7','8','9'};


long long sumSubSting()
{
	std::function<void(std::map<int,bool>,std::string,int)> impl = [&impl](std::map<int,bool> m,std::string str,int level)
	{
		// std::cout<<str<<std::endl;
		if(level == 10)
		{
			if(atoi(std::string(str,level-3).c_str())%17==0)
			{
				std::cout<<str<<std::endl;
			}
			return;
		}
		bool next = false;
		if(level == 9)
		{
			if(atoi(std::string(str,level-3).c_str())%13==0)
				next = true;
		}
		else if (level == 8)
		{
			if(atoi(std::string(str,level-3).c_str())%11 == 0)
				next = true;
		}
		else if (level == 7)
		{
			if(atoi(std::string(str,level-3).c_str())%7 == 0)
				next = true;
		}
		else if (level == 6)
		{
			if(atoi(std::string(str,level-3).c_str())%5 == 0)
				next = true;
		}
		else if (level == 5)
		{
			if(atoi(std::string(str,level-3).c_str())%3 == 0)
				next = true;
		}
		else if( level == 4)
		{
			if(atoi(std::string(str,level-3).c_str())%2 == 0)
				next = true;
		}
		else 
			next = true;
		if(next)
		{
			for(int i = 0 ; i < 10 ; ++ i)
			{
				if(m[i]==false)
				{
					std::map<int,bool> mm(m);
					mm[i] = true;
					char c = i + '0';
					impl(mm,std::string(str)+c,level + 1);
				}
			}
		}
	};
	std::map<int,bool> m;
	for (int i = 0 ; i < 10 ; ++ i)
		m[i] = false;
	std::string str;
	impl(m,str,0);
	return 10;
}

/** answer is 16695334890 */
int main(int argc, char *argv[])
{
	sumSubSting();
}