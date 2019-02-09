 ///
 /// @file    String.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-12 14:41:38
 ///
#include "String.h"
#include <string.h>
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

String::String()
{
		cout<<"调用了无参函数"<<endl; _pstr=new char[20]; strcpy(_pstr,"wucanhanshu");
}
String::String(const char *pstr)
{
	_pstr = (new char[sizeof(pstr)+1]());
	strcpy(_pstr,pstr);
	cout<<"调用了带参数构造函数"<<endl;
}
String::String(const String &rhs)//复制构造函数
:_pstr( new char[strlen(rhs._pstr)+1]())//开辟空间初始化
{
    //_pstr=( new char[strlen(rhs._pstr)+1]()//开辟空间初始化的第二种写法
	cout << "调用复制构造函数" << endl;

	strcpy(_pstr,rhs._pstr);
}
String &String::operator=(const String &rhs)//赋值运算符函数与复制构造函数有很大区别
											//注意赋值运算符函数的三部曲
											//清理空间、新建空间、再赋值
{
	size_t len = strlen(_pstr);//获取字符串长度
	if(len>strlen(rhs._pstr))
	{
		strcpy(_pstr,rhs._pstr);//把rhs._pstr的值复制到当前函数
	}
	else// if(this != &rhs)
	{
		delete [] _pstr;//释放左操作数指针的堆空间,进行深拷贝
					//this指针代表左操作数 赋值运算符有两个操作数，左边为左操作数，右边为右操作数 rhs为右操作数 this->_pstr= new char[strlen(rhs._pstr)+1](); strcpy(_pstr,rhs._pstr);
		_pstr = new char[strlen(_pstr)+1]();
		strcpy(_pstr,rhs._pstr);//把rhs._pstr的值复制到当前函数
		
	}
		return *this;
		cout<<"调用赋值运算符函数"<< endl;
}
String ::~String()
{
	delete [] _pstr;
	cout << "调用了析构函数" << endl;

}
void String::print()
{
	printf("所在内存地址为：%p\n",_pstr);
	cout<<"result: "<< _pstr <<endl;

}

