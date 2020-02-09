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
int gNumber = 10000;
pthread_mutex_t mutex1; //定义一个互斥锁
void *threadFounc1(void *arg)//子线程
{
	int cnt = 100;
	while(cnt--){
		pthread_mutex_lock(&mutex1);//加锁操作
		--gNumber;
		printf("sub thread %ld!, gNumber = %ld\n", (uint64_t)pthread_self(),(uint64_t)gNumber);
		pthread_mutex_unlock(&mutex1);//解锁操作
		sleep(1);
	}
	return NULL;
}

void *threadFounc2(void *arg)//子线程
{
	int cnt = 100;
	while(cnt--){
		pthread_mutex_lock(&mutex1);//加锁操作
		--gNumber;
		printf("sub thread %ld!, gNumber = %ld\n", (uint64_t)pthread_self(),(uint64_t)gNumber);
		pthread_mutex_unlock(&mutex1);//加锁操作
		sleep(1);
	}
	return NULL;
}

void begin()
{
	pthread_mutex_init(&mutex1, NULL);//动态初始化互斥锁
	printf(">> main thread start runing !\n");
	pthread_t pthid1 = 0, pthid2 = 0;//开启两个子线程，会出现混乱的情况
	pthread_t pthid3 = 0, pthid4 = 0;
	pthread_create(&pthid1, NULL, threadFounc1, NULL);//创建一个线程
	pthread_create(&pthid2, NULL, threadFounc1, NULL);
	pthread_create(&pthid3, NULL, threadFounc2, NULL);
	pthread_create(&pthid4, NULL, threadFounc2, NULL);
	//printf("main thread = %u, sub thread id = %u, %u\n", pthread_self(),pthid1, pthid2);
	printf("main thread：%ld \nsub thread ids: \n%ld   %ld \n%ld   %ld\n"
	,(uint64_t)pthread_self()
	, (uint64_t)pthid1, (uint64_t)pthid2
	, (uint64_t)pthid3, (uint64_t)pthid4);
	pthread_join(pthid1, NULL);//常用的等待子线程结束的方式，(阻塞，线程挂起）
	pthread_join(pthid2, NULL);
	pthread_join(pthid3, NULL);
	pthread_join(pthid4, NULL);
	pthread_mutex_destroy(&mutex1);
	printf(">> main thread exit!\n");
}

int main(void)
{
	begin();
	return 0;
}
