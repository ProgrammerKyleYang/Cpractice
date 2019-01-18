 ///
 /// @file    MainDictionary.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-17 10:40:34
 ///

#include "Dictionary.h"
#include <time.h>
//#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ostream;
using std::vector;


int main(void)
{	
	Dictionary dictionay(13000);
	time_t beg = ::time(NULL);
	dictionay.read("The_Holy_Bible.txt");
	time_t end = ::time(NULL);
	cout << "using "<< (end-beg) << " s"<<endl;
	dictionay.store("The_Holy_Bible.bat");
	return 0;
}

