#pragma once

class UiState {
public:
	//the function that is fired when a state is activated
	virtual void activate() = 0;
};