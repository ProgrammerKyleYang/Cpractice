 ///
 /// @file    QueueTemplate.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-28 22:38:02
 ///
 
#include <iostream>
#include <string>
using std:: cout;
using std:: endl;
using std:: string;

template  <class T, size_t kSize = 10>
class Queue
{
public:
	Queue()
	: _rear(0)
	, _front(0)
	, _size(kSize)
	, _data(new T [kSize]())
	{}

	~Queue()
	{
		delete[] _data;
		cout << "~Queue()" << endl;
	}
	
	void push(const T &number);
	void pop();
	T front() const;
	T back() const;
	bool isEmpty()const;
	bool isFull() const; 
	int getRear()const;
	void display();

private:
	int _rear;
	int _front;
	int _size;
	T *_data;
};

template  <class T, size_t kSize>
void Queue<T, kSize>::push(const T &number) 
{
	if (!isFull()){
		_data[_rear++] = number;
		_rear %= _size;	
		cout<< "push ("
			<< number
			<< ") in Queue !"
			<< endl;
	}
	else{
		cout<< "Queue is full, can't push elements."<< endl;
	}
}

template  <class T, size_t kSize>
void Queue<T, kSize>:: pop()
{
	cout<< "pop an element ("
		<< _data[_front]
		<< ") "
		<< endl;
	if(!isEmpty()){
		++_front;
		_front %= _size;
	}
	else 
	cout<< "Can't pop! The queue is empty" << endl ;
}

template  <class T, size_t kSize>
T Queue<T, kSize>::front()const
{
	return _data[_front];
}

template  <class T, size_t kSize>
T Queue<T, kSize>::back()const
{
	return _data[(_rear - 1 + _size) % _size];
}

template  <class T, size_t kSize>
bool Queue<T, kSize>::isEmpty()const
{
	return _front == _rear;
}

template  <class T, size_t kSize>
bool Queue<T, kSize>::isFull()const
{
	return _front == (_rear + 1) % _size;
}

template  <class T, size_t kSize>
int Queue<T, kSize>::getRear()const
{
	return _rear;
}

template  <class T, size_t kSize>
void Queue<T, kSize>::display()
{
	if(isEmpty()==1)
		cout<< "Queue is empty." << endl;
	if(isFull()==1)
		cout << "Queue is full."<< endl;
	else 
		cout << "Queue is not full" << endl;
}

void test0(void)
{
	Queue<string, 10> queue;
	cout<< "Build a Queue" << endl;
	queue.display();
	string alph = "hello world!";
	queue.push(alph);
	queue.display();
	for(int number = 1; number != 11; ++number){
		queue.push(string(3, 'a' + number));
	}
	queue.display();
	while(!queue.isEmpty()){
		cout<< "the front element is ("
			<< queue.front()
			<< "), "
			<< "the rear element is ("
			<< queue.back()
			<< ")"<< endl;
		queue.pop();
	}
	queue.display();
}
void test1(void)
{
	Queue <int, 10> queue;
	queue.display();
	queue.push(1);
	queue.display();
	for(int number = 2; number != 11; ++number){
		queue.push(number);
	}
	queue.display();
	while(!queue.isEmpty()){
		cout<< "the front element is ("
			<< queue.front()
			<< "), "
			<< "the rear element is ("
			<< queue.back()
			<< ")"<< endl;
		queue.pop();
	}
	queue.display();
}

int main(void)
{
	cout<< "******************************test0***************************"<< endl;
	test0();
	cout<< "******************************test1***************************"<< endl;
	test1();
	return 0;
}






