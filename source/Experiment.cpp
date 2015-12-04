#include "../headers/Experiment.h"
#include "../headers/MemoryTracker.h"
#include "../headers/SortWrapper.h"
#include "../headers/SortWrapper.h"
#include "../headers/ExperimentIO.h"
#include "../headers/Console.h"
#include <time.h>
#include <map>
#include <sstream>
#include <iostream>

bool Experiment::check_sort(vector<int> &sorted, bool ascending) {
	bool successful = true;
	for (vector<int>::iterator sortedIt = sorted.begin(); sortedIt != sorted.end(); sortedIt++) {
		vector<int>::iterator next = sortedIt + 1;
		if (next != sorted.end()) {
			if (ascending) {
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
	return successful;
}

bool Experiment::run_iteration(ExpParams params, int n, int &time, int &memory) {
	vector<int> vectorToSort = generate_vector(params, n);
	
	SortWrapper sortFascade;
	
	int memBefore = MemoryTracker::get_current_memory();
	int timeBefore = clock();
	sortFascade.sort(vectorToSort, params);
	int timeAfter = clock();
	time = timeAfter - timeBefore;
	memory = MemoryTracker::get_saved_memory() - memBefore;

	return check_sort(vectorToSort, params.ascending);
}

bool Experiment::run_iterations(ExpParams params, int n, int &avgTime, int &avgMemory, int iterations) {
	Console* console = Console::getInstance();
	console->put("running a sort with size "+console->int_to_str(n));

	int totalTime = 0;
	int totalMemory = 0;
	bool success;
	for (int i = 0; i < iterations; i++) {
		int time, memory;
		success = run_iteration(params, n, time, memory);
		if (success == false) return false;
		totalTime += time;
		totalMemory += memory;
	}
	avgTime = totalTime / iterations;
	avgMemory = (totalMemory / iterations) / (CLOCKS_PER_SEC/1000);
	return success;
}

vector<int> Experiment::generate_vector(ExpParams params, int size) {
	vector<int> vectorToSort;
	switch (params.genMethod) {
	default:
	case RANDOM:
		for (int j = 0; j < size; j++) {
			vectorToSort.push_back(rand() % RAND_MAX);
		}
		break;
	case SORTED:
		for (int j = 0; j < size; j++) {
			vectorToSort.push_back(j);
		}
		break;
	case SORTED_REVERSE:
		for (int j = size; j > 0; j--) {
			vectorToSort.push_back(j);
		}
		break;
	case RANDOM_IN_RANGE:
		for (int j = 0; j < size; j++) {
			vectorToSort.push_back((rand() % (params.rangeMax - params.rangeMin)) + params.rangeMin);
		}
		break;
	}
	return vectorToSort;
}

bool Experiment::runExperiment(ExpParams params, string logName) {
	srand(time(NULL));
	bool success = true;

	Console* console = Console::getInstance();

	//maps strings, (the text to prepend to colums) to a vector of maps [[n]->time, [n]->memory]
	map<string, vector<map<int, int>>> data;
	for (vector<SortType>::iterator sortType = params.sortTypeVector.begin(); sortType != params.sortTypeVector.end(); sortType++) {
		params.sortType = *sortType;
		if (*sortType == SHELL) {
			for (vector<GapType>::iterator gapType = params.gapTypeVector.begin(); gapType != params.gapTypeVector.end(); gapType++) {
				string key;
				map<int, int> avgTime, avgMemory;
				params.gapType = *gapType;
				key = "shell gap-type "+ console->int_to_str(*gapType);
				for (vector<int>::iterator n = params.nVector.begin(); n != params.nVector.end(); n++) {
					int time, memory;
					success = success & run_iterations(params, *n, time, memory, 5);
					avgTime[*n] = time;
					avgMemory[*n] = memory;
				}
				data[key] = { avgTime, avgMemory };
			}
		}
		else if (*sortType == HYBRID_MERGE || *sortType == HYBRID_QUICK) {
			for (vector<int>::iterator threshold = params.thresholdVector.begin(); threshold != params.thresholdVector.end(); threshold++) {
				string key;
				map<int, int> avgTime, avgMemory;
				params.hybridThreshold = *threshold;
				if (*sortType == HYBRID_MERGE) key = "hybrid merge sort threshold " + console->int_to_str(*threshold);
				else key = "hybrid quicksort threshold " + console->int_to_str(*threshold);
				for (vector<int>::iterator n = params.nVector.begin(); n != params.nVector.end(); n++) {
					int time, memory;
					success = success & run_iterations(params, *n, time, memory, 5);
					avgTime[*n] = time;
					avgMemory[*n] = memory;
				}
				data[key] = { avgTime, avgMemory };
			}
		}
		else {
			string key;
			map<int, int> avgTime, avgMemory;
			switch (*sortType) {
			case INSERTION:
				key = "insertion";
			break;
			case SELECTION:
				key = "selection";
			break;
			case SHELL:
				key = "shell";
			break;
			case QUICK:
				key = "quick";
			break;
			case MERGE:
				key = "merge";
			break;
			default:
				key = "";
			break;
			}
			for (vector<int>::iterator n = params.nVector.begin(); n != params.nVector.end(); n++) {
				int time, memory;
				success = success & run_iterations(params, *n, time, memory, 5);
				avgTime[*n] = time;
				avgMemory[*n] = memory;
			}
			data[key] = { avgTime, avgMemory };
		}
		if (success == false) return false;
	}
	ExperimentIO dataLogger;
	dataLogger.save_results(data, logName);
	return success;
}
