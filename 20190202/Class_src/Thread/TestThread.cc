 ///
 /// @file    TestThread.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-02-10 22:11:24
 ///
#include "Thread.h" 
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;
 
class MyThread
: public wd::Thread//继承WD空间中的Thread
{
	void run() override//重定义
	{
		int cnt = 10;
		::srand(::clock());
		while(cnt--){
			int number = ::rand() % 100;
			cout<< "sub Thread "<< pthread_self()
				<< ": getNumber = "<< number<< endl;
			::sleep(1);
		}
	}

public:
	~MyThread()
	{
		cout << "~MyThread()" << endl;
	}
};
void test0()
{
	cout << "main Thread "<< pthread_self() << endl;
	unique_ptr<wd::Thread> mythread(new MyThread());
	mythread->start();
	mythread->join();

}
void test1()
{
	cout << "main Thread "<< pthread_self() << endl;
	MyThread mythread;
	mythread.start();
	mythread.join();

	//MyThread mythread2(mythread);//线程不可以被复制，所以这个操作应该被禁止
	//定义个头文件，让这个类继承不能被复制
}
int main(void)
{
	test0();
	return 0;
}
