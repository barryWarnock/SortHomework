#pragma once
#include <vector>
#include "UiState.h"
using namespace std;

class UiStateMachine {
protected:
	vector<UiState> states;
	UiState currentState;
public:
	void add_state(UiState &newState);
};