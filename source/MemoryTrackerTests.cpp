#include "../headers/MemoryTrackerTests.h"
#include <vector>
using namespace std;

bool MemoryTrackerTests::test_memory_increase() {
    //set up (record current memory and allocate some new memory)
    MemoryTracker::save_memory();
    vector<int> bigVector;
    bigVector.resize(10000000, 2);

    //test / compare
    bool success = (MemoryTracker::get_current_memory() > MemoryTracker::get_saved_memory());

    //teardown //no teardown

    //return
    return success;
}

bool MemoryTrackerTests::run_tests() {
    return test_memory_increase();
}
