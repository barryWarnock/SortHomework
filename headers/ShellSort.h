#pragma once
#include "Sort.h"
#include <vector>
using namespace std;

template <typename T>
class ShellSort: public Sort<T>
{
protected:
	vector<int> generate_shell_gaps(int maxGap);
	vector<int> generate_hibbard_gaps(int maxGap);
	vector<int> generate_lazarus_gaps(int maxGap);
public:
	// Inherited via Sort
	virtual vector<T> sort(vector<T> vectorToSort, SortParams params) override;
};

