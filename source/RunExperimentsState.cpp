#include <iostream>
#include <regex>
#include <sstream>
#include <vector>
#include "../headers/Experiment.h"
#include "../headers/ExperimentIO.h"
#include "../headers/RunExperimentsState.h"
using namespace std;

void RunExperimentsState::activate() {
	vector<string> experiments;
	string input = "";
	/*
	this bit is heavily based off of waqas's answer from this stack overflow thread:
	http://stackoverflow.com/questions/478898/how-to-execute-a-command-and-get-output-of-command-within-c
	*/
	FILE* pipe = _popen("dir experiments", "r");
	if (pipe) {
		string dirString = "";
		char buffer[128];
		while (!feof(pipe)) {
			if (fgets(buffer, 128, pipe) != NULL) {
				dirString += buffer;
			}
		}
		_pclose(pipe);
		regex fileRegex("(\\S+\\.txt)");
		smatch match;
		int i = 1;
		//while (regex_search(dirString, match, fileRegex)) {
			experiments.push_back(match.str());
		//	i++;
		//}
	}
	while (input != "back") {
		system("CLS");
		for (vector<string>::iterator it = experiments.begin(); it != experiments.end(); it++) {
			cout << "[" << (it - experiments.begin()) + 1 << "] " << *it << endl;
		}
		cout << "[back] return to main screen" << endl;
		cin >> input;
		if (input != "back") {
			/*Experiment exp;
			ExpParams params;
			ExperimentIO io;
			try {
			params = io.load_experiment("experiments/experiment10.txt");
			exp.runExperiment(params, "csvTest");\
			}
			catch (exception e) {
			cout << "ERROR";
			}*/
			system("PAUSE");
		}
	}
}