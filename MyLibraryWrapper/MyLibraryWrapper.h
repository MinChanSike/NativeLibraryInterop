// MyLibraryWrapper.h

#pragma once
#include "E:\\Sources\\dotNetLab\\ShareLibraryByWrapper\\MyLibrary\\mHeader.h"
#include "E:\\Sources\\dotNetLab\\ShareLibraryByWrapper\\MyLibrary\\mBody.cpp"
using namespace System;


namespace MyLibraryWrapper {

	public ref class MyLib {

	public:
		MyLib(double x, double y);
		double getSum();
		int deepLoopTest(int loopCount);

	private:
		myClass* myClassInstance;

	};
}
