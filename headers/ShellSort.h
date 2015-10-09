#pragma once
#include "Sort.h"

/**
names are all based off the authors names from this table:
https://en.wikipedia.org/wiki/Shellsort#Gap_sequences
*/
enum GapType
{
	SHELL_GAP,
	HIBBARD_GAP,
	LAZARUS_GAP
};

class ShellSort: public Sort
{
protected:
	int* gapArray;
	int numGaps;
	void generate_shell_gaps(int maxGap);
	void generate_hibbard_gaps(int maxGap);
	void generate_lazarus_gaps(int maxGap);
public:
	/**
	the constructor sets gap array to be [1] so that if somehow a gap does not get set
	the sort will still run with gap 1
	*/
	ShellSort();
	// Inherited via Sort
	virtual void sort(int arrayToSort[], int arrayLength, bool ascending) override;
	void sort(int arrayToSort[], int arrayLength, bool ascending, GapType gapAlgorithm);
	/**
	frees the memory allocated for the gap array
	*/
	~ShellSort();
};

