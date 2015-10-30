#pragma once
#include "ExpParams.h"
#include <string>

class Experiment {
public:
	//takes a set of parameters and a base name for the csv log files and runs the experiment described by the ExpParams parameters
	bool runExperiment(ExpParams params, string logName);
};