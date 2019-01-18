 ///
 /// @file    Queue.h
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-13 23:09:46
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Queue
{  
public:

	explicit
	Queue(int size = 10)
	: _size(size)
	, _front(0)
	, _rear(0)
	,_data(new int [_size]())
	{}
	~Queue();
	void push(int);
	void pop();
	int front()const;
	int back()const;
	bool isOrNotEmpty()const;
	bool isOrNotFull()const;
	int getRear()const;
    void diaplay();
private:
	int _size;
	int _front;
	int _rear;
	int *_data;

};
