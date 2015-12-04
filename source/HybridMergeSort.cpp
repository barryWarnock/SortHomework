#include "../headers/HybridMergeSort.h"
#include "../headers/SortWrapper.h"
#include "../headers/MemoryTracker.h"

void HybridMergeSort::sort(vector<int> &vectorToSort, SortParams params) {
	if (vectorToSort.size() > params.hybridThreshold) {
		vector<int> left, right;
		split(vectorToSort, left, right);
		sort(left, params);
		sort(right, params);
		merge(vectorToSort, left, right, params);
		MemoryTracker::save_memory();
	}
	else {
		SortWrapper sortFascade;
		params.sortType = INSERTION;
		sortFascade.sort(vectorToSort, params);
		MemoryTracker::save_memory();
	}
}