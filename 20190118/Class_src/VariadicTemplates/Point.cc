 ///
 /// @file    Point.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-27 19:52:18
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Point
{		
	public:
	Point(double ix= 0, double iy= 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "初始化完成！"<<endl;
	}
//	普通成员函数模板，模板参数可以设置成默认值，如这里的int
//	也可以自己指出，如下<double>
	template <class T = int>
	T func()
	{
		return (T)_ix;
	}

	~Point()
	{
		cout << "已调用析构函数" << endl;
	}

	friend std::ostream &operator<<(std::ostream &os, const Point &rhs);
private:
	double _ix;
	double _iy;
};

std::ostream &operator<<(std::ostream &os, const Point &rhs)//重载输出流运算符
{
	os << "(" <<rhs._ix
		<< "," <<rhs._iy
		<< ")";
	return os;
}

double test0(void)
{
	Point pt(2.3,5.7);//使用了重载的输出语句
	cout << "pt = "<< pt.func<double>() << endl;
	cout << "pt = "<< pt.func() << endl;
	return 0;
}
int main(void)
{
	test0(); 
	return 0;
}
