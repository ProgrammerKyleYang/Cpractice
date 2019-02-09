 ///
 /// @file    Line.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-24 22:26:26
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point()
	: _ix(0)
	, _iy(0)
	{
		cout << "Point()" << endl;
	}
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point (int, int)" <<endl;
	}
	~Point()
	{
		cout << "调用析构函数" <<endl;
	}
	void printPoint() const
	{
		cout<< "(" << _ix
			<< "," << _iy
			<< ")" ;
	}

private:
	int _ix;
	int _iy;


};

class Line
{
public:
	class Point
	{
	public:
		Point()
		: _ix(0)
		, _iy(0)
		{
			cout << "Point()" << endl;
		}
		Point(int ix = 0, int iy = 0)
		: _ix(ix)
		, _iy(iy)
		{
			cout << "Point (int, int)" <<endl;
		}
		~Point()
		{
			cout << "调用析构函数" <<endl;
		}
		void printPoint() const
		{
			cout<< "(" << _ix
				<< "," << _iy
				<< ")" ;
		}
	
	private:
		int _ix;
		int _iy;
	};	

	Line(int x1, int y1, int x2, int y2)
	: _pt1(x1, y1)
	, _pt2(x2, y2)
	{
		cout << "Line: " << endl;	
	}

	void printLine()
	{
		_pt1.printPoint();
		cout << "——————>" ;
		_pt2.printPoint();
		cout << endl;
	}

private:
	Point _pt1;
	Point _pt2;
	 
};

int main(void)
{
	Line line (1, 2, 3, 5) ;
	line.printLine();
	Line::Point pt(1, 6) ;//在类中调用类，使用作用域限定符 :: 也是可以创立一个对象的
							//要是不希望别人调用，把public去掉就好，类中成员默认是私有的
	pt.printPoint();
	return 0;
}
