 ///
 /// @file    Testlogsystem.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-22 08:32:07
 ///
#include "Logsystem.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using namespace wd;

void test0()
{
	Logsystem::getInstance()->error(prefix("this is an error messages!"));
	Logsystem::getInstance()->warn("this is an warn messages!");
	Logsystem::getInstance()->info("this is an info messages!");
	Logsystem::getInstance()->debug("this is an debug  messages!");

	cout << "Logsystem::Priority::WARN = "<< Logsystem::Priority::WARN <<endl; 
	cout << "Logsystem::Priority::ERROR= "<< Logsystem::Priority::ERROR<<endl;
	cout << "Logsystem::Priority::INFO= "<< Logsystem::Priority::INFO<<endl; 
	cout << "Logsystem::Priority::DEBUG= "<< Logsystem::Priority::DEBUG<<endl; 
	Logsystem::getInstance()->setPriority(Logsystem::Priority::WARN);
}
void test1()
{
	cout << __FILE__ << " " << __LINE__ << " " << __FUNCTION__ << endl;
}

void test2()
{
	LogWarn("this is a error message!");
	LogInfo("this is a error message!");
	LogDebug("this is a error message!");
}

 
int main(void)
{
	test1();
	return 0;
}
