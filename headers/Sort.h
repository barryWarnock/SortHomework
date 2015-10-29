#pragma once
#include <vector>
#include "../headers/SortParams.h"
using namespace std;
class Sort {
protected:
	/**
	if ascending compare functions as >
	if descending compare functions as <
	*/
	bool compare(int first, int second, bool ascending);
public:
	/**

	*/
	virtual void sort(vector<int> &vectorToSort, SortParams params) = 0;
};
