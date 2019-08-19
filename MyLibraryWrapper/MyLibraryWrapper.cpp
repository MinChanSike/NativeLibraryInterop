// This is the main DLL file.

#include "stdafx.h"
#include "MyLibraryWrapper.h"
#include "mHeader.h"
#include "mBody.cpp"
#include "Extensions.cpp"

/*
	Project Type:
		Visual C++  -> CLR -> Class Library
*/
using namespace System;
using namespace System::Timers;
using namespace System::Threading;


void SysTick(Object^ state, ElapsedEventArgs^ e)
{
	DateTime _current = System::DateTime::Now;
	String^ dt_str = String::Format("NOW: @{0}.{1:000}", _current.ToLongTimeString(), _current.Millisecond);
	Console::WriteLine(dt_str);	 

	//MyLibraryWrapper::MyLib::onMyEventHappen("Hay..");
}

static void StartTimer() {
	System::Timers::Timer^ sys_tick = gcnew System::Timers::Timer(1000);
	sys_tick->BeginInit();
	sys_tick->AutoReset = true;
	sys_tick->Elapsed += gcnew ElapsedEventHandler(SysTick);
	sys_tick->EndInit();
	sys_tick->Start();
}

MyLibraryWrapper::MyLib::MyLib(double x, double y) {
	myClassInstance = new myClass(x, y);
	
	//StartTimer();
}

double MyLibraryWrapper::MyLib::getSum() {
	onMyEventHappen("Hay, I send out from get sum method.");
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
