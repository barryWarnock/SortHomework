#pragma once
#ifndef EXPPARAMS_H
#define EXPPARAMS_H
#include "SortParams.h"
#include <vector>
using namespace std;

enum GenerationMethod {
	RANDOM,
	SORTED,
	SORTED_REVERSE,
	RANDOM_IN_RANGE
};

//the struct that describes an experiment
struct ExpParams : public SortParams {
	vector<SortType> sortTypeVector;
	//a list of n's (sizes of arrays to run the experiment on)
	vector<int> nVector;
	//the method used to generate the array
	GenerationMethod genMethod;
	//if genMethod is RANDOM_IN_RANGE these are used as the minimum and maximum values 
	int rangeMin;
	int rangeMax;
	//the current type of gap to use (this will be changed by the experiment if there is more than one gap type being used by this experiment)
	GapType gapType;
	//a list of gap types to use
	vector<GapType> gapTypeVector;
	//I misread some experiments and so implemented the ability to toggle memory logging on and off
	bool logMemory;
	vector<int> thresholdVector;
	ExpParams();
	ExpParams(const ExpParams &other);
};
#endif