 ///
 /// @file    Thread.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-02-10 21:27:30
 ///
#include "Thread.h" 
#include <iostream>
using std::cout;
using std::endl;
namespace wd
{
Thread:: Thread()
: _pthid(0)
, _isRuning(false)
{}

Thread:: ~Thread()
{
	if(_isRuning){
		pthread_detach(_pthid);//detach功能是在一个detach线程结束后资源会被自动回收
		_isRuning = false;
	}
}
void Thread:: start()
{
	pthread_create(&_pthid, NULL, threadFunc, this);//第四个参数是给线程传参的
	_isRuning = true;
	
}
void Thread::join()
{
	if(_isRuning){
		pthread_join(_pthid,NULL);
		_isRuning = false;
	}
}
void * Thread::threadFunc(void *arg)
{
	Thread *p = static_cast<Thread *>(arg);
	if(p)
		p->run();//虚函数使用需要一个对象去调用
	return NULL;
}
}//end of wd
