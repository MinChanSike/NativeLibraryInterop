#pragma once

#include <iostream>
#include "INativeListener.h"
using namespace std;

class myClass {
public :
	myClass();
	myClass(double x, double y);
	void registerListener(INativeListener* listener);

	double sumX_Y();
	int deepLoop(int loopCount);
	void pokeEvent(string msg);

private:
	double _x;
	double _y; 
	//native code uses a listener object to emit events
	INativeListener* _theListener; 
};