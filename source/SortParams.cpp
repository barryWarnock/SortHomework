#include "../headers/SortParams.h"
SortParams::SortParams() {
	sortType = SHELL;
	ascending = true;
	gapVector.push_back(1);
	gapType = LAZARUS_GAP;
	hybridThreshold = 16;
}

SortParams::SortParams(const SortParams &other) {
	ascending = other.ascending;
	sortType = other.sortType;
	gapVector = other.gapVector;
	gapType = other.gapType;
	hybridThreshold = other.hybridThreshold;
}