#include "../headers/QuickSort.h"
#include "../headers/MemoryTracker.h"
#include "../headers/SortWrapper.h"
#include <algorithm>

int QuickSort::find_pivot(vector<int> &vectorToSort, int begining, int end) {
	int first = vectorToSort[begining];
	int middle = vectorToSort[begining + ((end - begining) / 2)];
	int last = vectorToSort[end];

	vector<int> possiblePivots= {first, middle, last};
	SortParams params;
	SortWrapper sortFascade;
	sortFascade.sort(possiblePivots, params);
	return possiblePivots[1];
}

void QuickSort::sort(vector<int> &vectorToSort, SortParams params, int begining, int end) {
	if (begining + 1 < end) {
		int pivot = find_pivot(vectorToSort, begining, end);

		int i = begining;
		int j = end;
		bool partitioned = false;
		while (!partitioned) {

			while (compare(pivot, vectorToSort[i], params.ascending)) {
				i++;
			}

			while (compare(vectorToSort[j], pivot, params.ascending)) {
				j--;
			}

			if (i < j) {
				std::swap(vectorToSort[i], vectorToSort[j]);
				i++;
				j++;
			}
			else {
				partitioned = true;
			}
		}

		if (j < end) {
			sort(vectorToSort, params, begining, j);
		}
		if (j+1 > begining) {
			sort(vectorToSort, params, j + 1, end);
		}
	}
	MemoryTracker::save_memory();
}

void QuickSort::sort(vector<int>& vectorToSort, SortParams params) {
	sort(vectorToSort, params, 0, vectorToSort.size() - 1);
	MemoryTracker::save_memory();
}
