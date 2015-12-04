#pragma once
#ifndef SHELLSORTTEST_H
#define SHELLSORTTEST_H
#include "UnitTest.h"
#include "ShellSort.h"
class ShellSortTests : public UnitTest {
public:
    bool test_sort_ascending_shell_gap();
    bool test_sort_descending_shell_gap();
    bool test_sort_ascending_hibbard_gap();
    bool test_sort_descending_hibbard_gap();
    bool test_sort_ascending_lazarus_gap();
    bool test_sort_descending_lazarus_gap();
    bool test_compare_ascending();
    bool test_compare_descending();
    virtual bool run_tests() override;
};
#endif