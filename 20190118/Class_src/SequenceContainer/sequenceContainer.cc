 /// @file    sequenceContainer.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-28 13:49:00
 ///
#include <vector>
#include <deque>
#include <list>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::list;

void test0()
{//vector的构造方法
//	vector<int> numbers(10,1);//把1传入容器
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> numbers(array, array + 10);
	cout<< "number's size = "<< numbers.size()<< endl
		<< "number's capacity = "<< numbers.capacity()<<endl;
	vector<int>::const_iterator cit;//使用迭代器遍历元素
	for(cit = numbers.begin(); cit!= numbers.end(); ++ cit)
	{
		cout << *cit << " "	;
	}
	cout << "sizeof (vector<int>) = "<< sizeof (vector<int>) << endl;
	//迭代器构造方法
}

void test1()
{
	list<int> numbers(10,1);
	cout<< "number's size = "<< numbers.size()<< endl;
	list<int>::const_iterator cit;//使用迭代器遍历元素
	for(cit = numbers.begin(); cit!= numbers.end(); ++ cit)
	{
		cout << *cit << " "	;
	}
	cout << "sizeof (vector<int>) = "<< sizeof (vector<int>) << endl;
}

void test2()
{
	deque<int> numbers(10,1);//把1传入容器
	cout<< "number's size = "<< numbers.size()<< endl;
	deque<int>::const_iterator cit;//使用迭代器遍历元素
	for(cit = numbers.begin(); cit!= numbers.end(); ++ cit)
	{
		cout << *cit << " "	;
	}
	cout << "sizeof (vector<int>) = "<< sizeof (vector<int>) << endl;
}

int main(void)
{
	cout << ">>> vector: "<<endl;
	test0();
	cout << ">>> list: "<<endl;
	test1();
	cout << ">>> deque: "<<endl;
	test2();
	return 0;
}
