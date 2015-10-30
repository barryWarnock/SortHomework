#include "../headers/SortParams.h"
SortParams::SortParams() {
	sortType = SHELL;
	ascending = true;
	gapVector.push_back(1);
	gapType = LAZARUS_GAP;
}
