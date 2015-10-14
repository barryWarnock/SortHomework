#include "../headers/Sort.h"

bool Sort::compare(int first, int second, bool ascending) {
	if (ascending) {
		return (first > second);
	}
	else {
		return (first < second);
	}
}