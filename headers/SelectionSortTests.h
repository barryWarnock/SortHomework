#pragma once
#ifndef SELECTIONSORTTESTS_H
#define SELECTIONSORTTESTS_H
#include "UnitTest.h"
#include "SelectionSort.h"
class SelectionSortTests : public UnitTest {
public:
    bool test_sort_ascending();
    bool test_sort_descending();
    bool test_compare_ascending();
    bool test_compare_descending();
    virtual bool run_tests() override;
};
#endif