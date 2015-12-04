#pragma once
#ifndef SORTWRAPPERTESTS_H
#define SORTWRAPPERTESTS_H
#include "UnitTest.h"
#include "SortWrapper.h"
class SortWrapperTests : public UnitTest {
public:
	bool test_sort_insertion();
	bool test_sort_selection();
	bool test_sort_shell();
	bool test_sort_quick();
	bool test_sort_merge();
	bool test_sort_hybrid_merge();
	bool test_sort_hybrid_quick();

	virtual bool run_tests() override;
};
#endif