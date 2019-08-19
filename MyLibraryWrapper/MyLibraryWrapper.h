// MyLibraryWrapper.h

#pragma once
#include "mHeader.h"
#include "mBody.cpp"
#include "CustomObj.cpp"

using namespace System;

namespace MyLibraryWrapper {

	public ref class MyLib {

	public:
		MyLib(double x, double y);
		double getSum();
		int deepLoopTest(int loopCount);
		
		String ^ passString(String^ strParam);
		String ^ passObject(CustomObj ^ objParam);

	private:
		myClass* myClassInstance;

	};
}
