#include "utilities.h"

int Utilities:: randomise(int value) {
	int v = rand() % value + 1 ;
	return v;
}