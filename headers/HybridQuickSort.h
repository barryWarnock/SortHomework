#pragma once
#ifndef HYBRIDQUICKSORT_H
#define HYBRIDQUICKSORT_H

#include "QuickSort.h"

class HybridQuickSort : public QuickSort {
	friend class HybridQuickSortTests;
public:
	virtual void sort(vector<int> &vectorToSort, SortParams params) override;
	void sort(vector<int> &vectorToSort, SortParams params, int begining, int end);
};

#endif