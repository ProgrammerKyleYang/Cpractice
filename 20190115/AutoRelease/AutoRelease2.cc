 ///
 /// @file    AutoRelease1.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-23 23:18:21
 ///
//编译时要加载库文件 -lpthread 
#include <iostream>
using std::cout;
using std::endl;

//方法三：
//		atexit + pthread_once	
//		平台相关的方法
class Singleton
{
public:
	static Singleton * getInstance()
	{
	//这样多线程下线程安全的
		pthread_once(&_once, init);
		return _pInstance;
	}
	static void destory()
	{
		if(_pInstance)	
			delete _pInstance;//放在析构函数中可以自动执行，可以达到自动回收的效果
							//可以创立一个对象
	}
	void print() const
	{
		cout << "Singleton::print()使用对象" << endl;	
	}

	static void init()
	{
		_pInstance = new Singleton();
		::atexit(destory);
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
	Singleton(){cout << "Singleton()创建对象"<<endl;}
	~Singleton(){cout << "~Singleton()自动释放对象"<<endl;}
private:
	static Singleton *_pInstance;
	static pthread_once_t _once;
};

Singleton *Singleton::_pInstance =nullptr ;//使用懒汉模式，不调用一开始就不构造
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

int main(void)
{
	//Singleton::getInstance()->print();
	//Singleton::distory();
	
	Singleton *p1 = Singleton::getInstance();
	p1->print();

	return 0;
}

