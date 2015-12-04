#pragma once
#ifndef EXPERIMENT_H
#define EXPERIMENT_H
#include "ExpParams.h"
#include <string>

class Experiment {
private:
	vector<int> generate_vector(ExpParams params, int size);
public:
	//takes a set of parameters and a base name for the csv log files and runs the experiment described by the ExpParams parameters
	bool runExperiment(ExpParams params, string logName);
};
#endif