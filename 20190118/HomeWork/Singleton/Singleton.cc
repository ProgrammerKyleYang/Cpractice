 ///
 /// @file    Singleton.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-30 22:00:48
 ///
#include <string> 
#include <iostream>
using std::cout;
using std::endl;
using std::string;
class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout <<"Point()！" << endl;
	}
	~Point()
	{
		cout<<"~Point()"<<endl;
	}

	friend std::ostream & operator << (std::ostream& os, const Point &rhs);

private:
	int _ix;
	int _iy;
};
std::ostream & operator << (std::ostream& os, const Point &rhs)
{
	os << "("
	   << rhs._ix 
	   << ","
	   << rhs._iy
	   << ")" ;
	return os;
}
class Computer
{
public:
	Computer(string ix = "null", int iy = 2)
	: _ix(ix)
	, _iy(iy)
	{
		cout <<"Computer()！" << endl;
	}
	~Computer()
	{
		cout<<"~Computer()"<<endl;
	}

	friend std::ostream & operator << (std::ostream& os, const Computer &rhs);

private:
	string _ix;
	int _iy;
};
std::ostream & operator << (std::ostream& os, const Computer &rhs)
{
	os << "("
	   << rhs._ix 
	   << ","
	   << rhs._iy
	   << ")" ;
	return os;
}
template <class T>
class Singleton
{
public:
	template <class ...Args>
	static T * getInstance(Args... args)
	{
		if(nullptr == _ptr)
		{
			_ptr = new T(args...);
		}	
		return _ptr;
	}
	static void distory()
	{
		if(_ptr)
			delete _ptr;
	}
	static T * _ptr;
	Singleton()
	{
		cout << "Singleton()" <<endl;
	}
	~Singleton()
	{
		cout << "~Singleton()" <<endl;
	}
};

template <class T>
T * Singleton<T>::_ptr;

int main(void)
{
	Point *ptr1 = Singleton<Point>::getInstance(1);
	cout << ptr1 <<endl;
	Point *ptr2 = Singleton<Point>::getInstance(3,4);
	cout <<ptr2<< endl;
	cout <<*ptr2<< endl;
	Singleton<Point>::distory();
	Computer *computer0 = Singleton<Computer>::getInstance("Huawei", 8888);
	cout << computer0 <<endl;
	Computer *computer1 = Singleton<Computer>::getInstance("xiaomi",6666);
	cout <<computer1<< endl;
	cout <<*computer1<< endl;
	Singleton<Computer>::distory();
	return 0;
}


#if 0
class Computer;

Point pt(1, 2);
Point pt2(3, 4);

Computer com("Mac", 8888);

int main(void)
{
   Computer * p1 = Singleton<Computer>::getInstance("Xiaomi", 6666);
   Computer * p2 = Singleton<Computer>::getInstance("Xiaomi", 6666);

   Point　* p3 = Singleton<Point>::getInstance(1, 2);
   Point　* p4 = Singleton<Point>::getInstance(1, 2);

   return 0;
} 
#endif

