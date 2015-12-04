#pragma once
#ifndef EXPERIMENTIO_H
#define EXPERIMENTIO_H
#include "ExpParams.h"
#include <map>
#include <string>
using namespace std;
//handles the creation of ExpParam objects from files and the writing of the results to a csv
class ExperimentIO {
public:
	//takes the name of an experiment in the experiments directory and turns it into an ExpParams parameter struct
	ExpParams load_experiment(string path);
	//takes two maps, [n]->ms taken for sort, and [n]->memory taken by sort as well as the base name of the csv to log the results to
	void save_results(map<string, vector<map<int,int>>> data, string filename);
};
#endif