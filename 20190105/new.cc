 //
 /// @file    new.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-19 18:55:03
 ///
#include <string.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;
 

void *test1()//C空间的开辟
{
	int *pInt = (int *)malloc(sizeof(int));//开辟一个动态空间，这个空间位于堆上,malloc位于stdlib.h头文件中
	memset(pInt, 0, sizeof(int));//把空间清零，已备使用,memset位于string.h头文件中
	*pInt = 10;
	cout << "pInt = " << *pInt << endl;
	cout << "pInt = " << pInt << endl;//这样输出的是pInt的地址
	free(pInt);//释放空间	
	return 0;
	//如果不销毁，在使用后return pInt;返回这个空间，就可以接着使用在堆上开辟的这个空间
}
void test2()//C++的空间开辟
{
	int *pInt = new int(17);
	cout << "pInt = " << *pInt << endl;
	cout << "pInt = " << pInt << endl;
	delete  [] pInt;//释放空间
}

int main(void)
{
	test1();
	test2();
	return 0;
}

// new/delete 与 malloc的差别：
// new/delete 是表达式与 malloc是库函数
// new表达式在开辟空间时，只申请空间，不会初始化空间
// malloc也可以开辟一个数组空间
//
// 相同点：
// new/delete 与 malloc/free 都是用于开辟空间的
// 必须成对出现，否则就会有内存泄漏的可能
//
// ——>内存泄漏是指：申请了对空间但是使用之后没有释放（回收），
// 因为堆空间是物理内存的一部分，如果长时间不释放之前的空间，
// 就会导致后期开辟不出新的空间，如有的路由器就有这个现象，
// 长时间运行后可能要重启
// ——>内存踩踏是指：内存重叠，常发生在拷贝过程中，会导致结果不正确
// ——>野指针是指：定义了指针但是未进行复制
//
// malloc底层实现运用了系统调用
// new表达式的底层实现
//

