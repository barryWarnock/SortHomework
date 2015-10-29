#pragma once
#include "Sort.h"
#include "InsertionSortTests.h"
class InsertionSort : public Sort {
    friend class InsertionSortTests;
public:
	// Inherited via Sort
	virtual void sort(vector<int> &vectorToSort, SortParams params) override;
};
