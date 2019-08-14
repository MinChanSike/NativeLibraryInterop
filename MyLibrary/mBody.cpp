#pragma once
#include "mHeader.h"

myClass::myClass() {}

myClass::myClass(double x, double y) {
	_x = x;
	_y = y;
}

double myClass::sumX_Y() {
	return _x + _y;
}

int myClass::deepLoop(int loopCount) {
	int result = 0;
	for (int i = 0; i < loopCount; i++) {
		for (int j = 0; j < loopCount; j++) {
			result = i + j;
		}
	}
	return result;
}