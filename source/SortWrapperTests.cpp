#include "../headers/SortWrapperTests.h"
#include <vector>
using namespace std;

bool SortWrapperTests::test_sort_insertion() {
	//set up
	SortWrapper wrapper;
	SortParams params;
	params.sortType = INSERTION;
	vector<int> vectorToSort = {3,4,1,8,7,1};

	//test
	wrapper.sort(vectorToSort, params);
	
	//compare
	vector<int> sortedCheck = {1,1,3,4,7,8};
	bool success = (sortedCheck == vectorToSort);
	
	//teardown, no teardown
	
	//return
	return success;
}

bool SortWrapperTests::test_sort_selection() {
	//set up
	SortWrapper wrapper;
	SortParams params;
	params.sortType = SELECTION;
	vector<int> vectorToSort = { 3,4,1,8,7,1 };

	//test
	wrapper.sort(vectorToSort, params);

	//compare
	vector<int> sortedCheck = { 1,1,3,4,7,8 };
	bool success = (sortedCheck == vectorToSort);

	//teardown, no teardown

	//return
	return success;
}

bool SortWrapperTests::test_sort_shell() {
	//set up
	SortWrapper wrapper;
	SortParams params;
	params.sortType = SHELL;
	vector<int> vectorToSort = { 3,4,1,8,7,1 };

	//test
	wrapper.sort(vectorToSort, params);

	//compare
	vector<int> sortedCheck = { 1,1,3,4,7,8 };
	bool success = (sortedCheck == vectorToSort);

	//teardown, no teardown

	//return
	return success;
}

bool SortWrapperTests::test_sort_quick() {
	//set up
	SortWrapper wrapper;
	SortParams params;
	params.sortType = QUICK;
	vector<int> vectorToSort = { 3,4,1,8,7,1 };

	//test
	wrapper.sort(vectorToSort, params);

	//compare
	vector<int> sortedCheck = { 1,1,3,4,7,8 };
	bool success = (sortedCheck == vectorToSort);

	//teardown, no teardown

	//return
	return success;
}
bool SortWrapperTests::test_sort_merge() {
	//set up
	SortWrapper wrapper;
	SortParams params;
	params.sortType = MERGE;
	vector<int> vectorToSort = { 3,4,1,8,7,1 };

	//test
	wrapper.sort(vectorToSort, params);

	//compare
	vector<int> sortedCheck = { 1,1,3,4,7,8 };
	bool success = (sortedCheck == vectorToSort);

	//teardown, no teardown

	//return
	return success;
}
bool SortWrapperTests::test_sort_hybrid_merge() {
	//set up
	SortWrapper wrapper;
	SortParams params;
	params.sortType = HYBRID_MERGE;
	vector<int> vectorToSort = { 3,4,1,8,7,1 };

	//test
	wrapper.sort(vectorToSort, params);

	//compare
	vector<int> sortedCheck = { 1,1,3,4,7,8 };
	bool success = (sortedCheck == vectorToSort);

	//teardown, no teardown

	//return
	return success;
}
bool SortWrapperTests::test_sort_hybrid_quick() {
	//set up
	SortWrapper wrapper;
	SortParams params;
	params.sortType = HYBRID_QUICK;
	vector<int> vectorToSort = { 3,4,1,8,7,1 };

	//test
	wrapper.sort(vectorToSort, params);

	//compare
	vector<int> sortedCheck = { 1,1,3,4,7,8 };
	bool success = (sortedCheck == vectorToSort);

	//teardown, no teardown

	//return
	return success;
}

bool SortWrapperTests::run_tests() {
	return (test_sort_insertion() & test_sort_selection() & test_sort_shell() & test_sort_quick() & test_sort_merge() & test_sort_hybrid_merge() & test_sort_hybrid_quick());
}