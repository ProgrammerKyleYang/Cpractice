 ///
 /// @file    pthreadTest.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-02-09 21:15:06
 ///
#include <unistd.h>
#include <stdio.h>
#include <pthread.h> 
#include <iostream>
using std::cout;
using std::endl;
//线程执行依赖于进程本生，
//当进程执行结束时，线程也无法执行
//
void *threadFounc(void *arg)//子线程
{
	int cnt = 5;
	while(cnt--){
		printf("sub thread %u!\n", pthread_self());
		sleep(1);
	}
	return NULL;
}
int main(void)
{
	printf(">> main thread start runing !\n");
	pthread_t pthid = 0;//开启一个子线程
	pthread_create(&pthid, NULL, threadFounc, NULL);//创建一个线程
	printf("main thread = %u,  sub thread id = %u\n", pthread_self(),pthid);
	int cnt = 5;
	while(cnt--){
		printf("main thread 1!\n");
		//sleep(1);
	}
	//sleep(3);//等待子线程执行结束
	pthread_join(pthid, NULL);//常用的等待子线程结束的方式，
							//使用pthread_join()函数相当于阻塞作用	
							//阻塞是线程挂起

	printf(">> main thread exit!\n");
	return 0;
}
