 ///
 /// @file    Thread.h
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-02-10 20:49:51
 ///

#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

namespace wd
{
class Thread
{
public:
	Thread();
	virtual
	~Thread();
	void start();//开启子线程
	void join();//回收子线程
	bool isRuning() const {return _isRuning;}//获取线程的状态，看是否还在运行
private:
	virtual void run() = 0;//纯虚函数，作为一个接口存在
	//静态成员函数不带this指针
	static void *threadFunc(void *);
private:
	pthread_t _pthid;
	bool _isRuning;
};

}//wd

#endif
