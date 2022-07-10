#include "../public/RifleSort.h"
#include <ctime>
#include <cstdlib>
#include "../../Manager/public/SortResult.h"
#include "../../Manager/public/SortTarget.h"

void RifleSort::SortCycle(SortTarget* target, SortResult& result)
{
	result.StartTime = std::chrono::high_resolution_clock::now();
	srand(time(NULL));
	int index1, index2;
	int ArrSize = target->TargetArray.size();

	int _temp;
	while (!target->IsSorted())
	{
		index1 = rand() % ArrSize;
		index2 = rand() % ArrSize;
		if (index1 == index2)
		{
			if (index2 == ArrSize - 1) --index2;
			else ++index2;
		}

		_temp = target->TargetArray[index1];
		target->TargetArray[index1] = target->TargetArray[index2];
		target->TargetArray[index2] = _temp;
		++result.Moves;
	}

	result.EndTime = std::chrono::high_resolution_clock::now();
	return;
}
