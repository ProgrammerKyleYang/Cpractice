 ///
 /// @file    inline.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-20 19:56:59
 ///
 
#include <iostream>
using std::cout;
using std::endl;

#define multiply(x,y) ((x)*(y))//这样没有开销，代码执行效率高
								//这里加上括号是进行保护，防止出错

//inline 函数
//inline 函数的效果与上面带参数的宏定义效果是一样的
//同时还可以进行编译，安全性要比带参数的宏定义高
//inline 函数不能分成头文件和实现文件，必须放到一起
//inline 函数尽量不要使用for 循环
//eg:

inline //内联函数
int divide(int x, int y)
{
	return x/y;	//比起带参宏定义更方便自定义
}

int main(void)
{
	int a = 8; int b = 4;
	cout << multiply(a, b) <<endl;
	cout << divide(a, b) <<endl;
	return 0;
}
