#include "E:\Sources\\dotNetLab\\NativeLibraryInterop\MyLibrary\\mHeader.h"
#include "E:\Sources\\dotNetLab\\NativeLibraryInterop\MyLibrary\\mBody.cpp"

/*
Project Type:
	Visual C++  ->
		Win32 Project -> DLL --> Empty Project

	To optimize calculation speed
		Project Properties ->
			C/C++ -> Optimization -> Full Optimization or Maximize Speed
			Code Generation -> Basic Runtime Checks -> Default
*/

extern "C" __declspec(dllexport) double sumTwo(double varX, double varY) {
	myClass MC(varX, varY);
	return MC.sumX_Y();
}

extern "C" __declspec(dllexport) int deepLoopTest(int loopCount) {
	return myClass().deepLoop(loopCount);
}