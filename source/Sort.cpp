#include "../headers/Sort.h"

template <typename T>
bool Sort<T>::compare(T first, T second, bool ascending) {
	if (ascending) {
		return (first > second);
	}
	else {
		return (first < second);
	}
}
