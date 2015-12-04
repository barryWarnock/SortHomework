#include "../headers/MergeSortTests.h"
#include <vector>
using namespace std;

bool MergeSortTests::test_sort_ascending() {
	//set up
	MergeSort sort;
	SortParams params;
	params.ascending = true;
	vector<int> vectorToSort = { 1,8,4,2,1 };

	//test
	sort.sort(vectorToSort, params);
	//vector should now = [1,1,2,4,8]

	//compare
	vector<int> sortCheck = { 1,1,2,4,8 };
	bool success = (sortCheck == vectorToSort);

	//teardown
	//no teardown required

	//return
	return success;
}

bool MergeSortTests::test_sort_descending() {
	//set up
	MergeSort sort;
	SortParams params;
	params.ascending = false;
	vector<int> vectorToSort = { 1,8,4,2,1 };

	//test
	sort.sort(vectorToSort, params);
	//vector should now = [8,4,3,2,2]

	//compare
	vector<int> sortCheck = { 8,4,2,1,1 };
	bool success = (sortCheck == vectorToSort);

	//teardown
	//no teardown required

	//return
	return success;
}

bool MergeSortTests::test_compare_ascending() {
	//set up
	MergeSort sort;

	//test
	bool smallLarge = sort.compare(1, 2, true);
	bool largeSmall = sort.compare(2, 1, true);
	bool same = sort.compare(1, 1, true);

	//compare
	bool success = (!smallLarge & largeSmall & !same);

	//teardown
	//no teaardown required

	//return
	return success;
}

bool MergeSortTests::test_compare_descending() {
	//set up
	MergeSort sort;

	//test
	bool smallLarge = sort.compare(1, 2, false);
	bool largeSmall = sort.compare(2, 1, false);
	bool same = sort.compare(1, 1, false);

	//compare
	bool success = (smallLarge & !largeSmall & !same);

	//teardown
	//no teaardown required

	//return
	return success;
}

bool MergeSortTests::run_tests() {
	return (test_sort_ascending() & test_sort_descending() & test_compare_ascending() & test_compare_descending());
}