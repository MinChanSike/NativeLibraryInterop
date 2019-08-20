#pragma once 

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
using namespace System;

namespace MyLibraryWrapper {
	class Extensions {
	public:
		static void MarshalString(String ^ sysStr, string& ntStr) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(sysStr)).ToPointer();
			ntStr = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}

		static void MarshalString(String ^ sysStr, wstring& ntwStr) {
			using namespace Runtime::InteropServices;			
			const wchar_t* chars =
				(const wchar_t*)(Marshal::StringToHGlobalUni(sysStr)).ToPointer();
			ntwStr = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}

		static String ^ ConvertToSystemString(const string& ntStr) {
			String ^ result = gcnew String(ntStr.c_str());
			return result;
		}

	};
}
