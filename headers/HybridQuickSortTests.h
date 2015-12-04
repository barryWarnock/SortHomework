#pragma once
#ifndef HybridQuickSortTESTS_H
#define HybridQuickSortTESTS_H
#include "UnitTest.h"
#include "HybridQuickSort.h"
class HybridQuickSortTests : public UnitTest {
public:
	bool test_sort_ascending();
	bool test_sort_descending();
	bool test_compare_ascending();
	bool test_compare_descending();
	virtual bool run_tests() override;
};
#endif