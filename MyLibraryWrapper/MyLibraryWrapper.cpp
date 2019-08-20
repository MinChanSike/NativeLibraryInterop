// This is the main DLL file.

#include "stdafx.h"
#include <vcclr.h>//required for gcroot

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

class NListenerImp : public INativeListener {
public:
	NListenerImp(gcroot<MyLibraryWrapper::MyLib ^> myLibObj) {
		_myLibObj = myLibObj;
	}

	virtual void OnEvent(const NativeEventArgs& args) {
		_myLibObj->FireEvent(args);
	}
private:
	gcroot<MyLibraryWrapper::MyLib ^> _myLibObj;
};

void SysTick(Object^ state, ElapsedEventArgs^ e) {
	DateTime _current = System::DateTime::Now;
	String^ dt_str = String::Format("NOW: @{0}.{1:000}", _current.ToLongTimeString(), _current.Millisecond);
	Console::WriteLine(dt_str);	
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
	_myNativeClass = new myClass(x, y);

	_iEventListener = new NListenerImp(this);
	_myNativeClass->registerListener(_iEventListener);

	//StartTimer();
}

double MyLibraryWrapper::MyLib::getSum() {
	return _myNativeClass->sumX_Y();
}

int MyLibraryWrapper::MyLib::deepLoopTest(int loopCount) {
	return _myNativeClass->deepLoop(loopCount);
}

void MyLibraryWrapper::MyLib::pokeNativeEvent(String ^ msg) {
	std::string dMsg;
	Extensions::MarshalString(msg, dMsg);
	_myNativeClass->pokeEvent(dMsg);
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

