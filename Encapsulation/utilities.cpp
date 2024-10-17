#include "utilities.h"

int Utilities:: Randomise(int minValue, int maxValue) {
	int v = rand() % maxValue - minValue;
	return v;
}