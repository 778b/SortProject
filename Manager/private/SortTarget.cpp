#include "../public/SortTarget.h"

#include <cstdlib>
#include <ctime>


SortTarget::SortTarget(int Count, bool random)
{
	TargetArray.reserve(Count);
	if (random)
	{
		InitializeRandomArray(Count);
	}
}

SortTarget::SortTarget(std::string StringArray)
{
	std::string symbol = "";

	for (int i = 0; i < StringArray.length(); ++i)
	{
		if (StringArray[i] >= '0' && StringArray[i] <= '9')
		{
			symbol += StringArray[i];
		}
		else
		{
			if (symbol.length() > 0) TargetArray.push_back(std::stoi(symbol));
			symbol = "";
		}
	}
}

bool SortTarget::IsSorted()
{
	for (size_t i = 0; i < TargetArray.size(); ++i)
	{
		if (i < TargetArray.size() - 1)
		{
			if (TargetArray[i] > TargetArray[i + 1]) return false;
		}
		else return true;
	}
	return true; // zeroed = sorted :)
}

std::string SortTarget::GetArray()
{
	std::string result = "";
	for (auto& temp : TargetArray)
	{
		result += std::to_string(temp) + ' ';
	}
	return result;
}


void SortTarget::InitializeRandomArray(int Count)
{
	srand(static_cast<unsigned int>(time(0)));

	for (int i = 0; i < Count; ++i)
	{
		TargetArray.push_back(rand()%20);
	}
}

