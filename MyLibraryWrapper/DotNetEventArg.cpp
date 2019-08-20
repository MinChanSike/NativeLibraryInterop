#pragma once

#include "stdafx.h"
#include "NativeEventArgs.h"

using namespace System;
using namespace System::Runtime::InteropServices;

//.net equvelant of the argument class
public ref class DotNetEventArg {
internal:

	//contructor takes native version of argument to transform
	DotNetEventArg(const NativeEventArgs& args) {

		//assign primitives naturally
		argInt32 = args.argInt32;

		//convert wide string to CLR string
		argWString = Marshal::PtrToStringUni(IntPtr((void*)args.argWString));

		//convert 8-bit native string to CLR string
		argString = Marshal::PtrToStringAnsi(IntPtr((void*)args.argString));

		//see Marshal class for rich set of conversion methods (e.g. buffers)
	}
private:
	String^ argString;
	String^ argWString;
	Int32 argInt32;

public:
	//define properties
	property String^ ArgString {
		String^ get() {
			return argString;
		}
	}

	property String^ ArgWString {
		String^ get() {
			return argWString;
		}
	}

	property Int32 ArgInt32 {
		Int32 get() {
			return argInt32;
		}
	}
};