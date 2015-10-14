#include "../headers/SortWrapper.h"
#include "../headers/Sort.h"
#include "../headers/InsertionSort.h"
#include "../headers/SelectionSort.h"
#include "../headers/ShellSort.h"
#include <iostream>

void SortWrapper::sort(int arrayToSort[], int arrayLength, bool ascending, SortType algorithm) {
	Sort *selectedSort = NULL;
	switch (algorithm)
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
	}
	if (selectedSort != NULL) {
		selectedSort->sort(arrayToSort, arrayLength, ascending);
		delete selectedSort;
	}
}