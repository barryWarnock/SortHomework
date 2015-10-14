#include "../headers/SortWrapper.h"
#include <iostream>
#include <cstdlib>
#include "../headers/SelectionSort.h"
#include "../headers/InsertionSort.h"
#include <time.h>
using namespace std;

int main() {
	int *a;
	SortWrapper s;
	srand(time(NULL));
	int num = 1;
	while (num) {
		cout << "\n\n\nenter number of elements to sort (enter a number < 1 to quit): ";
		cin >> num;
		a = new(int[num]);
		for (int i = 0; i < num; i++) {
			a[i] = rand() % num + 1;
		}
		cout << "Generated Numbers, sorting ..." << endl;
		s.sort(a, num, true, SHELL);
		for (int i = 0; i < num && i < 200; i++) {
			cout << a[i] << " ";
		}
	}
	delete[] a;
	return 0;
}
