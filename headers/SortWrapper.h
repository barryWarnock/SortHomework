#pragma once
#include "SortParams.h"
#include <vector>
using namespace std;

class SortWrapper {
public:
	//takes a vector to sort and a SortParams parameter object and uses the apropriate sort class to sort the vector
	void sort(vector<int> &vectorToSort, SortParams params);
};