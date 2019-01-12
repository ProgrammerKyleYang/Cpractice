 //
 /// @file    TestComputer.cc
 /// @author  kyle(kyleyang58@gmail.com)
 /// @date    2019-01-08 22:33:11
 ///
#include "Computer.h" 
#include <iostream>
using std::cout;
using std::endl;

Computer gComputer("Mi",6666);

int main(void)
{	
	gComputer.print();
	Computer computer("Lenovo_Thinkpad",6758);
	computer.print();
	Computer * pc = new Computer("Macbook pro",11111);
	pc->print();
	delete pc;
	//computer.setBrand("Lenovo");
	//computer.setPrice(5555);
//	computer._brand = "Thinkpad";//error！_brand是一个私有成员变量，不可以直接赋值
//	computer._price = 8888;
	return 0;
}
