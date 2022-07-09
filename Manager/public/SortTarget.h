#pragma once
#include <vector>
#include <string>

class SortTarget
{
private:
	SortTarget() {};
	SortTarget(const SortTarget& copy) {};
public:
	SortTarget(int Count, bool random);

	bool IsSorted();
	std::string GetArray();

	std::vector<int> TargetArray;

private:
	void InitializeRandomArray(int Count);
};

