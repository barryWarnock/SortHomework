#pragma once
#include "UnitTest.h"
#include "SortWrapper.h"
class SortWrapperTests : public UnitTest {
public:
	bool test_sort_insertion();
	bool test_sort_selection();
	bool test_sort_shell();

	virtual bool run_tests() override;
};
