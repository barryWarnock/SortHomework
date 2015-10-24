#include "../headers/MainState.h"
#include "../headers/UserSortState.h"

int main() {
	MainState mainMenu;
	mainMenu.add_option("[sort] test sort", "sort", new UserSortState());
	mainMenu.activate();
	return 0;
}
