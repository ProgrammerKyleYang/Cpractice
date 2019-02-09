 ///
 /// @file    VariadicTemplates.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-27 20:23:57
 ///
#include <string> 
#include <iostream>
using std::cout;
using std::endl;
using std::string;
 
template <typename... Args>//Args模板参数包
void print(Args... args)//args函数参数包
{
	cout<< "参数包Args中元素个数[sizeof... (Args)]= "
		<< sizeof...(Args) << endl;
	cout<< "参数包args中元素个数[sizeof... (args)]= "
		<< sizeof...(args) << endl;
}
//display()递归条件的出口
//是一个自顶向下


void display()
{
	cout << endl;//递归调用出口
}

template <class T, class... Args>
void display(T t, Args... args)//函数参数包递声明时...在左边
{
	cout << t << " ";
	display(args...);//当三个点放在函数函数参数包右边的时候表示对参数包进行展开
	//递归调用打印
}

template <class T>
T sum(T t)
{
	return t;
}

template <class T, class... Args>
T sum(T t, Args... args)
{
	return t + sum(args...);
}

void test0()
{
	cout<< "sum (1, 2, 3, 4, 5) = "
		<< sum(1, 2, 3, 4, 5)
		<< endl;
}

int test1()//打印元素个数
{
	string s1 = "world";
	print(3, 4.4, "hello", 'c');
	print(2, 5);
	print('a', true, "hello", s1);
	print();
	return 0;
}

int test2()//打印元素内容,使用递归调用
{
	string s1 = "world";
	display(3, 4.4, "hello", 'c');
	display(2, 5);
	display('a', true, "hello", s1);
	display();
	return 0;
}

int main(void)
{
	test0();
	test1();
	test2();
	return 0;
}
