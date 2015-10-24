#include "../headers/SortWrapper.h"
#include <cstdlib>
#include <time.h>
#include <vector>
#include "../headers/SortParams.h"
#include "../headers/UserSortState.h"
#include <iostream>
using namespace std;

void UserSortState::activate() {
	system("CLS");
	vector<int> a;
	SortWrapper sortFascade;
	srand(time(NULL));
	int num = 1;
	while (num > 0) {
		cout << "\n\n\nenter number of elements to sort (enter a number < 1 to quit): ";
		cin >> num;
		a.clear();
		for (int i = 0; i < num; i++) {
			a.push_back(rand() % num + 1);
		}
		cout << "Generated Numbers, sorting ..." << endl;

		SortParams parameters;
		parameters.ascending = false;
		parameters.sortType = SHELL;
		sortFascade.sort(a, parameters);
		for (int i = 0; i < num && i < 200; i++) {
			cout << a[i] << " ";
		}
	}
	system("PAUSE");
}