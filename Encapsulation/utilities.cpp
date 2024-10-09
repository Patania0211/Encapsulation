#include "utilities.h"

int Utilities:: randomise(int value) {
	int v = rand() % value;
	return v;
}