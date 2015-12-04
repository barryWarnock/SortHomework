#pragma once
#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
#include "SelectionSortTests.h"
#include "Sort.h"
class SelectionSort : public Sort {
    friend class SelectionSortTests;
public:
	// Inherited via Sort
	virtual void sort(vector<int> &vectorToSort, SortParams params) override;
};
#endif