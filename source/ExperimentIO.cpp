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
	string nStart, nIncrement, nStop, generationMethod, rangeMin, rangeMax, sortType, ascending, logMemory, gapType;
	rangeMin = "0";
	rangeMax = "0";
	vector<int> nVector;
	vector<GapType> gapVector;
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
	fileIn >> logMemory;
	fileIn >> gapType;
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
	
	bool isLogMemory;
	istringstream(logMemory) >> isLogMemory;

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

	
	if (gapType == "") {
		gapVector.push_back(SHELL_GAP);
	}
	else {
		string charBuffer = "";
		for (int i = 0; i < gapType.size(); i++) {
			//don't care about whitespace
			if (gapType[i] != ' ') {
				if (gapType[i] == ',') {
					if (charBuffer == "SHELL") {
						gapVector.push_back(SHELL_GAP);
					}
					else if (charBuffer == "HIBBARD") {
						gapVector.push_back(HIBBARD_GAP);
					}
					else if (charBuffer == "LAZARUS") {
						gapVector.push_back(LAZARUS_GAP);
					}
					charBuffer = "";
				}
				else {
					charBuffer += gapType[i];
				}
			}
		}
	}

	fileIn.close();

	ExpParams returnParams;
	returnParams.nVector = nVector;
	returnParams.genMethod = genMethod;
	returnParams.rangeMin = minNum;
	returnParams.rangeMax = maxNum;
	returnParams.ascending = isAscending;
	returnParams.logMemory = isLogMemory;
	returnParams.sortType = selectedSortType;
	returnParams.gapType = gapVector[0];
	returnParams.gapTypeVector = gapVector;
	return returnParams;
}

void ExperimentIO::save_results(map<int, int> averageTimes, map<int, int> averageMems, string filename) {
	bool logMemory = (averageMems.begin() != averageMems.end());
	ofstream fileOut;
	fileOut.open("experiment_logs/"+filename+".csv");
	string header = (logMemory) ? ("n,ticks,memory (bytes)") : ("n,ticks");
	fileOut << header << endl;
	for (map<int, int>::iterator it = averageTimes.begin(); it != averageTimes.end(); it++) {
		fileOut << it->first << "," << it->second;
		if (logMemory) {
			fileOut << "," << averageMems[it->first];
		}
		fileOut << endl;
	}
	fileOut.close();
}