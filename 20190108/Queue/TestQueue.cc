///
/// @file    TestQueue.cc
/// @author    kyle(kyleyang58@gmail.com)
/// @date    2019-01-13 23:09:57
///
#include "Queue.h"
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	Queue queue;
	cout<< "Build a Queue" << endl;
	//queue.isOrNotEmpty();
	queue.diaplay();
	queue.push(1);
	//queue.isOrNotEmpty();
	queue.diaplay();
	for(int idx = 2; idx != 12 ;++idx)
		queue.push(idx);	
	cout << "_rear : " << queue.getRear() << endl;
	cout << "rear element is:" << queue.back() << endl;
	cout << "front element is:" << queue.front() << endl;
	cout << "rear element is:" << queue.back() << endl;
	queue.pop();
	queue.push(10);
	cout << "_rear : " << queue.getRear() << endl;
	cout << "rear element is:" << queue.back() << endl;
	cout << "pop Queue" <<endl;
	while(!queue.isOrNotEmpty())
	{
			cout << queue.front() << " ";
			queue.pop();
	}
	cout <<endl;
	
	queue.diaplay();

}
