#pragma once
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "Sort.h"
class QuickSort : public Sort {
	//friend class SelectionSortTests;
protected:
	int find_pivot(vector<int> &vectorToSort, int begining, int end);
	int partition(vector<int> &vectorToSort, int begining, int end, int pivot, SortParams params);
public:
	// Inherited via Sort
	virtual void sort(vector<int> &vectorToSort, SortParams params) override;
	void sort(vector<int> &vectorToSort, SortParams params, int begining, int end);
};
#endif