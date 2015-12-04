#pragma once
#ifndef MERGESORT_H
#define MERGESORT_H

#include "Sort.h"
class MergeSort : public Sort {
	friend class MergeSortTests;
protected:
	void split(vector<int> &original, vector<int> &left, vector<int> &right);
	void merge(vector<int> &mergeInto, vector<int> &left, vector<int> &right, SortParams params);
public:
	// Inherited via Sort
	virtual void sort(vector<int> &vectorToSort, SortParams params) override;
};

#endif