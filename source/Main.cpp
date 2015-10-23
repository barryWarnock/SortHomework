#include "../headers/SortWrapper.h"
#include <iostream>
#include <cstdlib>
#include "../headers/SortParams.h"
#include <time.h>
#include <vector>
using namespace std;

int main() {
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
		parameters.sortType = SELECTION;
		a = sortFascade.sort(a, parameters);
		for (int i = 0; i < num && i < 200; i++) {
			cout << a[i] << " ";
		}
	}
	return 0;
}
