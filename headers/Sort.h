#pragma once
#include <vector>
#include "../headers/SortParams.h"
using namespace std;
class Sort {
protected:
	/**
	if ascending compare functions as >, false otherwise
	if decending compare functions as <, false otherwise
	*/
	bool compare(int first, int second, bool ascending);
public:
	/**

	*/
	virtual void sort(vector<int> &vectorToSort, SortParams params) = 0;
};