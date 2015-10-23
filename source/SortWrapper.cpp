#include "../headers/SortWrapper.h"
#include "../headers/Sort.h"
#include "../headers/InsertionSort.h"
#include "../headers/SelectionSort.h"
#include "../headers/ShellSort.h"

template <typename T>
vector<T> SortWrapper::sort(vector<T> vectorToSort, SortParams params) {
	Sort *selectedSort = NULL;
	switch (params.sortType)
	{
	case SELECTION:
		selectedSort = new(SelectionSort<T>);
		break;
	case INSERTION:
		selectedSort = new(InsertionSort<T>);
		break;
	case SHELL:
		selectedSort = new(ShellSort<T>);
		break;
	}
	vector<T> returnVector;
	if (selectedSort != NULL) {
		returnVector = selectedSort->sort(vectorToSort, params);
		delete selectedSort;
	}
	return returnVector;
}
