#pragma once
#include "../public/SortBase.h"

class SortTarget;
struct SortResult;

class BubbleSort : public SortBase
{
public:
	BubbleSort()
	{
		SortName = "BubbleMethod";
	}

	void SortCycle(SortTarget* target, SortResult& result) override;
};

