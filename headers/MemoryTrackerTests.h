#pragma once
#include "UnitTest.h"
#include "MemoryTracker.h"
class MemoryTrackerTests : public UnitTest {
public:
    bool test_memory_increase();//not a single function but the functions only matter in this context
    virtual bool run_tests() override;
};

