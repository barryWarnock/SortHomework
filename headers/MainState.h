#pragma once
#ifndef MAINSTATE_H
#define MAINSTATE_H
#include <map>
#include <string>
#include <vector>
#include "UiState.h"
using namespace std;

class MainState : public UiState {
protected:
	map<string, UiState*> states;
	vector<string> optionTexts;

public:
	virtual void activate() override;
	//takes a state, the text to describe what that state does, the text that triggers that state 
	void add_option(string text, string input, UiState* newState);
	~MainState();
};
#endif