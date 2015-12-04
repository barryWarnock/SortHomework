#include "../headers/SortWrapper.h"
#include <cstdlib>
#include <time.h>
#include <vector>
#include <string>
#include "../headers/SortParams.h"
#include "../headers/UserSortState.h"
#include "../headers/MemoryTracker.h"
#include "../headers/Console.h"
using namespace std;

void UserSortState::activate() {
	Console* console = Console::getInstance();
	SortWrapper sortFascade;
	srand(time(NULL));

	bool exit = false;
	while (!exit) {
		string input = "";
		console->clear();
		console->put("[run] run a sort");
		console->put("[back] return to main screen");
		console->put("please enter your desired option: ");
		input = console->get();
		if (input == "back") {
			exit = true;
		}
		else if (input == "run") {
			int n = 0;
			console->put("how many elements would you like to sort: ");
			n = console->str_to_int(console->get());
			vector<int> vectorToSort;
			for (int i = 0; i < n; i++) {
				vectorToSort.push_back(rand() % RAND_MAX);
			}

			string ascendingInput = "";
			while (ascendingInput != "asc" && ascendingInput != "des") {
				console->put("[asc]ending or [des]cending: ");
				ascendingInput = console->get();
			}
			bool ascending = (ascendingInput == "asc");

			string typeInput = "";
			while (typeInput != "sel" && typeInput != "ins" && typeInput != "she" && typeInput != "qui" && typeInput != "mer" && typeInput != "hm" && typeInput != "hq") {
				console->put("which type of sort?");
				console->put("[sel]ection, [ins]ertion, [she]ll, [mer]ge, [qui]ck, [hm]-hybrid merge, or [hq]-hybrid quick: ");
				typeInput = console->get();
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
			else if (typeInput == "mer") {
				sortType = MERGE;
			}
			else if (typeInput == "qui") {
				sortType = QUICK;
			}
			else if (typeInput == "hm") {
				sortType = HYBRID_MERGE;
			}
			else if (typeInput == "hq") {
				sortType = HYBRID_QUICK;
			}

			int hybridThreshold = 0;
			if (sortType == HYBRID_MERGE || sortType == HYBRID_QUICK) {
				console->put("how large do you want the hybrid threshold to be: ");
				hybridThreshold = console->str_to_int(console->get());
			}

			SortParams params;
			params.ascending = ascending;
			params.sortType = sortType;
			params.hybridThreshold = hybridThreshold;
			console->put("running sort, depending on how many elements you chose this may take some time");

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
			console->put("the sort was "+successString+", took "+console->int_to_str(timeElapsed)+"ms to complete and used "+console->int_to_str(memUsed)+" bytes");
			console->pause();
		}
		else {
			console->put("\""+input+"\" is not recognized as a valid input");
			console->pause();
		}
	}
}
