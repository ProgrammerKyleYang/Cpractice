 ///
 /// @file    AutoRelease1.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-23 23:18:21
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//方法一：
//		嵌套类+静态对象
//方法二：
//		atexit + 饱汉模式（防止破坏线程安全）
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
    class AutoRelease
	{                //为Singleton创立
    public:
        AutoRelease()
        {
            cout << "创建AutoRelease()对象" << endl;
        }
        ~AutoRelease()
        {
            if (_pInstance)//存在_pInstance的话可以直接释放
                delete _pInstance;
            cout << "~AutoRelease()自动释放" << endl; }
    };
private:
	Singleton(){cout << "Singleton()"<<endl;}
	~Singleton(){cout << "~Singleton()"<<endl;}
private:
	static Singleton *_pInstance;
	static AutoRelease _auto;

};

Singleton *Singleton::_pInstance =getInstance() ;
//Singleton *Singleton::_pInstance =nullptr ;//懒汉模式，不调用一开始就不构造

Singleton::AutoRelease Singleton::_auto;//饱汉模式

int main(void)
{
	//Singleton::getInstance()->print();
	//Singleton::distory();
	
	Singleton *p1 = Singleton::getInstance();
	p1->print();

	return 0;
}

