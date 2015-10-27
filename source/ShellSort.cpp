#include "../headers/ShellSort.h"
#include "../headers/InsertionSort.h"
#include "../headers/MemoryTracker.h"
#include <iostream>

vector<int> ShellSort::generate_shell_gaps(int maxGap) {
	vector<int> gaps;
	gaps.push_back(1);
	gaps.push_back(5);
	gaps.push_back(16);
	SortParams params;
	params.ascending = false;
	InsertionSort gapSort;
	gapSort.sort(gaps, params);
	return gaps;
}

vector<int> ShellSort::generate_hibbard_gaps(int maxGap) {
	vector<int> gaps;
	gaps.push_back(1);
	gaps.push_back(5);
	gaps.push_back(16);
	SortParams params;
	params.ascending = false;
	InsertionSort gapSort;
	gapSort.sort(gaps, params);
	return gaps;
}

vector<int> ShellSort::generate_lazarus_gaps(int maxGap) {
	vector<int> gaps;
	gaps.push_back(1);
	gaps.push_back(5);
	gaps.push_back(16);
	SortParams params;
	params.ascending = false;
	InsertionSort gapSort;
	gapSort.sort(gaps, params);
	return gaps;
}

void ShellSort::sort(vector<int> &vectorToSort, SortParams params) {
	vector<int> gaps;
	switch (params.gapType) {
	case SHELL_GAP:
		gaps = generate_shell_gaps(vectorToSort.size());
		break;
	case HIBBARD_GAP:
		gaps = generate_hibbard_gaps(vectorToSort.size());
		break;
	case LAZARUS_GAP:
		gaps = generate_lazarus_gaps(vectorToSort.size());
		break;
	case CUSTOM:
	default:
		gaps = params.gapVector;
		break;
	}
	for (int k = 0; k < gaps.size(); k++) {
		int gap = gaps[k];
		for (int i = gap; i < vectorToSort.size(); i++) {
			int val = vectorToSort[i];
			int j = i - gap;
			while (j >= 0 && compare(vectorToSort[j], val, params.ascending)) {
				vectorToSort[j + gap] = vectorToSort[j];
				j -= gap;
			}
			vectorToSort[j + gap] = val;
		}
	}
	MemoryTracker::save_memory();
}
