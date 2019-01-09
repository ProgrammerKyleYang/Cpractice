 ///
 /// @file    Point.cc
 /// @author  kyle(kyleyang58@gmail.com)
 /// @date    2019-01-08 23:00:41
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Point//因为当类中没有显示定义构造函数的时候，编译器会自动提供一个默认（无参）构造函数
{		//在显示定义了构造函数之后，系统就不会再自动提供默认的构造函数了；
	public:
		point(int ix, int iy)
		{
			_ix = ix ;
			_iy = iy ;
			cout << "Point(int,int)" << endl;//point标记法，要是执行了上面两个语句则打印这一行
		}
	void print()
	{
		cout << "()" << _ix
			 << "," << _iy
			 << ")" << endl;
	}
	private:
		int _ix;
		int _iy;

};


int main(void)
{
	Point pt1;//这里是可以调用构造函数的（无参且未初始化）并且可以通过编译。但是结果是乱码，因为还没初始化
	//因为当类中没有显示定义构造函数的时候，编译器会自动提供一个默认（无参）构造函数
	Point pt1(1,2);//此时运行时出错，还未定义
	pt1.print();

	return 0;
}
