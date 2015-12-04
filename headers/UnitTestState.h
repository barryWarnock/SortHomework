#pragma once
#ifndef UNITTESTSTATE_H
#define UNITTESTSTATE_H
#include "UiState.h"
class UnitTestState : public UiState {
public:
    virtual void activate() override;
};
#endif