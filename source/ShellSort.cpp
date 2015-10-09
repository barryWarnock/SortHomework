#include "ShellSort.h"
#include "InsertionSort.h"
#include <iostream>

void ShellSort::generate_shell_gaps(int maxGap) {
	delete[] gapArray;
	gapArray = new(int[3]);
	gapArray[0] = 1;
	gapArray[1] = 5;
	gapArray[2] = 16;
	numGaps = 3;
	InsertionSort gapSort;
	gapSort.sort(gapArray, numGaps, false);
}
void ShellSort::generate_hibbard_gaps(int maxGap) {
	delete[] gapArray;
	gapArray = new(int[1]);
	gapArray[0] = 1;
	numGaps = 1;
}
void ShellSort::generate_lazarus_gaps(int maxGap) {
	delete[] gapArray;
	gapArray = new(int[1]);
	gapArray[0] = 1;
	numGaps = 1;
}

ShellSort::ShellSort() {
	gapArray = new(int[1]);
	gapArray[0] = 1;
	numGaps = 1;
}

void ShellSort::sort(int arrayToSort[], int arrayLength, bool ascending) {
	sort(arrayToSort, arrayLength, ascending, SHELL_GAP);
}

void ShellSort::sort(int arrayToSort[], int arrayLength, bool ascending, GapType gapAlgorithm) {
	switch (gapAlgorithm) {
	case SHELL_GAP:
		generate_shell_gaps(arrayLength);
		break;
	case HIBBARD_GAP:
		generate_hibbard_gaps(arrayLength);
		break;
	case LAZARUS_GAP:
		generate_lazarus_gaps(arrayLength);
		break;
	}
	for (int k = 0; k < numGaps; k++) {
		int gap = gapArray[k];
		for (int i = gap; i < arrayLength; i++) {
			int val = arrayToSort[i];
			int j = i - gap;
			while (j >= 0 && compare(arrayToSort[j], val, ascending)) {
				arrayToSort[j + gap] = arrayToSort[j];
				j -= gap;
			}
			arrayToSort[j + gap] = val;
		}
	}
}

ShellSort::~ShellSort() {
	delete[] gapArray;
	gapArray = NULL;
}