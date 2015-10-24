#include "../headers/MainState.h"
#include <iostream>

void MainState::activate() {
	bool exit = false;
	while (!exit) {
		system("CLS"); //I know system() is generally supposed to be avoided but I don't want to learn curses or print a ton of newlines so this will have to do
		for (vector<string>::iterator it = optionTexts.begin(); it != optionTexts.end(); it++) {
			cout << *it << endl;
		}
		cout << "[exit] to exit" << endl;
		cout << "Please enter your desired option: ";
		string input = "";
		cin >> input;
		if (input == "exit") {
			exit = true;
		}
		else {
			map<string, UiState*>::iterator mapIterator = states.find(input);
			if (mapIterator == states.end()) {
				cout << "\"" + input + "\" is not recognized as a valid input" << endl;
				system("PAUSE");
			}
			else {
				mapIterator->second->activate();
			}
		}
	}
}

void MainState::add_option(string text, string input, UiState* newState) {
	if (input != "exit") {
		optionTexts.push_back(text);
		states[input] = newState;
	}
}

MainState::~MainState() {
	for (map<string, UiState*>::iterator it = states.begin(); it != states.end(); it++) {
		delete it->second;
	}
}