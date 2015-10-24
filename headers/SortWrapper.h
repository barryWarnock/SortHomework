#pragma once
#include "SortParams.h"
#include <vector>
using namespace std;

class SortWrapper {
public:
	void sort(vector<int> &vectorToSort, SortParams params);
};