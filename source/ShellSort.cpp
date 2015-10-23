#include "../headers/ShellSort.h"
#include "../headers/InsertionSort.h"
#include <iostream>

template <typename T>
vector<int> ShellSort<T>::generate_shell_gaps(int maxGap) {
	vector<int> gaps;
	gaps.push_back(1);
	gaps.push_back(5);
	gaps.push_back(16);
	SortParams params;
	params.ascending = false;
	return gapSort.sort(gaps, params);
}

template <typename T>
vector<int> ShellSort<T>::generate_hibbard_gaps(int maxGap) {
	vector<int> gaps;
	gaps.push_back(1);
	gaps.push_back(5);
	gaps.push_back(16);
	SortParams params;
	params.ascending = false;
	return gapSort.sort(gaps, params);
}

template <typename T>
vector<int> ShellSort<T>::generate_lazarus_gaps(int maxGap) {
	vector<int> gaps;
	gaps.push_back(1);
	gaps.push_back(5);
	gaps.push_back(16);
	SortParams params;
	params.ascending = false;
	return gapSort.sort(gaps, params);
}

template <typename T>
vector<T> ShellSort<T>::sort(vector<T> vectorToSort, SortParams params) {
	vector<int> gaps;
	switch (params.gapType) {
	case SHELL_GAP:
		gaps = generate_shell_gaps(arrayLength);
		break;
	case HIBBARD_GAP:
		gaps = generate_hibbard_gaps(arrayLength);
		break;
	case LAZARUS_GAP:
		gaps = generate_lazarus_gaps(arrayLength);
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
			while (j >= 0 && compare(vectorToSort[j], val, ascending)) {
				vectorToSort[j + gap] = vectorToSort[j];
				j -= gap;
			}
			vectorToSort[j + gap] = val;
		}
	}
}
