#include "../headers/UnitTestState.h"
#include "../headers/InsertionSortTests.h"
#include "../headers/SelectionSortTests.h"
#include "../headers/ShellSortTests.h"
#include "../headers/MemoryTrackerTests.h"
#include "../headers/SortWrapperTests.h"
#include "../headers/Console.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void UnitTestState::activate() {
	Console* console = Console::getInstance();
	SelectionSortTests selSortTests;
    InsertionSortTests insSortTests;
    ShellSortTests shellSortTests;
    MemoryTrackerTests memTrackerTests;
	SortWrapperTests sortWrapperTests;

    string input = "";
    while (input != "back") {
		console->clear();
        console->put("[sel] run selection sort tests");
		console->put("[ins] run insertion sort tests");
		console->put("[she] run shell sort tests");
		console->put("[mem] run memory tracker tests");
		console->put("[wra] run sort wrapper tests");
		console->put("[all] run all tests");
		console->put("[back] return to main screen");
		input = console->get();
        if (input != "back") {
            string successString; //reusable string for reporting success/failure
            if (input == "sel") {
                successString = (selSortTests.run_tests()) ? ("tests completed successfully") : ("one or more of the tests failed");
				console->put(successString);
            }
            else if (input == "ins") {
                successString = (insSortTests.run_tests()) ? ("tests completed successfully") : ("one or more of the tests failed");
				console->put(successString);
            }
            else if (input == "she") {
                successString = (shellSortTests.run_tests()) ? ("tests completed successfully") : ("one or more of the tests failed");
				console->put(successString);
            }
            else if (input == "mem") {
                successString = (memTrackerTests.run_tests()) ? ("tests completed successfully") : ("one or more of the tests failed");
				console->put(successString);
            }
			else if (input == "wra") {
				successString = (sortWrapperTests.run_tests()) ? ("tests completed successfully") : ("one or more of the tests failed");
				console->put(successString);
			}
            else if (input == "all") {
                successString = (selSortTests.run_tests()) ? ("selection sort tests completed successfully") : ("one or more of the selection sort tests failed");
				console->put(successString);
                successString = (insSortTests.run_tests()) ? ("insertion sort tests completed successfully") : ("one or more of the insertion sort tests failed");
				console->put(successString);
				successString = (shellSortTests.run_tests()) ? ("shell sort tests completed successfully") : ("one or more of the shell sort tests failed");
				console->put(successString);
				successString = (memTrackerTests.run_tests()) ? ("memory tracker tests completed successfully") : ("one or more of the memory tracker tests failed");
				console->put(successString);
				successString = (sortWrapperTests.run_tests()) ? ("sort wrapper tests completed successfully") : ("one or more of the sort wrapper tests failed");
				console->put(successString);
            }
            else {
                console->put("\""+input+"\" is not recognized as a valid input");
            }
			console->pause();
        }
    }
}
