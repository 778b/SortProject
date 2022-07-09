#pragma once
#include <vector>
#include <string>

class SortBase;

class SortFactory
{
public:
	SortFactory();

	virtual ~SortFactory()
	{
		DeleteAllSort();
	}
	SortBase* GetSort(int index);
	size_t GetSortCount();

	void RegisterAllSort();

	void GetNamesAllSorts(std::vector<std::string>& Listtemp);

private:
	std::vector<SortBase*> RegisteredSort;

	bool CheckSortForAdd(SortBase* sort);

	void DeleteAllSort();
};