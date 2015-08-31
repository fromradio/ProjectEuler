#ifndef STATS_H__
#define STATS_H__

#include <chrono>

class TimeStats
{
	std::chrono::time_point<std::chrono::high_resolution_clock> __start;
	std::chrono::time_point<std::chrono::high_resolution_clock> __end;
public:
	TimeStats()
	{
		__start = std::chrono::high_resolution_clock::now();
		__end = std::chrono::high_resolution_clock::now();
	}
	void tic()
	{
		__start = std::chrono::high_resolution_clock::now();
	}
	void toc()
	{
		__end = std::chrono::high_resolution_clock::now();
	}
	long long milliseconds() const
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(__end-__start).count();
	}
};

#endif