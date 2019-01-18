 ///
 /// @file    io3.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-17 16:30:10
 ///
#include <sstream>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::istringstream;
using std::ostringstream;
using std::stringstream;
using std::string;

void test0()
{
	int number1 = 10;
	int number2 = 20;
	stringstream ss;//可以看为一个缓冲区
	ss << "number1" << number1 << ",number2" << number2 <<endl;
	string line = ss.str();
	cout << line;

	string key;
	int value;
	 
	while(ss >> key >> value, !ss.eof()){
		cout << key << "-->" << value << endl;
	}

}
 
int main(void)
{
	test0();
	return 0;

}
