 ///
 /// @file    TestString.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-12 16:14:55
 ///
#include "String.h" 
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	String str1;
	str1.print();

	String str2 = "Hello,world";
	String str3("wangdao");

	str2.print();
	str3.print();
	
	String str4 = str3;//复制构造函数，使用赋值运算符(自己定义）
	str4.print();

	str4 = str2;
	str4.print();

	return 0;
}
