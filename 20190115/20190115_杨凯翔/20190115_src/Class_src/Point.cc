 ///
 /// @file    Point.cc
 /// @author  kyle(kyleyang58@gmail.com)
 /// @date    2019-01-08 23:00:41
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Point
{		
	public:
	Point ()
	: _ix(0)
	, _iy(0)
	{
		cout << "已经调用默认构造函数！"<<endl;
	}

	Point(int ix, int iy= 0)
	{
		_ix = ix ;
		_iy = iy ;
		cout << "Point(int,int)" << endl;
	}

	~Point()
	{
		cout << "已调用析构函数" << endl;
	}

		friend std::ostream &operator<<(std::ostream &os, const Point &rhs);
	private:
		int _ix;
		int _iy;
};
std::ostream &operator<<(std::ostream &os, const Point &rhs)//重载输出流运算符
{
		os << "(" <<rhs._ix
			 << "," <<rhs._iy
			 << ")";
		return os;
}

int test0(void)
{
//	int a(70);
//	cout << "a = "<< a << endl;
//	Point pt1;
//	pt1.print();
//	Point pt2(1,2);
//	pt2.print();
	Point pt3(3,4);//使用了重载的输出语句
	cout << "pt3 = "<< pt3 << endl;
	Point pt4 = 1;//要执行需要隐式转换,符初始值
	cout << "pt4 = "<< pt4 << endl;
	return 0;
}

int main()
{
cout << "即将进入到test0"<<endl;
test0();
cout << "已经退出了test0"<<endl;
return 0;
}




