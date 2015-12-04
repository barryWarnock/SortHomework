#pragma once
#ifndef HybridMergeSORTTESTS_H
#define HybridMergeSORTTESTS_H
#include "UnitTest.h"
#include "HybridMergeSort.h"
class HybridMergeSortTests : public UnitTest {
public:
	bool test_sort_ascending();
	bool test_sort_descending();
	bool test_compare_ascending();
	bool test_compare_descending();
	virtual bool run_tests() override;
};
#endif