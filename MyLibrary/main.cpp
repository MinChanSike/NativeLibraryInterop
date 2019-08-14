#include <iostream>
#include <time.h>
#include "mHeader.h"


/*
	Project Type: 
		Visual C++  -> 
				Win32 Project -> Console Application --> Empty Project

	To optimize calculation speed
		Project Properties ->
			C/C++ -> Optimization -> Full Optimization or Maximize Speed
			Code Generation -> Basic Runtime Checks -> Default
*/
int main() {
	myClass myClassInstance(10, 5);
	double result = myClassInstance.sumX_Y();
	std::cout << "Sum result  " << result << std::endl;

	time_t start = time(0);
	std::cout << "Starting at " << start << std::endl;
	int dResult = myClassInstance.deepLoop(50000);	 
	time_t end = time(0);
	std::cout << "Ending at " << end << std::endl;
	std::cout << "Total Duration: " << end-start << std::endl;

	std::cin.get();
	return 0;
}

