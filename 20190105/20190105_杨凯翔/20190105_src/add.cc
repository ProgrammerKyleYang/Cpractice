 ///
 /// @file    add.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-20 19:24:26
 ///
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;
//C++支持函数重载，在函数名相同的时候会根据参数的类型、个数顺序进行改编

/*用C的方式调用
  不进行名字改编*/

//#ifdef __cpluspluse
//extern "C"
//{
//#endif

/*用C++的方式调用
  进行名字改编*/

int add (int x, int y)
{
return x + y ;
}

//#ifdef __cpluspluse
//extern "C"
//}// end of extern "C"
//#endif

int add (int x, int y, int z)
{
	return x + y + z;
}

int main(void)
{
 int a = 2, b = 3, c = 4;
 printf("add(a,b) = %d\n",add(a, b));
 printf("add(a,b,c) = %d\n",add(a, b,c));
 cout << "add (a + b + c= )"<< add(a, b, c)<< endl;
 return 0;
}
