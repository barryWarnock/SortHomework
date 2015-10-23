#pragma once
#include "SortParams.h"
#include <vector>
using namespace std;

class SortWrapper {
public:
	template <typename T>
	vector<T> sort(vector<T> vectorToSort, SortParams params);
};