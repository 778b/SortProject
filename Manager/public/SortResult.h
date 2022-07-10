#pragma once
#include <chrono>

struct SortResult
{
	std::chrono::time_point<std::chrono::steady_clock> StartTime;
	std::chrono::time_point<std::chrono::steady_clock> EndTime;
	unsigned __int64 Moves = 0;
};