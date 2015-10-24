#pragma once
#include "Sort.h"
#include <vector>
using namespace std;

class ShellSort: public Sort
{
protected:
	vector<int> generate_shell_gaps(int maxGap);
	vector<int> generate_hibbard_gaps(int maxGap);
	vector<int> generate_lazarus_gaps(int maxGap);
public:
	// Inherited via Sort
	virtual void sort(vector<int> &vectorToSort, SortParams params) override;
};

