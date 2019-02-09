 ///
 /// @file    reference.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-19 20:16:24
 ///
 
#include <iostream>
using std::cout;
using std::endl;

void test()
{
	int number = 10;
	int & ref = number;//引用是一个变量的别名，对引用进行初始化

	cout << "修改之前: " << endl;
	cout << "number: " << number << endl;
	cout << "ref: " << ref << endl;
	ref = 101;
	cout << endl << "修改之后：" << endl;
	cout << "number: " << number << endl;
	cout << "ref: " << ref << endl;
	cout << "&number: " << &number << endl;//输出地址
	cout << "&ref: " << &ref << endl;
	//什么是引用？与指针的区别
	//引用底层实现就是指针 ==》常量指针
	//引用必须要进行初始化，需要绑定一个实体，
	//引用一经绑定之后就不能改变指向
	//int & ref2; 未初始化
}
//引用作为函数的参数进行传递
void swap(int *x, int *y)
{//解引用  间接访问；c常用的方式
	int temp = *x;
	*x = *y;
	*y = temp;
}
void swap2(int &x, int &y)//c++引用的方式
{
	int temp = x;
	x = y;
	y = temp;
}

int * func1 ()
{
	int number = 10;//这种用法也是错误的
	return &number;
}
int & getnumber()
{
	int number = 10;//局部变量值存在于函数的栈空间中，
	return number;//当函数执行完毕后，栈空间已经被销毁了，
				//所以使用return再去操作她它是没有意义的
				//所以会出现报警
}
int &getNumber ()
{
	int number = 10;//这种用法也是错误的
	return number;
}
//不要轻易返回一个堆空间变量的引用，这样做可能会发生内存泄漏(用了之后没回收）
//除非有一个内存回收的策略
int &getHeapVariable ()
{
	int *pNumber = new int(10);
	return *pNumber;//返回变量本身
}
 
int main(void)
{
	test();
	int a = 10 ;
	int b = 17 ;
	cout << "a = " << a << "b= " <<b << endl;
	swap(&a,&b);
	cout << "a = " << a << "b= " <<b << endl;
	swap2(a,b);
	cout << "a = " << a << "b= " <<b << endl;
	return 0;
 
}
