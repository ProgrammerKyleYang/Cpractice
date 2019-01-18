 /// / @file    justStack.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-15 20:13:02
#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;
//只可以生成栈对象 
//意味着对象只能够放到栈上，不能放到堆上
//可以将operator new/delete 放到private区中
//
//只能生成堆对象
//意味着对象只能放在堆上，不能放在栈上
//因为系统要调用析构函数，所以把析构函数私有化就可以实现
//这样的功能，编译不能通过
class Student
{
	public:
		Student(int id, const char *name)
		:_id(id)
		,_name(new char[strlen(name)+1]())
		{
			cout << "Student(int , const chat*)"<< endl;
			strcpy(_name, name);
		}
		void print()const
		{
			cout << "id : "<< _id  << endl
				 << "name:"<< _name <<endl;
		}
		~Student()
		{
			delete [] _name;
			cout << ">> ~Student()" << endl;
		}
		void *operator new(size_t size)
		{
			void *pret = malloc(size);
			cout << "void *mallco(size_t)" << endl;
			return pret;
		
		}
		void operator delete (void *pret)
		{
			free(pret);
			cout << "void operator deleat (void *pret)"<<endl;
		}
	private:
		int _id;
		char *_name;
	//	void *operator new(size_t size)
	//	{
	//		void *pret = malloc(size);
	//		cout << "void *mallco(size_t)" << endl;
	//		return pret;
	//	
	//	}
	//	void operator delete (void *pret)
	//	{
	//		free(pret);
	//		cout << "void operator deleat (void *pret)"<<endl;
	//	}
	//	~Student()
	//	{
	//		delete [] _name;
	//		cout << ">> ~Student()" << endl;
	//	}
};

int main(void)
{
	Student s2(101,"xiaoyang");
	s2.print();
	Student * pstu = new Student(100,"xiaoming");
	pstu->print();
	delete pstu;//把析构函数私有化之后，类外不能使用delete，因为delete要调用析构函数
				//可以把调用delete操作放在类中，重写一个函数，就可以使用delete了
	return 0;

}
