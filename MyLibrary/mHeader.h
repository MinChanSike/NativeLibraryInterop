#pragma once

class myClass {
public :
	myClass();
	myClass(double x, double y);

	double sumX_Y();
	int deepLoop(int loopCount);


private:
	double _x;
	double _y;
};