#include "../headers/ExperimentIO.h"
#include <fstream>
#include <vector>
#include <sstream>

ExpParams ExperimentIO::load_experiment(string path) {
	ifstream fileIn;
	fileIn.open(path);
	if (!fileIn.is_open()) {
		throw exception();
	}
	string nStart, nIncrement, nStop, generationMethod, rangeMin, rangeMax, sortType, ascending, gapType, gapSequence;
	rangeMin = "0";
	rangeMax = "0";
	gapSequence = "1";
	vector<int> nVector;
	vector<int> gapVector;
	fileIn >> nStart;
	fileIn >> nIncrement;
	fileIn >> nStop;
	fileIn >> generationMethod;
	if (generationMethod == "RANDOM_IN_RANGE") {
		fileIn >> rangeMin;
		fileIn >> rangeMax;
	}
	fileIn >> sortType;
	fileIn >> ascending;
	fileIn >> gapType;
	if (gapType == "CUSTOM") {
		fileIn >> gapSequence;
	}
	int nStartNum, nIncrementNum, nStopNum;
	istringstream(nStart) >> nStartNum;
	istringstream(nIncrement) >> nIncrementNum;
	istringstream(nStop) >> nStopNum;
	string numStr = "";
	for (int i = nStartNum; i <= nStopNum; i += nIncrementNum) {
		nVector.push_back(i);
	}
	
	GenerationMethod genMethod;
	if (generationMethod == "RANDOM") {
		genMethod = RANDOM;
	}
	else if (generationMethod == "SORTED") {
		genMethod = SORTED;
	}
	else if (generationMethod == "SORTED_REVERSE") {
		genMethod = SORTED_REVERSE;
	}
	else if (generationMethod == "RANDOM_IN_RANGE") {
		genMethod = RANDOM_IN_RANGE;
	}
	
	int minNum, maxNum;
	istringstream(rangeMin) >> minNum;
	istringstream(rangeMax) >> maxNum;
	
	bool isAscending;
	istringstream(ascending) >> isAscending;
	
	SortType selectedSortType;
	if (sortType == "INSERTION") {
		selectedSortType = INSERTION;
	}
	else if (sortType == "SELECTION") {
		selectedSortType = SELECTION;
	}
	else if (sortType == "SHELL") {
		selectedSortType = SHELL;
	}

	numStr = "";
	for (int i = 0; i < gapSequence.size(); i++) {
		//I don't care about whitespace
		if (gapSequence[i] != ' ') {
			if (gapSequence[i] == ',') {
				int tempNum;
				istringstream(numStr) >> tempNum;
				gapVector.push_back(tempNum);
				numStr = "";
			}
			else {
				numStr += gapSequence[i];
			}
		}
	}

	GapType selectedGapType;
	if (gapType == "CUSTOM") {
		selectedGapType = CUSTOM;
	}
	else if (gapType == "") {
		selectedGapType = SHELL_GAP;
	}
	else if (gapType == "HIBBARD") {
		selectedGapType = HIBBARD_GAP;
	}
	else if (gapType == "LAZARUS") {
		selectedGapType = LAZARUS_GAP;
	}

	fileIn.close();

	ExpParams returnParams;
	returnParams.nVector = nVector;
	returnParams.genMethod = genMethod;
	returnParams.rangeMin = minNum;
	returnParams.rangeMax = maxNum;
	returnParams.ascending = isAscending;
	returnParams.sortType = selectedSortType;
	returnParams.gapVector = gapVector;
	returnParams.gapType = selectedGapType;
	return returnParams;
}

void ExperimentIO::save_results(map<int, int> averageTimes, string filename) {
	ofstream fileOut;
	fileOut.open("experiment_logs/"+filename+".csv");
	fileOut << "n,ticks" << endl;
	for (map<int, int>::iterator it = averageTimes.begin(); it != averageTimes.end(); it++) {
		fileOut << it->first << "," << it->second << endl;
	}
	fileOut.close();
}