#pragma once
#include "Sort.h"
#include "ShellSortTests.h"
#include <vector>
using namespace std;

class ShellSort: public Sort
{
friend class ShellSortTests;
protected:
	//all of these are from the wikipedia page on shell sort
	vector<int> generate_shell_gaps(int maxGap);
	vector<int> generate_hibbard_gaps(int maxGap);
	vector<int> generate_lazarus_gaps(int maxGap);
public:
	// Inherited via Sort
	virtual void sort(vector<int> &vectorToSort, SortParams params) override;
};

