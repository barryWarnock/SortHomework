#pragma once
#ifndef SORTPARAMS_H
#define SORTPARAMS_H
#include <vector>
using namespace std;
enum SortType {
	SELECTION = 1,
	INSERTION = 2,
	SHELL = 3,
	QUICK = 4,
	MERGE = 5,
	HYBRID_QUICK = 6,
	HYBRID_MERGE = 7
};

/**
names are all based off the authors names from this table:
https://en.wikipedia.org/wiki/Shellsort#Gap_sequences
*/
enum GapType
{
	SHELL_GAP = 1,
	HIBBARD_GAP = 2,
	LAZARUS_GAP = 3,
	CUSTOM = 4
};

//I made SortParam a struct with no setters/getters
struct SortParams {
	//the type of sort to use
	SortType sortType;
	//true if the vector should be sorted in ascending order
	bool ascending;
	//a list of gaps to use if gapType is CUSTOM and sortType is SHELL
	vector<int> gapVector;
	//the function to use to generate gaps or CUSTOM to use your own gap vector
	GapType gapType;
	int hybridThreshold;
	//sets all values to values that will "work" with sort functions
	SortParams();
	SortParams(const SortParams &other);
};
#endif