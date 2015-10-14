#include "../headers/InsertionSort.h"
#include <iostream>
using namespace std;

void InsertionSort::sort(int arrayToSort[], int arrayLength, bool ascending) {
	sort(arrayToSort, arrayLength, ascending, 1);
}

void InsertionSort::sort(int arrayToSort[], int arrayLength, bool ascending, int gapSize)
{
	for (int i = 0; i < arrayLength; i++) {
		int val = arrayToSort[i];
		int j = i - 1;
		while (j >= 0 && compare(arrayToSort[j], val, ascending)) {
			arrayToSort[j + 1] = arrayToSort[j];
			j--;
		}
		arrayToSort[j+1] = val;
	}
}
