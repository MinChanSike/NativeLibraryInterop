// This is the main DLL file.

#include "stdafx.h"
#include "MyLibraryWrapper.h"
#include "E:\Sources\\dotNetLab\\NativeLibraryInterop\MyLibrary\\mHeader.h"
#include "E:\Sources\\dotNetLab\\NativeLibraryInterop\MyLibrary\\mBody.cpp"
#include "Extensions.cpp"

/*
	Project Type:
		Visual C++  -> CLR -> Class Library		 
*/
MyLibraryWrapper::MyLib::MyLib(double x, double y) {
	myClassInstance = new myClass(x, y);

}

double MyLibraryWrapper::MyLib::getSum() {
	return myClassInstance->sumX_Y();
}

int MyLibraryWrapper::MyLib::deepLoopTest(int loopCount) {
	return myClassInstance->deepLoop(loopCount);
}

String ^ MyLibraryWrapper::MyLib::passString(String ^ strParam) {
	std::string dStrParam;
	Extensions::MarshalString(strParam, dStrParam);
	dStrParam = dStrParam + " (Received)";
	return Extensions::ConvertToSystemString(dStrParam);
}

String ^ MyLibraryWrapper::MyLib::passObject(CustomObj ^ objParam) {
	String ^ objStr = objParam->FirstProp + ", " + objParam->SecondProp + ", " + objParam->ThirdProp + " (Received)";
	return objStr;
}
