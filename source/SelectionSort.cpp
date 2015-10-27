#include "../headers/SelectionSort.h"
#include "../headers/MemoryTracker.h"
#include <algorithm>

void SelectionSort::sort(vector<int>& vectorToSort, SortParams params)
{
	int nextPosition = 0;
	while (nextPosition < vectorToSort.size()) {
		int minElement = nextPosition;
		for (int i = nextPosition; i < vectorToSort.size(); i++) {
			if (compare(vectorToSort[minElement], vectorToSort[i], params.ascending)) {
				minElement = i;
			}
		}
		std::swap(vectorToSort[nextPosition], vectorToSort[minElement]);
		nextPosition++;
	}
	MemoryTracker::save_memory();
}
