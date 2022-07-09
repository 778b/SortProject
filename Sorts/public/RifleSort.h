#pragma once
#include "SortBase.h"

struct SortResult;
class SortTarget;

class RifleSort : public SortBase
{
public:
	RifleSort()
	{
		SortName = "RifleMethod";
	}

	void SortCycle(SortTarget* target, SortResult& result) override;
};

