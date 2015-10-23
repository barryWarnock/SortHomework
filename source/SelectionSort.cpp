#include "../headers/SelectionSort.h"
#include <algorithm>
using namespace std;

template <typename T>
vector<T> SelectionSort<T>::sort(vector<T> vectorToSort, SortParams params)
{
	int nextPosition = 0;
	while (nextPosition < vectorToSort.size()) {
		int minElement = nextPosition;
		for (int i = nextPosition; i < vectorToSort.size(); i++) {
			if (compare(vectorToSort[minElement], vectorToSort[i], ascending)) {
				minElement = i;
			}
		}
		std::swap(vectorToSort[nextPosition], vectorToSort[minElement]);
		nextPosition++;
	}
}
