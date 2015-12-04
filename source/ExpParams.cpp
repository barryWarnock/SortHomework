#include "../headers/ExpParams.h"

ExpParams::ExpParams() {
	sortTypeVector.push_back(SHELL);
	rangeMin = 0;
	rangeMax = 5;
	genMethod = RANDOM;
	ascending = true;
	sortType = SHELL;
	gapVector.push_back(1);
	nVector.push_back(10000);
	gapType = SHELL_GAP;
	gapTypeVector.push_back(SHELL_GAP);
	hybridThreshold = 16;
	thresholdVector.push_back(16);
	logMemory = false;
}

ExpParams::ExpParams(const ExpParams &other) {
	sortTypeVector = other.sortTypeVector;
	rangeMin = other.rangeMin;
	rangeMax = other.rangeMax;
	genMethod = other.genMethod;
	ascending = other.ascending;
	sortType = other.sortType;
	gapVector = other.gapVector;
	nVector = other.nVector;
	gapType = other.gapType;
	gapTypeVector = other.gapTypeVector;
	logMemory = other.logMemory;
	hybridThreshold = other.hybridThreshold;
	thresholdVector = other.thresholdVector;
}