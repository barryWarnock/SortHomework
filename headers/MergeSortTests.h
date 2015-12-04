#pragma once
#ifndef MergeSORTTESTS_H
#define MergeSORTTESTS_H
#include "UnitTest.h"
#include "MergeSort.h"
class MergeSortTests : public UnitTest {
public:
	bool test_sort_ascending();
	bool test_sort_descending();
	bool test_compare_ascending();
	bool test_compare_descending();
	virtual bool run_tests() override;
};
#endif