#pragma once
#include "Sort.h"
template <typename T>
class InsertionSort : public Sort<T> {
public:
	// Inherited via Sort
	virtual vector<T> sort(vector<T> vectorToSort, SortParams params) override;
	void sort(int arrayToSort[], int arrayLength, bool ascending, int gap);
};