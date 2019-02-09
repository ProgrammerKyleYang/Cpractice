 ///
 /// @file    ClassTemplate.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-27 21:35:53
 ///
 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

template <class T, size_t kSize = 6>
class Stack
{
public:
	Stack()
	: _top(-1)
	, _data(new T[kSize]())
	{}

	~Stack();

	bool StackIsFull() const;
	bool StackIsEmpty() const;
	void push(const T &t);
	void pop();
	T top();

private:
	int _top;
	T *_data;
};

template < class T, size_t kSize>
Stack<T, kSize>::~Stack()
{
	cout << "~Stack() "<< endl;
}

template <class T, size_t kSize >
bool Stack<T, kSize>::StackIsFull() const
{
	return _top == (kSize -1);
}

template <class T, size_t kSize >
bool Stack<T, kSize>::StackIsEmpty() const
{
	return _top == -1;
}
template < class T, size_t kSize >

void Stack<T, kSize>::push(const T &t)
{
	if(!StackIsFull())
	{
		cout <<"Push ("<< t << ") in stack"<<endl;
		_data[++_top] = t;
		cout<<"("<< t <<") has pushed in the stack"<<endl;
	}
	else
		cout << "Stack is full"<< endl;
}

template < class T, size_t kSize >
void Stack<T, kSize>::pop()
{
	if(!StackIsEmpty())
	{
		--_top;
		cout << "Pop an element" <<endl;
	}
	else
		cout << "Stack is empty"<< endl;
}
template < class T, size_t kSize >
T Stack<T, kSize>::top()
{
	return _data[_top];
}
	
void test0(void)
{
	cout << "Build a new stack" << endl;
	Stack<string, 6> stack;
	string st = "hello worlad!";
	stack.push(st);
	for(int ix = 1; ix != 6; ++ix)	
	{
		stack.push(string(3,'a' + ix));
	}
	for(int iy = 1; iy != 3; ++iy)	
		stack.pop();
	cout<< "Pop remaining elements"<<endl;
	while (!stack.StackIsEmpty())
	{
		cout<< "The top element is ： "
			<< stack.top()
			<< endl;
		stack.pop();
	}
}
void test1(void)
{
	cout << "创建一个空栈"<< endl;
	Stack <int, 10> stack;
	stack.push(10);
	stack.push(12);
	stack.push(14);
	while (!stack.StackIsEmpty())
	{
		cout<< "栈顶元素为:" << stack.top() <<endl;
		stack.pop();
	}
	stack.pop();
	while (!stack.StackIsEmpty())
	{
		cout<< "栈顶元素为:" << stack.top() <<endl;
		stack.pop();
	}

}
int main(void)
{
	cout << "*********************test0*********************"<<endl;
	test0(); 
	cout << "*********************test1*********************"<<endl;
	test1(); 
	return 0;
}
