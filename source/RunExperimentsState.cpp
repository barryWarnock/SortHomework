#include <fstream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include "../headers/Experiment.h"
#include "../headers/ExperimentIO.h"
#include "../headers/RunExperimentsState.h"
#include "../headers/Console.h"
using namespace std;

void RunExperimentsState::activate() {
	Console* console = Console::getInstance();
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
		console->clear();
        console->put("./experiments/experimentList.txt not found");
        input = "back";
		console->pause();
	}

	while (input != "back") {
		console->clear();
		for (vector<string>::iterator it = experiments.begin(); it != experiments.end(); it++) {
			console->put("["+console->int_to_str(it - experiments.begin())+"] "+*it);
		}
		console->put("[all] run all experiments");
		console->put("[back] return to main screen");
		input = console->get();
		if (input != "back") {
                Experiment experiment;
                ExpParams params;
                ExperimentIO io;
                if (input == "all") {
					string logName = " ";
					while (logName.find(" ") != string::npos) {
						console->put("please choose a base name for the csv files, no spaces: ");
						logName = console->get();
					}
                    for (vector<string>::iterator expIt = experiments.begin(); expIt != experiments.end(); expIt++) {
						console->put("loading experiment "+*expIt);
                        try {
                            params = io.load_experiment("./experiments/"+*expIt);
                            //assumes a three character extension preceded by a dot
                            string logNameAppend = expIt->substr(0, expIt->size()-4);
							console->put("running experiment ...");
                            bool success = experiment.runExperiment(params, logName+logNameAppend);
                            string successMessage = (success) ? (*expIt+" completed successfully") : (*expIt+" failed to complete");
							console->put(successMessage);
                        }
                        catch (exception e) {
							console->put("failed to load experiment "+*expIt);
                        }
                    }
                }
                else if (all_of(input.begin(), input.end(), ::isdigit)) { //individual test
                    int index = strtol(input.c_str(), NULL, 10);
                    if (index >= 0 && index < experiments.size()) {
						string logName = " ";
						while (logName.find(" ") != string::npos) {
							console->put("please choose a base name for the csv files, no spaces: ");
							logName = console->get();
						}
						console->put("loading experiment "+experiments[index]);
                        try {
                            params = io.load_experiment("./experiments/"+experiments[index]);
                            console->put("running experiment ...");
                            bool success = experiment.runExperiment(params, logName);
                            string successMessage = (success) ? ("experiment completed successfully") : ("experiment failed to complete");
                            console->put(successMessage);
                        }
                        catch (exception e) {
							console->put("failed to load experiment "+experiments[index]);
                        }
                    }
                }
                else {
                    console->put("\""+input+"\" is not recognized as valid input");
                }
				console->pause();
		}
	}
}
