 /// / @file    Template.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-26 22:31:37
 ///
 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string; 
template <class T>//模板格式,有编译器自己推导
T add(T x, T y)
{
	cout<<"调用了模板实现"<<endl;
	return x + y;
}

template <class T>//模板与模板之间也可以进行重载
T add(T x, T y, T z)
{
	cout<<"调用了模板实现"<<endl;
	return x + y + z;
}

int add(int x, int y)
{
	cout<<"调用了普通函数实现"<<endl;
	return x + y;
}

int main(void)
{
	int a = 10, b= 29, c=31;
	double da = 1.3, db = 2.3;
	char ca = 'a', cb = 5;
	string sa = "hello", sb = " world";

	cout << "add(a , b)= " << add<int>(a, b) <<endl;//<int>可以加上，变为显示实例化
	cout << "add(a , b)= " << add(a, b) <<endl;//如果已经存在了普通函数，那么会优先调用普通函数，省去推导过程
	cout << "double(da , db)= " << add(da, db) <<endl;
	cout << "char(ca , cb)= " << add(ca, cb) <<endl;
	cout << "string(sa , sb)= " << add(sa, sb) <<endl;
	cout << "(a , db)= " << add<double>(a, db) <<endl;//用普通函数就不能执行
	cout << "(a, db, c)= " << add<int>(a, db, c) <<endl;//用普通函数就不能执行
 
	return 0;
}
