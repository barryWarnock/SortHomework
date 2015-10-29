#include "../headers/InsertionSortTests.h"
#include "../headers/InsertionSort.h"
#include <vector>
using namespace std;

bool InsertionSortTests::test_sort_ascending() {
    //set up
    InsertionSort sort;
    SortParams params;
    params.ascending = true;
    vector<int> vectorToSort;
    vectorToSort.push_back(1);
    vectorToSort.push_back(8);
    vectorToSort.push_back(4);
    vectorToSort.push_back(2);
    vectorToSort.push_back(1);
    //vector now = [1,8,4,2,1]
    int vectorSizeBeforeSort = vectorToSort.size();

    //test
    sort.sort(vectorToSort, params);
    //vector should now = [1,1,2,4,8]

    //compare
    bool success = true;
    if (vectorToSort.size() != vectorSizeBeforeSort) {
        success = false;
    }
    else if (vectorToSort[0] != 1) {
        success = false;
    }
    else if (vectorToSort[1] != 1) {
        success = false;
    }
    else if (vectorToSort[2] != 2) {
        success = false;
    }
    else if (vectorToSort[3] != 4) {
        success = false;
    }
    else if (vectorToSort[4] != 8) {
        success = false;
    }

    //teardown
    //no teardown required

    //return
    return success;
}

bool InsertionSortTests::test_sort_descending() {
    //set up
    InsertionSort sort;
    SortParams params;
    params.ascending = false;
    vector<int> vectorToSort;
    vectorToSort.push_back(1);
    vectorToSort.push_back(8);
    vectorToSort.push_back(4);
    vectorToSort.push_back(2);
    vectorToSort.push_back(1);
    //vector now = [1,8,4,2,1]
    int vectorSizeBeforeSort = vectorToSort.size();

    //test
    sort.sort(vectorToSort, params);
    //vector should now = [8,4,3,2,2]

    //compare
    bool success = true;
    if (vectorToSort.size() != vectorSizeBeforeSort) {
        success = false;
    }
    else if (vectorToSort[0] != 8) {
        success = false;
    }
    else if (vectorToSort[1] != 4) {
        success = false;
    }
    else if (vectorToSort[2] != 2) {
        success = false;
    }
    else if (vectorToSort[3] != 1) {
        success = false;
    }
    else if (vectorToSort[4] != 1) {
        success = false;
    }

    //teardown
    //no teardown required

    //return
    return success;
}

bool InsertionSortTests::test_compare_ascending() {
    //set up
    InsertionSort sort;

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

bool InsertionSortTests::test_compare_descending() {
    //set up
    InsertionSort sort;

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

bool InsertionSortTests::run_tests() {
    return (test_sort_ascending() & test_sort_descending() & test_compare_ascending() & test_compare_descending());
}
