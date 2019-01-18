 ///
 /// @file    Stack.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-12 18:26:27
 ///
#include "Stack.h" 
#include <iostream>
using std::cout;
using std::endl;

Stack::~Stack()
{
	if(_data)
		delete  [] _data ;
	cout << "调用了析构函数" << endl;

}
void Stack::push(int value)
{
	if(!full())
	{	
		cout << "把" << value  << "入栈" << endl;
		_data[++_top]=value;
		cout << value << "已入栈" << endl;
	}	
	else
		cout << "栈已满" << endl;
}

void Stack::pop()
{	
	if(!empty())
	{
		--_top;
		cout << "出栈一次" << endl;
	
	}
}
bool Stack:: empty()
{
	return _top == -1;
}
bool Stack:: full()
{
	return _top == (_size - 1);
}
void Stack:: print()
{


}
int Stack::top() const
{
	return _data[_top];
}
