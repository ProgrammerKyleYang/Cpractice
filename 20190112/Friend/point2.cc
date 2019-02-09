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
};
class Point
{
	//友元值普通函数
	friend  float Line::distance(const Point &lhs, const Point &rhs);
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int, int)" << endl;
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


int main(void)
{
	
	 Point();//匿名对象
	 Point pt0;
	 pt0.print();

	 Point pt1(1,2);
	 Point pt2(3,4);

	 cout << "The distance of ";
	 pt1.print();
	 cout << "---->";
	 pt2.print();
	 //cout << " is: "<< distance(pt1, pt2)<< endl;//方式一
	 cout << " is: "<<Line().distance(pt1, pt2)<< endl;//方式二

	 return 0;
	 
}
