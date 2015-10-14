#include "../headers/SelectionSort.h"
#include <algorithm>
using namespace std;

void SelectionSort::sort(int arrayToSort[], int arrayLength, bool ascending)
{
	int nextPosition = 0;
	while (nextPosition < arrayLength) {
		int minElement = nextPosition;
		for (int i = nextPosition; i < arrayLength; i++) {
			if (compare(arrayToSort[minElement], arrayToSort[i], ascending)) {
				minElement = i;
			}
		}
		std::swap(arrayToSort[nextPosition], arrayToSort[minElement]);
		nextPosition++;
	}
}
