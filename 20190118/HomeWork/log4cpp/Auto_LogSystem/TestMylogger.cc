 ///
 /// @file    TestMylogger.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-02-08 11:52:25
 ///
 
#include "Mylogger.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
 
int main(void)
{
	//logWarn("this is a warn message%s ","hello");
//	logWarn("this is a warn message%s ");
	logInfo("this is a info message");
	logError("this is a error message");
	logDebug("this is a debug message");

	return 0;
}
