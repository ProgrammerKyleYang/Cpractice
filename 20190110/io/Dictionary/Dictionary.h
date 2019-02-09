 ///
 /// @file    Dictionary.h
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-17 10:40:25
 ///
#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__
#include <vector>
//#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::istringstream;
  
struct Record
{
	Record(const string &word, size_t frequency)
	: _word(word)
	, _frequency(frequency)
	{}
	string _word;
	size_t _frequency;
};

//bool operator < (const Record &lhs, const Record &rhs)
//{
//	return lhs._frequency < rhs._frequency;
//}

class Dictionary
{
public:
	Dictionary(size_t capacity)
	{
		_dict.reserve(capacity);
	}
	void read(const string &filename);
	void store(const string &filename);
	
private:
	vector<Record> _dict;
	void insert(const string &word);
	string perprocess(const string &word);

};
#endif

