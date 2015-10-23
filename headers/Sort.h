#pragma once
#include <vector>
#include "../headers/SortParams.h"
using namespace std;
template <typename T>
class Sort {
protected:
	/**
	if ascending compare functions as >, false otherwise
	if decending compare functions as <, false otherwise
	*/
	bool compare(T first, T second, bool ascending);
public:
	/**

	*/
	virtual vector<T> sort(vector<T> vectorToSort, SortParams params) = 0;
};