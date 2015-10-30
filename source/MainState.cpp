#include "../headers/MainState.h"
#include "../headers/Console.h"

void MainState::activate() {
	Console *console = Console::getInstance();
	bool exit = false;
	while (!exit) {
		console->clear();
		for (vector<string>::iterator it = optionTexts.begin(); it != optionTexts.end(); it++) {
			console->put(*it);
		}
		console->put("[exit] to exit");
		console->put("Please enter your desired option: ");
		string input = console->get();
		if (input == "exit") {
			exit = true;
		}
		else {
			map<string, UiState*>::iterator mapIterator = states.find(input);
			if (mapIterator == states.end()) {
				console->put("\"" + input + "\" is not recognized as a valid input");
				console->pause();
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
