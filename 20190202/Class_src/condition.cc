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
int gNumber = 10000;
pthread_mutex_t mutex1; //定义一个互斥锁
pthread_cond_t cond1;//定义一个条件变量
bool flag = true;
void *threadFounc1(void *arg)//子线程
{
	//线程1：当flag为true时，执行减一操作,同时把true设为false，通知线程2
	//		 当flag为false时，阻塞挂起，等待条件成立
	int cnt = 5;
	while(cnt--){
		pthread_mutex_lock(&mutex1);//使用条件变量前要进行加锁操作
		while(flag == false){
			pthread_cond_wait(&cond1, &mutex1);//利用互斥锁阻塞,且在阻塞的同时进行解锁，否则会出现死锁的情况
		}
		--gNumber;
		flag = false;
		pthread_cond_signal(&cond1);

		printf("sub thread %ld!, gNumber = %ld\n", (uint64_t)pthread_self(),(uint64_t)gNumber);
		pthread_mutex_unlock(&mutex1);//解锁操作
		sleep(1);
	}
	return NULL;
}

void *threadFounc2(void *arg)//子线程
{
	//线程2：当flag为false时，执行减一操作,同时把false设为true，通知线程1
	//		 当flag为ture时，阻塞挂起，等待条件成立
	int cnt = 5;
	while(cnt--){
		pthread_mutex_lock(&mutex1);//加锁操作
		while(flag == true){
			pthread_cond_wait(&cond1,&mutex1);		
			//其他线程发送signal之后，当前wait被激活，激活后首先进行加锁
		}
		--gNumber;
		printf("sub thread %ld!, gNumber = %ld\n", (uint64_t)pthread_self(),(uint64_t)gNumber);

		if(flag == false)
			flag = true;
		pthread_cond_signal(&cond1);		
		pthread_mutex_unlock(&mutex1);//加锁操作
		sleep(1);
	}
	return NULL;
}

void begin()
{
	pthread_mutex_init(&mutex1, NULL);//动态初始化互斥锁
	pthread_cond_init(&cond1, NULL);//动态初始化条件变量
	printf(">> main thread start runing !\n");
	pthread_t pthid1 = 0, pthid2 = 0;//初始化两个线程
	//开启两个子线程，会出现混乱的情况
	pthread_create(&pthid1, NULL, threadFounc1, NULL);//创建一个线程
	pthread_create(&pthid2, NULL, threadFounc2, NULL);
	printf("main thread ids：\n%ld \nsub thread ids: \n%ld   %ld\n"
	,(uint64_t)pthread_self()
	,(uint64_t)pthid1,(uint64_t)pthid2);
	pthread_join(pthid1, NULL);//常用的等待子线程结束的方式，(阻塞，线程挂起）
	pthread_join(pthid2, NULL);
	pthread_mutex_destroy(&mutex1);
	printf(">> main thread exit!\n");
}

int main(void)
{
	begin();
	return 0;
}
