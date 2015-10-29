#include "../headers/ShellSort.h"
#include "../headers/MemoryTracker.h"
#include <iostream>
#include <math.h>

vector<int> ShellSort::generate_shell_gaps(int n) {
	vector<int> gaps;
	int k = 1;
	int nextGap = 5;
	while (nextGap > 1) {
        nextGap = n/(pow(2, k));
        k++;
        if (nextGap > 1) {
            gaps.push_back(nextGap);
        }
	}
	gaps.push_back(1);
	return gaps;
}

vector<int> ShellSort::generate_hibbard_gaps(int n) {
	vector<int> gaps;
	int k = 1;
	int nextGap = 1;
	while (nextGap < n) {
        nextGap = (pow(2, k) -1);
        k++;
        if (nextGap < n) {
            gaps.push_back(nextGap);
        }
	}
	SortParams params;
	params.ascending = false;
	//we can use shell sort here because the default gap sequence is SHELL_GAP
	ShellSort gapSort;
	gapSort.sort(gaps, params);
	return gaps;
}

vector<int> ShellSort::generate_lazarus_gaps(int n) {
	vector<int> gaps;
	int k = 1;
    int nextGap = 2;
    while (nextGap > 1) {
        nextGap = (2*(n/pow(2, k+1))) + 1;
        k++;
        if (nextGap > 1) {
            gaps.push_back(nextGap);
        }
    }
    gaps.push_back(1);
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
