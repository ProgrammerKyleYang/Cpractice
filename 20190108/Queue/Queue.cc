 // @file    Queue.cc	//
 // @author  kyle(kyleyang58@gmail.com) //
 // @date    2019-01-13 23:09:51 //
#include "Queue.h"
#include <iostream>
using std::cout;
using std::endl; 
Queue::~Queue()
{
	cout << ">> ~Queue()" << endl;
	delete  [] _data;
}
void Queue::push(int number)
{
	if(!isOrNotFull())
	{
		_data[_rear++] = number;
		_rear %= _size;
		cout << "push  " << number << "  in Queue" << endl;
	}
	else
		cout << "Queue is full, can not push anymore."<< endl;
}
void Queue::pop()
{
	if(!isOrNotEmpty())
	{
		++_front;
		_front %= _size;
		//cout << "pop Queue" << endl;
	}
	else 
		cout << "Can't pop! The queue is empty" << endl ;
}
int Queue::front()const
{
	return _data[_front];
}
int Queue::back()const
{
	return _data[(_rear - 1 + _size) % _size];
}
int Queue::getRear()const
{
	return _rear;
}
bool Queue::isOrNotEmpty()const 
{
	return _front == _rear;
}
bool Queue::isOrNotFull()const
{
	return _front == (_rear + 1)%_size;
}
void Queue::diaplay()
{
	
	if(isOrNotEmpty()==1)
		cout<< "Queue is empty." << endl;
	if( isOrNotFull()==1)
		cout << "Queue is full."<< endl;
	else 
		cout << "Queue is not full" << endl;
}
