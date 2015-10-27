#include <iostream>
#include "../headers/Experiment.h"
#include "../headers/ExperimentIO.h"
#include "../headers/RunExperimentsState.h"
using namespace std;

void RunExperimentsState::activate() {
	system("CLS");
	Experiment exp;
	ExpParams params;
	ExperimentIO io;
	try {
		params = io.load_experiment("experiments/experiment1.txt");
		exp.runExperiment(params, "csvTest");\
	}
	catch (exception e) {
		cout << "ERROR";
	}
	system("PAUSE");
}