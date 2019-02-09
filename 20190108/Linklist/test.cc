///
/// @file    test.cc
/// @author    kyle(kyleyang58@gmail.com)
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


class String
{
	public:
		String()
			: _pstr(nullptr)
		{
			cout << "String()" << endl;
		}

		String(const char * pstr)
			: _pstr(new char[strlen(pstr) + 1]())
		{
			strcpy(_pstr, pstr);
			cout << "String(const char *)" << endl;
		}

		String(const String & rhs)
			: _pstr(new char[strlen(rhs._pstr) + 1]())
		{
			cout << "String(const String&)" << endl;
			strcpy(_pstr, rhs._pstr);
		}

		String & operator=(const String & rhs)
		{
			cout << "String& operator=(const String&)" << endl;
			if(this != &rhs) {
				delete [] _pstr;

				_pstr = new char[strlen(rhs._pstr) + 1]();
				strcpy(_pstr, rhs._pstr);
			}
			return *this;
		}

		void print() const
		{
			if(_pstr)// cout对于char*的空指针，运行的时候会直接崩溃
				cout << _pstr << endl;
		}

		~String()
		{
			cout << "~String()" << endl;
			delete [] _pstr;
		}


	private:
		char * _pstr;
};

int main(void)
{
	String s1;
	s1.print();

	String s2("hello,world");
	s2.print();

	String s3(s2);
	s3.print();

	String s4("hubei wuhan");
	s3 = s4;
	s3.print();
	return 0;
}
/// @date    2019-01-14 22:53:43
///
