 ///
 /// @file    point.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-23 21:10:40
 ///
#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

class Point;//类的前项声明，使得Line类可以正常调用
			//之后再去定义class Point
class Line
{
public:
	float distance(const Point &lhs, const Point &rhs);
	void setPoint( Point &lhs, int ix, int iy);
};
class Point
{
	friend Line; //友元类
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "初始化一个点" << endl;
	}
	~Point()
	{
		cout << "~Point()" << endl;
	}
	void print()
	{
		cout<< "(" << _ix
			<< "," << _iy
			<< ")" ;
	}

private:
	int _ix;
	int _iy;	
};

float Line::distance(const Point &lhs, const Point &rhs)
{
	return hypot(lhs._ix - rhs._ix, lhs._iy - rhs._iy);//在类之外访问私有成员是不行的，要变为友元
}

void Line::setPoint( Point &pt, int ix, int iy)
{
	pt._ix = ix;
	pt._iy = iy;
}

int main(void)
{

	Point pt1(1,2);
	Point pt2(3,4);

	cout << "The distance of ";
	pt1.print();
	cout << "---->";
	pt2.print();
	cout << " is: "<<Line().distance(pt1, pt2)<< endl;//方式二

	Line line;
	line.setPoint(pt1, 10, 15);
	cout << "The pt1 had changed to: ";
	pt1.print();
	
	cout<< endl << "The distance of ";
	pt1.print();
	cout << "---->";
	pt2.print();
	cout << " is: "<<Line().distance(pt1, pt2)<< endl;//方式三

	return 0;
}
