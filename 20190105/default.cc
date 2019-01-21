 ///
 /// @file    add.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-20 19:24:26
 ///
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;
#ifdef __cpluspluse
extern "C"
{
#endif
int add2(int x, int y)
{
return x + y ;
}
#ifdef __cpluspluse
extern "C"
}// end of extern "C"
#endif

int add (int x , int y=8, int z=3)//默认参数的额设置必须是从右到左进行
{
	return x + y + z;
}

int main(void)
{
 int a = 2, b = 3, c = 4;
 printf("add(a,b) = %d\n",add(a, b));//使用默认构造函数
 printf("add(a,b) = %d\n",add2(a, b));//按照C语言必须要重新定义
 printf("add(a,b,c) = %d\n",add(a, b,c));
 cout << "add (a + b + c= )"<< add(a, b, c)<< endl;
 return 0;
}
