#pragma once
class Sort {
protected:
	/**
	if ascending compare returns true if the first is greater than the second integer, false otherwise
	if decending compare returns true if the first is less than the second integer, false otherwise
	*/
	bool compare(int first, int second, bool ascending);
public:
	/**

	*/
	virtual void sort(int arrayToSort[], int arrayLength, bool ascending) = 0;
};