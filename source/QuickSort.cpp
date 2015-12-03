#include "../headers/QuickSort.h"
#include "../headers/MemoryTracker.h"
#include "../headers/SortWrapper.h"
#include <algorithm>

int QuickSort::find_pivot(vector<int> &vectorToSort, int begining, int end) {
	int first = vectorToSort[begining];
	int middle = vectorToSort[begining + ((end - begining) / 2)];
	int last = vectorToSort[end];

	if (first <= middle && first >= last || first >= middle && first <= last) {
		return first;
	}
	if (middle <= first && middle >= last || middle >= first && middle <= last) {
		return middle;
	}
	if (last <= middle && last >= first || last >= middle && last <= first) {
		return last;
	}
}

void QuickSort::sort(vector<int> &vectorToSort, SortParams params, int begining, int end) {
	if (begining < end) {
		int pivot = find_pivot(vectorToSort, begining, end);

		int i = begining;
		int j = end;

		while (i <= j) {

			while (compare(pivot, vectorToSort[i], params.ascending)) {
				i++;
			} 

			while (compare(vectorToSort[j], pivot, params.ascending)) {
				j--;
			} 

			if (i <= j) {
				std::swap(vectorToSort[i], vectorToSort[j]);
				i++;
				j--;
			}
		}

		sort(vectorToSort, params, begining, j);
		sort(vectorToSort, params, i, end);
	}
	MemoryTracker::save_memory();
}

void QuickSort::sort(vector<int>& vectorToSort, SortParams params) {
	sort(vectorToSort, params, 0, vectorToSort.size() - 1);
	MemoryTracker::save_memory();
}
