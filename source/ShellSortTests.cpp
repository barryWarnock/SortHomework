#include "../headers/ShellSortTests.h"
#include "../headers/ShellSort.h"
#include <vector>
using namespace std;

bool ShellSortTests::test_sort_ascending_shell_gap() {
	//set up
	ShellSort sort;
	SortParams params;
	params.ascending = true;
	params.gapType = SHELL_GAP;
	vector<int> vectorToSort = {1,8,4,2,1};

	//test
	sort.sort(vectorToSort, params);

	//compare
	vector<int> sortCheck = {1,1,2,4,8};
	bool success = (sortCheck == vectorToSort);

    //teardown
    //no teardown required

    //return
    return success;
}

bool ShellSortTests::test_sort_descending_shell_gap() {
    //set up
    ShellSort sort;
    SortParams params;
    params.ascending = false;
    params.gapType = SHELL_GAP;
	vector<int> vectorToSort = {1,8,4,2,1};

    //test
    sort.sort(vectorToSort, params);

    //compare
	vector<int> sortCheck = { 8,4,2,1,1 };
	bool success = (sortCheck == vectorToSort);

    //teardown
    //no teardown required

    //return
    return success;
}

bool ShellSortTests::test_sort_ascending_hibbard_gap() {
    //set up
    ShellSort sort;
    SortParams params;
    params.ascending = true;
    params.gapType = HIBBARD_GAP;
	vector<int> vectorToSort = { 1,8,4,2,1 };

    //test
    sort.sort(vectorToSort, params);

    //compare
	vector<int> sortCheck = { 1,1,2,4,8 };
	bool success = (sortCheck == vectorToSort);

    //teardown
    //no teardown required

    //return
    return success;
}

bool ShellSortTests::test_sort_descending_hibbard_gap() {
    //set up
    ShellSort sort;
    SortParams params;
    params.ascending = false;
    params.gapType = HIBBARD_GAP;
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

bool ShellSortTests::test_sort_ascending_lazarus_gap() {
    //set up
    ShellSort sort;
    SortParams params;
    params.ascending = true;
    params.gapType = LAZARUS_GAP;
	vector<int> vectorToSort = { 1,8,4,2,1 };

    //test
    sort.sort(vectorToSort, params);

    //compare
	vector<int> sortCheck = { 1,1,2,4,8 };
	bool success = (sortCheck == vectorToSort);

    //teardown
    //no teardown required

    //return
    return success;
}

bool ShellSortTests::test_sort_descending_lazarus_gap() {
    //set up
    ShellSort sort;
    SortParams params;
    params.ascending = false;
    params.gapType = LAZARUS_GAP;
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

bool ShellSortTests::test_compare_ascending() {
    //set up
    ShellSort sort;

    //test
    bool smallLarge = sort.compare(1,2,true);
    bool largeSmall = sort.compare(2,1,true);
    bool same = sort.compare(1,1,true);

    //compare
    bool success = (!smallLarge & largeSmall & !same);

    //teardown
    //no teaardown required

    //return
    return success;
}

bool ShellSortTests::test_compare_descending() {
    //set up
    ShellSort sort;

    //test
    bool smallLarge = sort.compare(1,2,false);
    bool largeSmall = sort.compare(2,1,false);
    bool same = sort.compare(1,1,false);

    //compare
    bool success = (smallLarge & !largeSmall & !same);

    //teardown
    //no teaardown required

    //return
    return success;
}

bool ShellSortTests::run_tests() {
    return (test_sort_ascending_shell_gap() & test_sort_descending_shell_gap() & test_sort_ascending_hibbard_gap() & test_sort_descending_hibbard_gap() & test_sort_ascending_lazarus_gap() & test_sort_descending_lazarus_gap() & test_compare_ascending() & test_compare_descending());
}
