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
	{	if (_dreal == 0 && _dimag == 0){
			cout << 0;
			return ;
		}
		else if(_dreal == 0){//_dimag!=0
			cout << _dimag << "i" << endl;
		}
		else{//_dreal != 0情况
			cout << _dreal;
			if(_dimag > 0)
				cout << "+" << _dimag <<endl;
			else if (_dimag <0){
				cout << " - "<<(-1)*_dimag << endl;
			}
			else
				cout << endl;
		}
		cout << _dreal << " + " << _dimag <<"i" << endl;
	}
//以成员函数形式进行重载
Complex operator+(const Complex &rhs)
{
	return Complex(_dreal + rhs._dreal,
				   _dimag + rhs._dimag);
}
                                       	
private:                               	
	double _dreal;                     	
	double _dimag;                     	
};

//Complex operator+(const Complex &lhs, const Complex &rhs)
//{
//	cout<< "对 “ + ” 进行重载" << endl;
//	return Complex(lhs._dreal + rhs._dreal,
//				   lhs._dimag + rhs._dimag);
//}
int main(void)
{
	int a = 3, b = 4;
	a += b;//这里推荐以成员函数的形式进行重载，因为a本身已经发生了变化

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
