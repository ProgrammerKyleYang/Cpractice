 ///
 /// @file    String.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-17 22:22:02
 ///
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
class String {
public:
	String():_pstr(nullptr)
	{}
	String(const char * pstr):_pstr(new char[strlen(pstr)+1]())
    {       
        cout<<"String (const char *)"<<endl;
        strcpy(_pstr,pstr);
	}

	String(const String & rhs):_pstr(new char[strlen(rhs._pstr)+1]())
	{
		cout<<"String(const String & )"<<endl;
		strcpy(_pstr,rhs._pstr);
	}

	~String()
	{
		if(_pstr){
		delete [] _pstr;
	}
		cout<<"~String()"<<endl;
		_pstr=NULL;
	}

	String &operator=(const String & rhs)
	{
		if(this!=&rhs){
			delete [] _pstr;
		_pstr = new char [strlen(rhs._pstr)+1]();
		strcpy(_pstr,rhs._pstr);
		}
		return *this;
	}

	String &operator=(const char * pstr)
	{
		String tmp(pstr);//复制构造函数
		*this = tmp;
		return *this;
	}

	String &operator+=(const String &rhs)//复合赋值运算符
	{
		String tmp;
		tmp._pstr = new char[strlen(this->_pstr)+1]();
		strcpy(tmp._pstr,this->_pstr);
		delete  [] this->_pstr;//记得回收
		this->_pstr = new char[strlen(this->_pstr)+strlen(rhs._pstr)+1]();
		sprintf(this->_pstr,"%s%s",tmp._pstr,rhs._pstr);//利用一个缓冲区
		return *this;
	}
	String &operator+=(const char * pstr)
	{	
		String tmp;
		*this += tmp;//利用复制运算
		return *this;
	}

	char &operator[](std::size_t index)
	{
		if(index<size()){
			return _pstr[index];
		}
		else {
			static char nullchar = '\0';
			return nullchar;
		}
	}

	const char &operator[](std::size_t index) const
	{
		if(index<size()){
			return _pstr[index];
		}
		else {
			static char nullchar = '\0';
			return nullchar;
		}	
	}

	std::size_t size() const
	{
		size_t len = strlen(_pstr)+1;
		return len;
	}

	const char* c_str() const
	{
		return this->_pstr;
	}
/*                                  声明                                */
	friend bool operator==(const String & lhs, const String & rhs);
	friend bool operator!=(const String & lhs, const String & rhs);
	friend bool operator<(const String & lhs, const String & rhs);
	friend bool operator>(const String & lhs, const String & rhs);
	friend bool operator<=(const String & lhs, const String & rhs);
	friend bool operator>=(const String & lhs,const String & rhs);
	friend std::ostream &operator<<(std::ostream &os, const String &s);
	friend std::istream &operator>>(std::istream &is, String &s); 
	
	friend String operator+(const String & lhs, const String & rhs);
	
	friend String operator+(const String &lhs, const char * pstr);
	
	friend String operator+(const char * pstr, const String &rhs);

private:
	char * _pstr;
};
bool operator==(const String & lhs, const String & rhs)
	{
		if(strcmp(lhs._pstr,rhs._pstr)==0){
			return true;
		}
		else
			return false;
	}

bool operator!=(const String & lhs, const String & rhs)
	{
		if(strcmp(lhs._pstr,rhs._pstr)!=0){
			return true;
		}
		else
			return false;
	}
bool operator<(const String & lhs, const String & rhs)
	{
		if(strcmp(lhs._pstr,rhs._pstr)<0){
			return true;
		}
		else return false;
	}
bool operator>(const String & lhs, const String & rhs)
	{
		if(strcmp(lhs._pstr,rhs._pstr)>0){
			return true;
		}
		else
			return false;
	}
bool operator<=(const String & lhs, const String & rhs)
	{
		if(strcmp(lhs._pstr,rhs._pstr)<=0){
			return true;
		}
		else 
			return false;
	}
bool operator>=(const String & lhs,const String & rhs)
	{
		if(strcmp(lhs._pstr,rhs._pstr)>=0){
			return true;
		}
		else
			return false;
	}
std::ostream &operator<<(std::ostream &os, const String &s)
	{
		os<<s._pstr;
		return os;
	}
std::istream &operator>>(std::istream &is, String &s)
	{
		if (s._pstr){
			delete  [] s._pstr;
		}
		//char buff[65536] = {0}//空间开在栈上的话效率更高
		//或者使用容器vector和get方法来动态开辟空间
		//get每次获取一个字符
		vector<char> buffer;
		char ch;
		while ((ch = is.get())!= '\n'){
			buffer.push_back(ch);	
		}
		s._pstr = new char[buffer.size() + 1];
		strncpy(s._pstr,&buffer[0],buffer.size());
		return is;
	}
String operator+(const String & lhs, const String & rhs)
{
	String tmp(lhs);
	tmp += rhs;
	return tmp;

}

String operator+(const String &lhs, const char * pstr)
{	
	String tmp(pstr);
	tmp += (lhs);
	return tmp;	
}

String operator+(const char * pstr, const String &rhs)
{	
	String tmp(pstr);
	tmp += rhs;
	return tmp;	
}

int main()
{
	String s1("ykx");
	cout<<"s1 is : "<<s1<<endl;
	String s2;
	s2 = s1;
	cout<<"s2 is : "<<s2<<endl;
	String s3;
	s3 = s1 + s2;
	cout<<"s3=s1+s2 : "<<s3<<endl;
	cout<<"input s4 : "<<endl;
	String s4;
	cin>>s4;
	cout<<"s4 is : "<<s4<<endl;
	if(s3!=s4){
		cout<<"s3 is not equal s4"<<endl;
	} 
	if(s3 > s4){
		cout<<"s3 is higher than s4"<<endl;
	} 
	if(s3 < s4){
		cout<<"s3 is lower than s4"<<endl;
	}
	return 0;
}
