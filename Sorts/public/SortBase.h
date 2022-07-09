#pragma once
#include <string>

struct SortResult;
class SortTarget;

// Inherits class must be registered in SortManager manually
class SortBase
{
public:
	SortBase() {};

	virtual void SortCycle(SortTarget* target,SortResult &result) = 0;

	std::string SortName;
};