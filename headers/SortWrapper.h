#pragma once
enum SortType {
	SELECTION,
	INSERTION,
	SHELL,
};

class SortWrapper {
public:
	void sort(int arrayToSort[], int arrayLength, bool ascending, SortType algorithm);
};