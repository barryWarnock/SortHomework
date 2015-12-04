#include "../headers/HybridQuickSort.h"
#include "../headers/SortWrapper.h"

void HybridQuickSort::sort(vector<int> &vectorToSort, SortParams params) {
	if (vectorToSort.size() > params.hybridThreshold) {
		sort(vectorToSort, params, 0, vectorToSort.size() - 1);
	}
	else {
		SortWrapper sortFascade;
		params.sortType = INSERTION;
		sortFascade.sort(vectorToSort, params);
	}
}

void HybridQuickSort::sort(vector<int> &vectorToSort, SortParams params, int begining, int end) {
	if (end-begining > params.hybridThreshold) {
		int pivot = find_pivot(vectorToSort, begining, end);

		int i = partition(vectorToSort, begining, end, pivot, params);

		sort(vectorToSort, params, begining, i - 1);
		sort(vectorToSort, params, i, end);
	}
	else {
		vector<int> subVector;
		for (int i = begining; i <= end; i++) {
			subVector.push_back(vectorToSort[i]);
		}

		SortWrapper sortFascade;
		params.sortType = INSERTION;
		sortFascade.sort(subVector, params);

		for (int i = begining; i <= end; i++) {
			vectorToSort[i] = subVector[0-begining+i];
		}
	}
}