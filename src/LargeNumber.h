#include <vector>


class largeNumber
{
	//  18 digits
	std::vector<long long> __nums;
public:
	largeNumber()
		:__nums(1,0)
	{}
	largeNumber(const std::vector<long long>& ns)
		:__nums(ns)
	{}
	largeNumber(const largeNumber& ln)
		:__nums(ln.numbers())
	{}
	largeNumber(largeNumber&& ln)
		:__nums(ln.__nums)
	{}
	largeNumber(long long num)
	{
		if (num > 1e18)
		{
			long long d = num / 1e18;
			__nums.emplace_back(num-d*1e18);
			__nums.emplace_back(d);
		}
		else
		{
			__nums.emplace_back(num);
		}
	}
	largeNumber operator+( const largeNumber& ln) const
	{
		int n = 0;
		int s = std::max(ln.numbers().size(),__nums.size());
		std::vector<long long> ns;
		for ( int i = 0 ; i < s ; ++ i )
		{
			long long x = 0;
			if(i<__nums.size())
				x += __nums[i];
			if(i<ln.numbers().size())
				x += ln.numbers()[i];
			x += n;
			if( x > 1e18)
			{
				ns.emplace_back(x-1e18);
				n = 1;
			}
			else
			{
				ns.emplace_back(x);
				n=0;
			}

		}
		if(n==1)
			ns.emplace_back(1);
		return largeNumber(ns);
	}
	largeNumber operator*( const largeNumber& ln) const
	{
		/**  multiplication of two largeNumbers 
		  *  	(a*1e9+b)(c*1e9+d) = (a*c*1e18 + b*c*1e9 + a*d*1e9 + b*d)
		  */

	}
	largeNumber mul(long long n1, long long n2)
	{
		
	}
	largeNumber& operator=(const largeNumber& ln)
	{
		__nums = ln.numbers();
		return *this;
	}
	largeNumber& operator=(largeNumber&& ln)
	{
		__nums = std::move(ln.numbers());
		return *this;
	}

	const std::vector<long long>& numbers() const
	{
		return __nums;
	}
	std::string toString() const
	{
		std::string result;
		for(int i = 0 ; i < __nums.size() - 1  ; ++ i)
		{
			long long digit = 1e17;
			for(int d = 0 ; d < 17 ; ++ d)
			{
				if(__nums[i]/digit==0)
					result = '0'+result;
				else
					break;
				digit /= 10;
			}
			result = std::to_string(__nums[i]) + result ;
		}
		result = std::to_string(__nums[__nums.size()-1]) + result;
		return result;
	}
	int digit() const
	{
		return toString().size();
	}

};