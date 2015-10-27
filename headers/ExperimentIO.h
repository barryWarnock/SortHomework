#pragma once
#include "ExpParams.h"
#include <map>
#include <string>
using namespace std;
//handles the creation of ExpParam objects from files and the writing of the results to a csv
class ExperimentIO {
public:
	ExpParams load_experiment(string path);
	void save_results(map<int, int> averageTimes, string filename);
};