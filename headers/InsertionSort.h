#pragma once
#include "Sort.h"
class InsertionSort : public Sort {
public:
	// Inherited via Sort
	virtual void sort(vector<int> &vectorToSort, SortParams params) override;
	void sort(int arrayToSort[], int arrayLength, bool ascending, int gap);
};