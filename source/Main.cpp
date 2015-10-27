#include "../headers/MainState.h"
#include "../headers/UserSortState.h"
#include "../headers/RunExperimentsState.h"
#include "../headers/MemoryTracker.h"

int main() {
	MainState mainMenu;
	mainMenu.add_option("[sort] test sort", "sort", new UserSortState());
	mainMenu.add_option("[exp] run experiments", "exp", new RunExperimentsState());
	mainMenu.activate();
	return 0;
}
