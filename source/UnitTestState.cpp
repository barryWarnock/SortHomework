#include "../headers/UnitTestState.h"
#include "../headers/InsertionSortTests.h"
#include "../headers/SelectionSortTests.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void UnitTestState::activate() {
    SelectionSortTests inSortTests;
    cout << inSortTests.run_tests() << endl;
    system("PAUSE");
}
