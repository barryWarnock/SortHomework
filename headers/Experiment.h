#pragma once
#ifndef EXPERIMENT_H
#define EXPERIMENT_H
#include "ExpParams.h"
#include <string>

class Experiment {
private:
	vector<int> generate_vector(ExpParams params, int size);
	bool run_iteration(ExpParams params, int n, int &time, int &memory);
	bool run_iterations(ExpParams params, int n, int &avgTime, int &avgMemory, int iterations);
	bool check_sort(vector<int> &sorted, bool ascending);
public:
	//takes a set of parameters and a base name for the csv log files and runs the experiment described by the ExpParams parameters
	bool runExperiment(ExpParams params, string logName);
};
#endif