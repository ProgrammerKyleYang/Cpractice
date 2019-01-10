 ///
 /// @file    Point.cc
 /// @author  kyle(kyleyang58@gmail.com)
 /// @date    2019-01-08 23:00:41
 ///
#include <iostream>
using std::cout;
using std::endl;
class Test
{		//在显示定义了构造函数之后，系统就不会再自动提供默认的构造函数了；
	public://构造函数的作用就是用来构造数据成员的
	Test (int value)
	: _iy(value)
	, _ix(_iy)
	{
		cout << "Test(int)"<<endl;
	}
//	Test(int ix, int iy)//显示定义的构造函数后，系统就不会提供默认构造函数，
//	{
//		_ix = ix ;
//		_iy = iy ;
//		cout << "Test(int,int)" << endl;//point标记法，要是执行了上面两个语句则打印这一行
//	}
	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}
	private:
		int _iy;
		int _ix;
};

int main(void)
{
	Test test(1);
	test.print();
	return 0;
}
