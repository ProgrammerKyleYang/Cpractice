 ///
 /// @file    Singleton.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-24 23:03:24
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Singleton
{
public:
	static Singleton * getInstance()
	{
		if(nullptr == _pInstance)
			_pInstance = new Singleton();
		return _pInstance;
	}
	static void distory()
	{
		if(_pInstance)	
			delete _pInstance;//放在析构函数中可以自动执行，可以达到自动回收的效果
							//可以创立一个对象
	}
	void print() const
	{
		cout << "Singleton::print()" << endl;	
	}
private:
	static Singleton *_pInstance;

	Singleton(){cout << "Singleton()"<<endl;}
	~Singleton(){cout << "~Singleton()"<<endl;}
};

Singleton *Singleton::_pInstance = nullptr;

int main(void)
{
	Singleton::getInstance()->print();
	Singleton::distory();
	return 0;
}

