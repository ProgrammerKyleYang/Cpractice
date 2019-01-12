 ///
 /// @file    String.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-12 14:41:38
 ///
#include "String.h"
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

String::String()
{
		cout<<"调用了无参函数"<<endl;
		_pstr=new char[20];
		strcpy(_pstr,"wucanhanshu");
}
String::String(const char *pstr)
{
	_pstr = (new char[sizeof(pstr)+1]());
	strcpy(_pstr,pstr);
	cout<<"调用了带参数构造函数"<<endl;
}
String::String(const String &rhs)
{
	_pstr = new char[strlen(rhs._pstr)+1]();
	cout << "调用复制构造函数" << endl;
	strcpy(_pstr,rhs._pstr);
}

void String::print()
{
	cout<<"result: "<< _pstr <<endl;

}

