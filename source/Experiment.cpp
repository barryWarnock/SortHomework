#include "../headers/Experiment.h"
#include "../headers/MemoryTracker.h"
#include "../headers/SortWrapper.h"
#include "../headers/Sort.h"
#include "../headers/InsertionSort.h"
#include "../headers/SelectionSort.h"
#include "../headers/ShellSort.h"
#include "../headers/ExperimentIO.h"
#include <time.h>
#include <map>
#include <sstream>
#include <iostream>

bool Experiment::runExperiment(ExpParams params, string logName) {
	srand(time(NULL));
	Sort* sort = NULL;
	switch (params.sortType) {
	case SELECTION:
		sort = new(SelectionSort);
		break;
	case INSERTION:
		sort = new(InsertionSort);
		break;
	case SHELL:
		sort = new(ShellSort);
		break;
	}
	if (sort == NULL) return false;
	//the key is the n and the value is the number of ms the sort takes on avg for than number of elements
	bool successful = true; //if a sort fails this is set to false;
	map<int, int> avgTimeForN;
	map<int, int> avgMemForN;
	for (vector<GapType>::iterator gapIt = params.gapTypeVector.begin(); gapIt != params.gapTypeVector.end(); gapIt++) {
		for (vector<int>::iterator n = params.nVector.begin(); n != params.nVector.end(); n++) {
			vector<int> timeTaken;
			vector<int> memTaken;
			for (int i = 0; i < 5; i++) {
				vector<int> vectorToSort;
				switch (params.genMethod) {
				default:
				case RANDOM:
					for (int j = 0; j < *n; j++) {
						vectorToSort.push_back(rand() % RAND_MAX);
					}
					break;
				case SORTED:
					for (int j = 0; j < *n; j++) {
						vectorToSort.push_back(j);
					}
					break;
				case SORTED_REVERSE:
					for (int j = *n; j > 0; j--) {
						vectorToSort.push_back(j);
					}
					break;
				case RANDOM_IN_RANGE:
					for (int j = 0; j < *n; j++) {
						vectorToSort.push_back((rand() % (params.rangeMax - params.rangeMin)) + params.rangeMin);
					}
					break;
				}
				params.gapType = *gapIt;
				int memBefore = MemoryTracker::get_current_memory();
				int timeBefore = clock();
				sort->sort(vectorToSort, params);
				int timeAfter = clock();

				memTaken.push_back(MemoryTracker::get_saved_memory() - memBefore);
				timeTaken.push_back(timeAfter - timeBefore);
				for (vector<int>::iterator sortedIt = vectorToSort.begin(); sortedIt != vectorToSort.end(); sortedIt++) {
					vector<int>::iterator next = sortedIt + 1;
					if (next != vectorToSort.end()) {
						if (params.ascending) {
							if (*next < *sortedIt) {
								successful = false;
								break;
							}
						}
						else {
							if (*next > *sortedIt) {
								successful = false;
								break;
							}
						}
					}
				}
			}

			int timeTotal = 0;
			int timeIterations = 0;
			for (vector<int>::iterator avgIt = timeTaken.begin(); avgIt != timeTaken.end(); avgIt++) {
				timeIterations++;
				timeTotal += *avgIt;
			}
			int timeAvg = timeTotal / timeIterations;
			avgTimeForN[*n] = (timeAvg/(CLOCKS_PER_SEC/1000));

			if (params.logMemory) {
				int memTotal = 0;
				int memIterations = 0;
				for (vector<int>::iterator avgIt = memTaken.begin(); avgIt != memTaken.end(); avgIt++) {
					memIterations++;
					memTotal += *avgIt;
				}
				int avgMem = memTotal / memIterations;
				avgMemForN[*n] = avgMem;
			}

		}
		if (successful) {
			ExperimentIO io;
			string append = "";
			if (params.gapTypeVector.size() > 1) {
				ostringstream appStream;
				appStream << "_gap" << *gapIt;
				append = appStream.str();
			}
			io.save_results(avgTimeForN, avgMemForN, logName+append);
		}
	}
	delete sort;
	return successful;
}
