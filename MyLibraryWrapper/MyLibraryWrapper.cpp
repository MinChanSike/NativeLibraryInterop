// This is the main DLL file.

#include "stdafx.h"
#include "MyLibraryWrapper.h"
#include "E:\\Sources\\dotNetLab\\ShareLibraryByWrapper\\MyLibrary\\mHeader.h"
#include "E:\\Sources\\dotNetLab\\ShareLibraryByWrapper\\MyLibrary\\mBody.cpp"


MyLibraryWrapper::MyLib::MyLib(double x, double y) {
	myClassInstance = new myClass(x, y);

}

double MyLibraryWrapper::MyLib::getSum() {
	return myClassInstance->sumX_Y();
}

int MyLibraryWrapper::MyLib::deepLoopTest(int loopCount) {
	return myClassInstance->deepLoop(loopCount);
}