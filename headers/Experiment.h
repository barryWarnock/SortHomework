#pragma once
#include "ExpParams.h"
#include <string>

class Experiment {
public:
	bool runExperiment(ExpParams params, string logName);
};