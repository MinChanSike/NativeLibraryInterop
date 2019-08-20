#pragma once

#include "mHeader.h"
#include "mBody.cpp"
#include "CustomObj.cpp"
#include "DotNetEventArg.cpp"

using namespace System;

namespace MyLibraryWrapper {

	public ref class MyLib {

	public:
		MyLib(double x, double y);
		double getSum();
		int deepLoopTest(int loopCount);
		void pokeNativeEvent(String ^ msg);
		
		String ^ passString(String^ strParam);
		String ^ passObject(CustomObj ^ objParam);
		delegate void DotNetEventHandler(DotNetEventArg^ arg);
		event DotNetEventHandler^ OnEventHappen;

	private:
		myClass* _myNativeClass;
		INativeListener* _iEventListener;

	internal:	
		void FireEvent(const NativeEventArgs& args) {
			//you can make necessary transformation between native types and .net types

			//create .net argument using native argument
			//required conversion is done by DotNetEventArg class
			DotNetEventArg^ dotNetArgs = gcnew DotNetEventArg(args);

			//fire .net event
			OnEventHappen(dotNetArgs);
		}
	};
}
