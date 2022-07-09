#include "../public/SortFactory.h"
#include "../../Sorts/public/SortBase.h"

//Sort List
#include "../../Sorts/public/RifleSort.h"



SortFactory::SortFactory()
{
}

SortBase* SortFactory::GetSort(int index)
{
	return RegisteredSort[index];
}

size_t SortFactory::GetSortCount()
{
	return RegisteredSort.size();
}

void SortFactory::RegisterAllSort()
{
	CheckSortForAdd(new RifleSort());



}

bool SortFactory::CheckSortForAdd(SortBase* sort)
{										
	if (sort->SortName.size() > 0)
	{																			
		RegisteredSort.push_back(sort);
		return true;
	}																			
	else
	{
		delete sort;
		return false;
	}
}

void SortFactory::DeleteAllSort()
{
	for (auto Sorts : RegisteredSort)
	{
		delete Sorts;
	}
	RegisteredSort.clear();
}


void SortFactory::GetNamesAllSorts(std::vector<std::string>& Listtemp)
{
	for (auto sort : RegisteredSort)
	{
		Listtemp.push_back(sort->SortName);
	}
}

