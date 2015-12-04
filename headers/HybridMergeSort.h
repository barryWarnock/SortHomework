#pragma once
#ifndef HYBRIDMERGESORT_H
#define HYBRIDMERGESORT_H

#include "MergeSort.h"

class HybridMergeSort : public MergeSort {
public:
	virtual void sort(vector<int> &vectorToSort, SortParams params) override;
};

#endif