#include "../headers/SortWrapper.h"
#include <cstdlib>
#include <time.h>
#include <vector>
#include <string>
#include "../headers/SortParams.h"
#include "../headers/UserSortState.h"
#include "../headers/MemoryTracker.h"
#include <iostream>
using namespace std;

void UserSortState::activate() {
	SortWrapper sortFascade;
	srand(time(NULL));

	bool exit = false;
	while (!exit) {
		string input = "";
		system("CLS");
		cout << "[run] run a sort" << endl;
		cout << "[back] return to main screen" << endl;
		cout << "please enter your desired option: ";
		cin >> input;
		if (input == "back") {
			exit = true;
		}
		else if (input == "run") {
			int n = 0;
			cout << "how many elements would you like to sort: ";
			cin >> n;
			vector<int> vectorToSort;
			for (int i = 0; i < n; i++) {
				vectorToSort.push_back(rand() % RAND_MAX);
			}

			string ascendingInput = "";
			while (ascendingInput != "asc" && ascendingInput != "des") {
				cout << "[asc]ending or [des]cending: ";
				cin >> ascendingInput;
			}
			bool ascending = (ascendingInput == "asc");

			string typeInput = "";
			while (typeInput != "sel" && typeInput != "ins" && typeInput != "she") {
				cout << "which type of sort?" << endl;
				cout << "[sel]ection, [ins]ertion, or [she]ll: ";
				cin >> typeInput;
			}
			SortType sortType;
			if (typeInput == "sel") {
				sortType = SELECTION;
			}
			else if (typeInput == "ins") {
				sortType = INSERTION;
			}
			else if (typeInput == "she") {
				sortType = SHELL;
			}

			SortParams params;
			params.ascending = ascending;
			params.sortType = sortType;
			cout << "running sort, depending on how many elements you chose this may take some time" << endl;

			int memBefore = MemoryTracker::get_current_memory();
			int ticksBefore = clock();
			sortFascade.sort(vectorToSort, params);
			int ticksAfter = clock();
			int timeElapsed = (ticksAfter - ticksBefore)/(CLOCKS_PER_SEC/1000);
			int memUsed = MemoryTracker::get_saved_memory() - memBefore;

			bool success = true;
			for (vector<int>::iterator sortedIt = vectorToSort.begin(); sortedIt != vectorToSort.end(); sortedIt++) {
				vector<int>::iterator next = sortedIt + 1;
				if (next != vectorToSort.end()) {
					if (params.ascending) {
						if (*next < *sortedIt) {
							success = false;
							break;
						}
					}
					else {
						if (*next > *sortedIt) {
							success = false;
							break;
						}
					}
				}
			}

			string successString = (success) ? ("successfull") : ("not successfull");
			cout << "the sort was " << successString << ", took " << timeElapsed << "ms to complete" << " and used " << memUsed << " bytes" << endl;
			system("PAUSE");
		}
		else {
			cout << "\"" + input + "\"" << " is not recognized as a valid input" << endl;
			system("PAUSE");
		}
	}
}
