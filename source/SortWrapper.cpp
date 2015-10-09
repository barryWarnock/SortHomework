#include "SortWrapper.h"
#include "Sort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "ShellSort.h"
#include <iostream>

void SortWrapper::sort(int arrayToSort[], int arrayLength, bool ascending, SortType algorithm) {
	Sort *selectedSort = NULL;
	switch (algorithm)
	{
	case SELECTION:
		selectedSort = &SelectionSort();
		break;
	case INSERTION:
		selectedSort = &InsertionSort();
		break;
	case SHELL:
		selectedSort = &ShellSort();
		break;
	default:
		break;
	}
	if (selectedSort != NULL) {
		selectedSort->sort(arrayToSort, arrayLength, ascending);
	}
}