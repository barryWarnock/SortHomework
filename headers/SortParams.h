#pragma once
#include <vector>
using namespace std;
enum SortType {
	SELECTION = 1,
	INSERTION = 2,
	SHELL = 3,
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
	SortType sortType;
	bool ascending;
	vector<int> gapVector;
	GapType gapType;
	//sets all values to values that will "work" with sort functions
	SortParams();
};