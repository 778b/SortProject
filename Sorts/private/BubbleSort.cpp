#include "../../Sorts/public/BubbleSort.h"

#include "../../Manager/public/SortResult.h"
#include "../../Manager/public/SortTarget.h"

void BubbleSort::SortCycle(SortTarget* target, SortResult& result)
{
	
	result.StartTime = std::chrono::high_resolution_clock::now();
	int _temp;
	
	for (int i = 0; i < target->TargetArray.size(); ++i)
	{
		for (int j = 0; j < target->TargetArray.size() - 1; ++j)
		{
			if (target->TargetArray[j] > target->TargetArray[j + 1])
			{
				_temp = target->TargetArray[j];
				target->TargetArray[j] = target->TargetArray[j+1];
				target->TargetArray[j+1] = _temp;
				++result.Moves;
			}
		}
	}

	result.EndTime = std::chrono::high_resolution_clock::now();
}
