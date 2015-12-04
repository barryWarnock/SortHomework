#pragma once
#ifndef UISTATE_H
#define UISTATE_H
class UiState {
public:
	//the function that is fired when a state is activated
	virtual void activate() = 0;
};
#endif