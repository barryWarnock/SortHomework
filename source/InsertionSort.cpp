#include "../headers/InsertionSort.h"
#include <iostream>
using namespace std;

void InsertionSort::sort(vector<int> &vectorToSort, SortParams params)
{
	for (int i = 0; i < vectorToSort.size(); i++) {
		int val = vectorToSort[i];
		int j = i - 1;
		while (j >= 0 && compare(vectorToSort[j], val, params.ascending)) {
			vectorToSort[j + 1] = vectorToSort[j];
			j--;
		}
		vectorToSort[j+1] = val;
	}
}
