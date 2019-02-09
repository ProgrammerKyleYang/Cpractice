 ///
 /// @file    Doublink_list.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-15 21:28:32
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
class Node
{
	public:
		int _data;
		Node *_pre;
		Node *_next;
		Node(int data =0,Node *pre =nullptr,Node *next =nullptr)
		:_data(data)
		,_pre(pre)
		,_next(next)
		{}
		~Node()
		{}
};


class Linklist
{
	public:
		Linklist()
		:_head(new Node())//初始化
		,_size(0)
		{
			_tail=_head;
		}
		void push_back(int data)//尾插
		{
			Node *newNode=new Node(data);
			(*newNode)._pre=_tail;//插入的新结点前置指针指向当前的尾结点
			(*_tail)._next=newNode;//连接插入的结点
			_tail=(*_tail)._next;//修改新插入的结点为尾结点
			++_size;
		}
		void push_front(int data)//头插一个结点
		{
			Node *newNode=new Node(data);
			newNode->_next=_head->_next;
			newNode->_pre=_head;
			_head->_next->_pre=newNode;
			_head->_next=newNode;
			++_size;
		}
		void delete_back()//在尾部删除一个数据
		{
			Node *deleteNode=_tail;
			_tail=_tail->_pre;
			delete deleteNode;
			_tail->_next=nullptr;
			--_size;
		}
		void delete_front()//在头部删除一个数据
		{
			Node *deleteNode=_head->_next;
			_head->_next=deleteNode->_next;
			deleteNode->_next->_pre=_head;
			delete deleteNode;
			--_size;
		}
		Node * find(int value)
		{
			Node *findNode=_head->_next;
			if(findNode->_data==value)
				return findNode;
			else 
				cout<<"找不到此结点";
		}		
		void add(int data,int value)//在某结点前添加数据
		{
			Node *addNode=new Node(value);
			Node *findone=_head->_next;
			while(findone&&findone->_data!=data)
			{
				findone=findone->_next;
			}
			addNode->_next=findone;
			addNode->_pre=findone->_pre;
			findone->_pre->_next=addNode;
			findone->_pre=addNode;
			++_size;
		}
		void deleteone(int value)//删除一个指定的结点
		{
			Node *deleteone=_head->_next;
			while((deleteone->_data)!=value)
			{	
				deleteone=deleteone->_next;
			}
			deleteone->_pre->_next=deleteone->_next;
			deleteone->_next->_pre=deleteone->_pre;
			delete deleteone;
			--_size;
		}
		void print()
		{
			cout<<"此时链表为：";
			Node * p=_head;//通过指针接操作_head
			while((p->_next)!=nullptr)
			{
				cout<<(*(p->_next))._data<<" ";
				p=p->_next;
			}
			cout<<endl;
		}
		~Linklist()
		{
			while(_tail!=_head)//初始头尾相等
			{
				Node *deleteNode=_tail;
				_tail=_tail->_pre;
				delete deleteNode;
				deleteNode == nullptr;
			}
			delete _head;
		}
	private:
		Node *_head;
		Node *_tail;
		size_t _size;
};


	
int main(void)
{
	Linklist dl; 
	cout << "连续插入6个数字: "<< endl;
	int _ix;
	for (_ix=0; _ix<6; ++_ix)
		dl.push_back(_ix);
	dl.print();
	cout << "删除头元素: "<< endl;
	dl.delete_front();
	dl.print();
	cout << "删除尾元素: "<< endl;
	dl.delete_back();
	dl.print();
	cout << "删除3 "<< endl;
	dl.deleteone(3);
	dl.print();
	return 0;
}
