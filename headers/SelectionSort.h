#pragma once
#include "Sort.h"
class SelectionSort : public Sort {
public:
	// Inherited via Sort
	virtual void sort(int arrayToSort[], int arrayLength, bool ascending) override;
};