 ///
 /// @file    TestStack.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-12 18:26:33
 ///
#include "Stack.h" 
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	cout << "创建一个空栈"<< endl;
	Stack stack ;
	stack.push(10);
	stack.push(12);
	stack.push(14);
	while (!stack.empty())
	{
		cout<< "栈顶元素为:" << stack.top() <<endl;
		stack.pop();
	}
	stack.pop();
	while (!stack.empty())
	{
		cout<< "栈顶元素为:" << stack.top() <<endl;
		stack.pop();
	}

}
