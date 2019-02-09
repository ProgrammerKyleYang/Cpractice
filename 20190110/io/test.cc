 ///
 /// @file    test.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-15 23:36:35
 ///
#include <string>
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::printf;
 
int main(void)
{

	cout << "sizeof(cout)" << sizeof(cout)<< endl;
	cout << "sizeof(cin)" << sizeof(cin)<< endl;
	//cout << "sizeof(printf)" << sizeof(printf)<< endl;
	//printf不是对象，不能通过上面方法来看大小
	//是位于stdio.h头文件中
}
