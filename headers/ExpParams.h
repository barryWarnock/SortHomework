#pragma once
#include "SortParams.h"
#include <vector>
using namespace std;

enum GenerationMethod {
	RANDOM,
	SORTED,
	SORTED_REVERSE,
	RANDOM_IN_RANGE
};

struct ExpParams : public SortParams {
	vector<int> nVector;
	GenerationMethod genMethod;
	int rangeMin;
	int rangeMax;
	GapType gapType;
	vector<GapType> gapTypeVector;
	bool logMemory;
	ExpParams();
};