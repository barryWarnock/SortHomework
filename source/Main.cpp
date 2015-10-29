#include "../headers/MainState.h"
#include "../headers/UserSortState.h"
#include "../headers/RunExperimentsState.h"
#include "../headers/UnitTestState.h"

int main() {
	MainState mainMenu;
	mainMenu.add_option("[sort] test sort", "sort", new UserSortState());
	mainMenu.add_option("[exp] run experiments", "exp", new RunExperimentsState());
	mainMenu.add_option("[test] run unit tests", "test", new UnitTestState());
	mainMenu.activate();
	return 0;
}
