#include "../headers/UnitTestState.h"
#include "../headers/InsertionSortTests.h"
#include "../headers/SelectionSortTests.h"
#include "../headers/ShellSortTests.h"
#include "../headers/MemoryTrackerTests.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void UnitTestState::activate() {
    SelectionSortTests selSortTests;
    InsertionSortTests insSortTests;
    ShellSortTests shellSortTests;
    MemoryTrackerTests memTrackerTests;

    string input = "";
    while (input != "back") {
        system("CLS");
        cout << "[sel] run selection sort tests" << endl;
        cout << "[ins] run insertion sort tests" << endl;
        cout << "[she] run shell sort tests" << endl;
        cout << "[mem] run memory tracker tests" << endl;
        cout << "[all] run all tests" << endl;
        cout << "[back] return to main screen" << endl;
        cin >> input;
        if (input != "back") {
            string successString; //reusable string for reporting success/failure
            if (input == "sel") {
                successString = (selSortTests.run_tests()) ? ("tests completed successfully") : ("one or more of the tests failed");
                cout << successString << endl;
            }
            else if (input == "ins") {
                successString = (insSortTests.run_tests()) ? ("tests completed successfully") : ("one or more of the tests failed");
                cout << successString << endl;
            }
            else if (input == "she") {
                successString = (shellSortTests.run_tests()) ? ("tests completed successfully") : ("one or more of the tests failed");
                cout << successString << endl;
            }
            else if (input == "mem") {
                successString = (memTrackerTests.run_tests()) ? ("tests completed successfully") : ("one or more of the tests failed");
                cout << successString << endl;
            }
            else if (input == "all") {
                successString = (selSortTests.run_tests()) ? ("selection sort tests completed successfully") : ("one or more of the selection sort tests failed");
                cout << successString << endl;
                successString = (insSortTests.run_tests()) ? ("insertion sort tests completed successfully") : ("one or more of the insertion sort tests failed");
                cout << successString << endl;
            }
            else {
                cout << "\""+input+"\"" << " is not recognized as a valid input" << endl;
            }
            system("PAUSE");
        }
    }
}
