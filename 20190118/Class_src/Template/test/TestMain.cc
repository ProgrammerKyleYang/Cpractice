 ///
 /// @file    TestMain.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-26 23:27:12
 ///
#include "test.h"
//必须要全部加载才行，只加载一个头文件不能进行
//要看到所有程序的实现才能进行推导
//所以要在头文件中加载.cc文件
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
 
int main(void)
{
	int a = 10, b= 29;
	double da = 1.3, db = 2.3;
	char ca = 'a', cb = 5;
	string sa = "hello", sb = " world";

	cout << "add(a , b)= " << add<int>(a, b) <<endl;//<int>可以加上，变为显示实例化
	cout << "add(a , b)= " << add(a, b) <<endl;//如果已经存在了普通函数，那么会优先调用普通函数，省去推导过程
	cout << "double(da , db)= " << add(da, db) <<endl;
	cout << "char(ca , cb)= " << add(ca, cb) <<endl;
	cout << "string(sa , sb)= " << add(sa, sb) <<endl;
	cout << "(a , db)= " << add<double>(a, db) <<endl;//用普通函数就不能执行
 
	return 0;
}
