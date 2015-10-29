#pragma once
#include "UnitTest.h"
#include "InsertionSort.h"
class InsertionSortTests : public UnitTest {
public:
    bool test_sort_ascending();
    bool test_sort_descending();
    bool test_compare_ascending();
    bool test_compare_descending();
    virtual bool run_tests() override;
};
