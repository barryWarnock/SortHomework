#include "../headers/SortWrapper.h"
#include "../headers/Sort.h"
#include "../headers/InsertionSort.h"
#include "../headers/SelectionSort.h"
#include "../headers/ShellSort.h"
#include "../headers/QuickSort.h"
#include "../headers/MergeSort.h"
#include "../headers/HybridMergeSort.h"
#include <cstdlib>

#include "../headers/MemoryTracker.h"
#include <iostream>
using namespace std;

void SortWrapper::sort(vector<int> &vectorToSort, SortParams params) {
	Sort *selectedSort = NULL;
	switch (params.sortType)
	{
	case SELECTION:
		selectedSort = new(SelectionSort);
		break;
	case INSERTION:
		selectedSort = new(InsertionSort);
		break;
	case SHELL:
		selectedSort = new(ShellSort);
		break;
	case QUICK:
		selectedSort = new(QuickSort);
		break;
	case MERGE:
		selectedSort = new(MergeSort);
		break;
	case HYBRID_MERGE:
		selectedSort = new(HybridMergeSort);
		break;
	default:
		selectedSort = new(QuickSort);
	}

	selectedSort->sort(vectorToSort, params);
	delete selectedSort;
}
