#pragma once

//https://stackoverflow.com/a/9931869/2728908
//An argument class to wrap event parameters
class NativeEventArgs {
public:
	//a 32bit integer argument
	//any other primitives can be here, just be careful about the byte size
	int argInt32;

	//null terminated ascii string
	const char* argString;

	//null terminated wide/unicode string
	const wchar_t* argWString;
};
