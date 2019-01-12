 ///
 /// @file    TestComputer.cc
 /// @author  kyle(kyleyang58@gmail.com)
 /// @date    2019-01-08 22:33:11
 ///
#include "Computer.h" 
#include <iostream>
using std::cout;
using std::endl;

void test1()
{
	Computer com1("Surface",9999);
	com1.print();
	Computer com2 = com1;
	com2.print();
	
}

int main(void)
{	
	test1();
	return 0;
}
