#include "E:\Sources\dotNetLab\ShareLibraryByPInvoke\MyLibrary\mHeader.h"
#include "E:\Sources\dotNetLab\ShareLibraryByPInvoke\MyLibrary\mBody.cpp"

extern "C" __declspec(dllexport) double sumTwo(double varX, double varY) {
	myClass MC(varX, varY);
	return MC.sumX_Y();
}

extern "C" __declspec(dllexport) int deepLoopTest(int loopCount) {
	return myClass().deepLoop(loopCount);
}

/*
	To optimize calculation speed
	Project Properties ->
		C/C++ -> Optimization -> Full Optimization or Maximize Speed
		Code Generation -> Basic Runtime Checks -> Default
*/