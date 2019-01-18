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
	String & operator = (const String & rhs);//系统提供的合成的赋值运算符函数
	~String();
	void print();
private:
	char * _pstr;

};
class Empty//空类的大小为一个字节空间，原因是为了区分出对象的不同
{
//	public:
//		Empty(int ix = 0, int iy = 0)//引用成员的初始化只能放在初始化表达式中
//		: _ix(ix)
//		, _iy(iy)
//		, _ref(_ix)
//		{
//		
//		cout<<"初始化可以放在括号之外"<<endl;
//		
//		}
};

#endif

