 ///
 /// @file    String.h
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-12 15:51:37
 ///
#ifndef __String_H__ 
#define __String_H__
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
class String
{
	public:
	String();
	String(const char *pstr);
	String(const String & rhs);
	String & operator = (const String & rhs)
	{
		size_t len = strlen(_pstr);
		if(len>strlen(rhs._pstr))
		{
			strcpy(_pstr,rhs._pstr);
		}
		else
		{
			delete []_pstr;
			_pstr= new char[strlen(rhs._pstr)+1]();
			strcpy(_pstr,rhs._pstr);
		}
			return *this;
			cout<<"调用赋值运算符函数"<< endl;
	}
	~String()
	{
		delete  []_pstr;
		cout << "调用了析构函数"<< endl;
	}
	void print();
private:
	char * _pstr;

};

#endif

