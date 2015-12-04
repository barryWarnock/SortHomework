#pragma once
#ifndef QUICKSORTTESTS_H
#define QUICKSORTTESTS_H
#include "UnitTest.h"
#include "QuickSort.h"
class QuickSortTests : public UnitTest {
public:
	bool test_sort_ascending();
	bool test_sort_descending();
	bool test_compare_ascending();
	bool test_compare_descending();
	virtual bool run_tests() override;
};
#endif