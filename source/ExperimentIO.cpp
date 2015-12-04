#include "../headers/ExperimentIO.h"
#include "../headers/Console.h"
#include <fstream>
#include <vector>
using namespace std;

ExpParams ExperimentIO::load_experiment(string path) {
	Console* console = Console::getInstance();
	ifstream fileIn;
	fileIn.open(path.c_str());
	if (!fileIn.is_open()) {
		throw exception();
	}
	string nStart, nIncrement, nStop, generationMethod, rangeMin, rangeMax, sortType, ascending, logMemory, gapType, thresholds;
	vector<int> thresholdVector;
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
	fileIn >> thresholds;
	int thresholdsNum = console->str_to_int(thresholds);
	for (int i = 0; i < thresholdsNum; i++) {
		string temp;
		fileIn >> temp;
		thresholdVector.push_back(console->str_to_int(temp));
	}

	int nStartNum, nIncrementNum, nStopNum;
	nStartNum = console->str_to_int(nStart);
	nIncrementNum = console->str_to_int(nIncrement);
	nStopNum = console->str_to_int(nStop);

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
	minNum = console->str_to_int(rangeMin);
	maxNum = console->str_to_int(rangeMax);

	bool isAscending;
	isAscending = console->str_to_int(ascending);

	bool isLogMemory;
	isLogMemory = console->str_to_int(logMemory);
	vector<SortType> sortTypeVector;
	string charBuffer = "";
	for (int i = 0; i < sortType.size(); i++) {
		if (sortType[i] == ',' || i == sortType.size() - 1) {
			SortType selectedSortType;
			if (charBuffer == "INSERTION") {
				selectedSortType = INSERTION;
			}
			else if (charBuffer == "SELECTION") {
				selectedSortType = SELECTION;
			}
			else if (charBuffer == "SHELL") {
				selectedSortType = SHELL;
			}
			else if (charBuffer == "QUICK") {
				selectedSortType = QUICK;
			}
			else if (charBuffer == "HYBRID_QUICK") {
				selectedSortType = HYBRID_QUICK;
			}
			else if (charBuffer == "MERGE") {
				selectedSortType = MERGE;
			}
			else if (charBuffer == "HYBRID_MERGE") {
				selectedSortType = HYBRID_MERGE;
			}
			sortTypeVector.push_back(selectedSortType);
			charBuffer = "";
		}
		else if (sortType[i] != ' ') {
			charBuffer += sortType[i];
		}
	}


	if (gapType == "NOGAP") {
		gapVector.push_back(SHELL_GAP);
	}
	else {
		charBuffer = "";
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
	returnParams.sortTypeVector = sortTypeVector;
	returnParams.gapType = gapVector[0];
	returnParams.gapTypeVector = gapVector;
	returnParams.thresholdVector = thresholdVector;
	return returnParams;
}

void ExperimentIO::save_results(map<string, vector<map<int, int>>> data, string filename) {
	ofstream fileOut;
	Console* console = Console::getInstance();

	string path = "experiment_logs/"+filename+".csv";
	fileOut.open(path.c_str());
	string header = "n";
	for (map<string, vector<map<int, int>>>::iterator key = data.begin(); key != data.end(); key++) {
		header += ","+key->first + " time (ms), " + key->first + " memory (bytes)";
	}
	fileOut << header;
	fileOut << endl;
	int rows = data.begin()->second.size();
	for (int i = 0; i < rows; i++) {
		fileOut << data.begin()->second[0][i];
		for (map<string, vector<map<int, int>>>::iterator key = data.begin(); key != data.end(); key++) {
			
		}
	}
	fileOut.close();
}
