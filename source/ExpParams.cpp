#include "../headers/ExpParams.h"

ExpParams::ExpParams() {
	rangeMin = 0;
	rangeMax = 5;
	genMethod = RANDOM;
	ascending = true;
	sortType = SHELL;
	gapVector.push_back(1);
	nVector.push_back(10000);
	gapType = SHELL_GAP;
	gapTypeVector.push_back(SHELL_GAP);
	logMemory = false;
}