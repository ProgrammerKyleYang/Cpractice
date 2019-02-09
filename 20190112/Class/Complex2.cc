 //// @file    Complex.cc / @author    kyle(kyleyang58@gmail.com) / @date    2019-01-23 23:37:37
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Complex
{
public:
	Complex(double dreal = 0, double dimag = 0)
	: _dreal(dreal)
	, _dimag(dimag)
	{
		cout<< "构造一个新的点" << endl;
	}
	~Complex()
	{
		cout <<"调用析构函数"<<endl;
	}

	void print() const
	{
		cout << _dreal << " + " << _dimag <<"i" << endl;
	}
//以友元函数进重载，对比Complex1.cc来说就不用反复定义get()函数，使代码简洁
	friend
	Complex operator+(const Complex &lhs, const Complex &rhs);
                                       	
private:                               	
	double _dreal;                     	
	double _dimag;                     	
};

Complex operator+(const Complex &lhs, const Complex &rhs)
{
	cout<< "对 “ + ” 进行重载" << endl;
	return Complex(lhs._dreal + rhs._dreal,
				   lhs._dimag + rhs._dimag);
}
int main(void)
{
	Complex c1(1, 2);
	cout << "c1 = ";
	c1.print();
	
	Complex c2(3, 4);
	cout << "c2 = ";
	c2.print();

	Complex c3 = c1 + c2;
	cout << "c3 = ";
	c3.print();

	return 0;
}
