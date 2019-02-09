 ///
 /// @file    Point2.cc
 /// @author  kyle(kyleyang58@gmail.com)
 /// @date    2019-01-11 21:25:17
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Point
{		
	public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int = 0, int = 0)"<<endl;
		cout << "已完成初始化"<<endl;
	}

	Point(const Point & rhs)//系统提供的复制构造函数
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	{
		cout << "调用了系统中的复制构造函数"<< endl;
	}

	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}
	~Point()
	{
		cout << "已调用析构函数" << endl;
	}

	private:
		int _ix;
		int _iy;

};

int test0(void)
{
	Point pt1(1,2);
	cout << "pt1 = ";
	pt1.print();
//	Point pt2(3,4);
	Point pt2(pt1);//这两行语句相当于执行了int a = 7 ; int b = a;
	cout << "pt2 = ";
	pt2.print();//cout<< "a = " << a << endl; cout<< "b = " << b << endl;
				//52行代码调用了拷贝构造函数
	return 0;
}

int main()
{
cout << "即将进入到test0"<<endl;
test0();
cout << "已经退出了test0"<<endl;
return 0;
}




