 ///
 /// @file    Stack.h
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-12 18:20:14
 ///
#ifndef __STACK_H__
#define __STACK_H__
#include <iostream>
using std::cout;
using std::endl;

class Stack
{
public:
	Stack(int size = 10) 
	: _top(-1) 
	, _size(size)
	, _data(new int[_size]())
	{
	
	}
	~Stack();
	void push(int);
	void pop();
	bool empty();
	bool full();
	void print();
	int top() const;
private:
	int _top;
	int _size;
	int *_data;
};

#endif

