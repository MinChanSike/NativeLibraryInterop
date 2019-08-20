#pragma once

#include "NativeEventArgs.h"

//https://stackoverflow.com/a/9931869/2728908
//A simple mechanism to fire an event from native code.
//Your library may have a DIFFERENT triggering mechanism (e.g. function pointers)
class INativeListener {
public:
	virtual void OnEvent(const NativeEventArgs& args) = 0;
};
