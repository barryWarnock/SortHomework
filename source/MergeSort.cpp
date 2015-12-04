#include "../headers/MergeSort.h"
#include "../headers/MemoryTracker.h"

void MergeSort::split(vector<int> &original, vector<int> &left, vector<int> &right) {
	int i;
	for (i = 0; i < original.size() / 2; i++) {
		left.push_back(original[i]);
	}
	for (; i < original.size(); i++) {
		right.push_back(original[i]);
	}
}

void MergeSort::merge(vector<int> &mergeInto, vector<int> &left, vector<int> &right, SortParams params) {
	int i = 0;
	int j = 0;
	for (int k = 0; k < mergeInto.size(); k++) {
		if (i >= left.size()) {
			for (; k < mergeInto.size() && j < right.size(); k++) {
				mergeInto[k] = right[j];
				j++;
			}
			break;
		}
		else if (j >= right.size()) {
			for (; k < mergeInto.size() && i < left.size(); k++) {
				mergeInto[k] = left[i];
				i++;
			}
			break;
		}
		else if (compare(right[j], left[i], params.ascending)) {
			mergeInto[k] = left[i];
			i++;
		}
		else {
			mergeInto[k] = right[j];
			j++;
		}
	}
}

void MergeSort::sort(vector<int> &vectorToSort, SortParams params) {
	if (vectorToSort.size() > 1) {
		vector<int> left, right;
		split(vectorToSort, left, right);
		sort(left, params);
		sort(right, params);
		merge(vectorToSort, left, right, params);
		MemoryTracker::save_memory();
	}
}
