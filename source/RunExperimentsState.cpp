#include <iostream>
#include <regex>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include "../headers/Experiment.h"
#include "../headers/ExperimentIO.h"
#include "../headers/RunExperimentsState.h"
using namespace std;

void RunExperimentsState::activate() {
	string input = "";
	ifstream inFile;
	inFile.open("./experiments/experimentList.txt");
	vector<string> experiments;
	if(inFile.is_open()) {
        while(!inFile.eof()) {
            string filename;
            inFile >> filename;
            experiments.push_back(filename);
        }
        inFile.close();
	}
	else {
        system("CLS");
        cout << "./experiments/experimentList.txt not found" << endl;
        input = "back";
        system("PAUSE");
	}

	while (input != "back") {
		system("CLS");
		for (vector<string>::iterator it = experiments.begin(); it != experiments.end(); it++) {
			cout << "[" << it - experiments.begin() << "] " << *it << endl;
		}
		cout << "[all] run all tests" << endl;
		cout << "[back] return to main screen" << endl;
		cin >> input;
		if (input != "back") {
                Experiment experiment;
                ExpParams params;
                ExperimentIO io;
                if (input == "all") {
                    cout << "please chose a base name for the csv files, no spaces: ";
                    string logName;
                    cin >> logName;
                    for (vector<string>::iterator expIt = experiments.begin(); expIt != experiments.end(); expIt++) {
                        cout << "loading experiment " << *expIt << endl;
                        try {
                            params = io.load_experiment("./experiments/"+*expIt);
                            //assumes a three character extension preceded by a dot
                            string logNameAppend = expIt->substr(0, expIt->size()-4);
                            cout << "running experiment ..." << endl;
                            bool success = experiment.runExperiment(params, logName+logNameAppend);
                            string successMessage = (success) ? (*expIt+" completed successfully") : (*expIt+" failed to complete");
                            cout << successMessage << endl;
                        }
                        catch (exception e) {
                            cout << "failed to load experiment " << *expIt << endl;;
                        }
                    }
                }
                else if (all_of(input.begin(), input.end(), ::isdigit)) { //individual test
                    int index = strtol(input.c_str(), NULL, 10);
                    if (index >= 0 && index < experiments.size()) {
                        cout << "please chose a base name for the csv file, no spaces: ";
                        string logName;
                        cin >> logName;
                        cout << "loading experiment " << experiments[index] << endl;
                        try {
                            params = io.load_experiment("./experiments/"+experiments[index]);
                            //assumes a three character extension preceded by a dot
                            cout << "running experiment ..." << endl;
                            bool success = experiment.runExperiment(params, logName);
                            string successMessage = (success) ? ("experiment completed successfully") : ("experiment failed to complete");
                            cout << successMessage << endl;
                        }
                        catch (exception e) {
                            cout << "failed to load experiment " << experiments[index] << endl;;
                        }
                    }
                }
                else {
                    cout << "\""+input+"\"" << " is not recognized as valid input" << endl;;
                }
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
