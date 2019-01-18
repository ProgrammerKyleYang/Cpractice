 ///
 /// @file    String.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-01-15 16:03:02
 ///
 
#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


class String
{
//在类内部实现的函数都是inline函数
public:
	String()
	: _pstr(new char[5]() + 4)
	{	
		cout << "String()" << endl;	
		initRefcount();
	}

	String(const char * pstr)
	: _pstr(new char[strlen(pstr) + 5]() + 4)
	{
		strcpy(_pstr, pstr);
		initRefcount();
		cout << "String(const char *)" << endl;
	}

	String(const String & rhs)
	: _pstr(rhs._pstr)
	{
		increaseRefcount();
		cout << "String(const String &)" << endl;
	}

	String & operator=(const String & rhs)
	{
		cout << "String & operator=(const String &)" << endl;
		if(this != &rhs) {// 自复制
			release(); //释放左操作数空间

			_pstr = rhs._pstr;// 进行浅拷贝
			increaseRefcount();
		}
		return *this;
	}

	void release()
	{
		decreaseRefcount();
		if(refcount() == 0) {
			delete [] (_pstr - 4);
			cout << ">> delete heap data!!!" << endl;
		}
	}
	

	~String()
	{
		release();
		cout << "~String()" << endl;
	}

	int refcount() const 
	{	return *(int*)(_pstr - 4);	}

	const char * c_str() const
	{	return _pstr;	}	

	size_t size() const
	{	return strlen(_pstr);}

private:
	class CharProxy
	{
	public:
		CharProxy(String & self, size_t idx)
		: _self(self)
		, _idx(idx)
		{}

		char &	operator=(const char & ch);
		friend std::ostream & operator<<(std::ostream & os, const CharProxy & rhs);
	
	private:
		String & _self;
		size_t _idx;
	};
	//设计模式之代理模式
public:
	CharProxy operator[](size_t idx)
	{
		return CharProxy(*this, idx);
	}
	//下标访问运算符无法区分接下来的操作是读操作还是写操作
	//char & operator[](size_t idx) 
//	CharProxy operator[](size_t idx) 
//	{
//	}

	//char & operator[](size_t idx) const;//const对象只能调用const成员函数
private:
	void initRefcount() //函数名能够表达语义
	{
		*(int *)(_pstr - 4) = 1;//对人不友好
	}

	void increaseRefcount()
	{
		++*(int *)(_pstr - 4);
	}

	void decreaseRefcount()
	{
		--*(int *)(_pstr - 4);
	}

	friend std::ostream & operator<<(std::ostream & os, const String & rhs);
	friend std::ostream & operator<<(std::ostream & os, const CharProxy & rhs); 
private:
	char * _pstr;//指向字符串内容本身
};

std::ostream & operator<<(std::ostream & os, const String & rhs)
{
	os << rhs._pstr;
	return os;
}

 
//写操作
char &	String::CharProxy::operator=(const char & ch)
{
	if(_idx < _self.size()) {
		//只考虑了写操作
		if(_self.refcount() > 1) {//共享字符串
			char * ptmp = new char[_self.size() + 5]() + 4;//进行深拷贝
			strcpy(ptmp, _self._pstr);

			_self.decreaseRefcount();
			_self._pstr = ptmp;
			_self.initRefcount();
		}	
		_self._pstr[_idx] = ch;//进行赋值操作
		return _self._pstr[_idx];
	} else {
		static char nullchar = '\0';
		return nullchar;
	} 
}
//读操作  并非成员函数
std::ostream & operator<<(std::ostream & os, const String::CharProxy & rhs)
{
	os << rhs._self._pstr[rhs._idx];
	return os;
}
int main(void)
{
 
	String s1("hello,world");
	String s2 = s1;//copy constructor
	//String s2(s1);
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s1' refcount = " << s1.refcount() << endl;
	cout << "s2' refcount = " << s2.refcount() << endl;
	printf("s1'address = %p\n", s1.c_str());
	printf("s2'address = %p\n", s2.c_str());

	String s3("hubei wuhan");
	cout << ">> 执行s3 = s1 之后: " << endl;
	s3 = s1;//调用operator=()
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s1' refcount = " << s1.refcount() << endl;
	cout << "s2' refcount = " << s2.refcount() << endl;
	cout << "s3' refcount = " << s3.refcount() << endl;
	printf("s1'address = %p\n", s1.c_str());
	printf("s2'address = %p\n", s2.c_str());
	printf("s3'address = %p\n", s3.c_str());
	
	cout << endl << "对s3[0]执行写操作:" << endl;
	s3[0] = 'H';//要去修改字符串内容，此时才去进行深拷贝
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s1' refcount = " << s1.refcount() << endl;
	cout << "s2' refcount = " << s2.refcount() << endl;
	cout << "s3' refcount = " << s3.refcount() << endl;
	printf("s1'address = %p\n", s1.c_str());
	printf("s2'address = %p\n", s2.c_str());
	printf("s3'address = %p\n", s3.c_str());

	cout << endl << "对s1[0]执行读操作" << endl;
	cout << "s1[0] = " << s1[0] << endl;//要去修改字符串内容，此时才去进行深拷贝
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s1' refcount = " << s1.refcount() << endl;
	cout << "s2' refcount = " << s2.refcount() << endl;
	cout << "s3' refcount = " << s3.refcount() << endl;
	printf("s1'address = %p\n", s1.c_str());
	printf("s2'address = %p\n", s2.c_str());
	printf("s3'address = %p\n", s3.c_str());


	return 0;
}
