#pragma once
#include "mHeader.h"

myClass::myClass() {}

myClass::myClass(double x, double y) {
	_x = x;
	_y = y;
}

void myClass::registerListener(INativeListener * listener) {
	_theListener = listener;
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

void myClass::pokeEvent(string msg) {
	cout << "\tNative pokeEvent received =>> " << msg.c_str() << endl;

	if (_theListener) {
		//prepare event parameters
		NativeEventArgs args;
		wstring wstr(L"A wide string come from native");
		string str("Pong from native");

		//build-up the argument object
		args.argInt32 = 15;
		args.argString = str.c_str();
		args.argWString = wstr.c_str();

		//fire the event using argument
		_theListener->OnEvent(args);
	}
}
