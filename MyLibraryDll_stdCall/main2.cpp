#include "E:\Sources\dotNetLab\ShareLibraryByPInvoke\MyLibrary\mHeader.h"
#include "E:\Sources\dotNetLab\ShareLibraryByPInvoke\MyLibrary\mBody.cpp"

double _stdcall sumTwo(double varX, double varY) {
	myClass MC(varX, varY);
	return MC.sumX_Y();
}

int _stdcall deepLoopTest(int loopCount) {
	return myClass().deepLoop(loopCount);
}

int _stdcall testFun() {
	return 123456789;
}

/*
	To optimize calculation speed
		Project Properties ->
			C/C++ -> Optimization -> Full Optimization or Maximize Speed
			Code Generation -> Basic Runtime Checks -> Default

	Add dodule definition definition file
		Project Properties ->
			Linker -> Input -> Module Definition File -> ExportDefinition.def
		
		*Export function name on def file are shoud not be the same on child inplementation.
*/	