#pragma once
#include "Sort.h"
template <typename T>
class SelectionSort : public Sort<T> {
public:
	// Inherited via Sort
	virtual vector<T> sort(vector<T> vectorToSort, SortParams params) override;
};