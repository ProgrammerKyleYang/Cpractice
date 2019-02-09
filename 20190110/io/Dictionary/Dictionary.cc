 ///
 /// @file    Dictionary.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-17 10:27:35
 ///
#include "Dictionary.h"
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
using std::ofstream;
using std::vector;


void Dictionary::read(const string &filename)
{
	ifstream ifs(filename);
	if(!ifs){
		cout << ">> ifstream open" << filename << "error" << endl;
		return;
	}
	string line;

	while(getline(ifs,line)){
		istringstream iss(line);
		string word;
		while (iss >> word){
			string processedWord = perprocess(word);
			insert(processedWord);
		}
	}
	ifs.close();
//	std::sort(_dict.begin(), _dict.end());
}
void Dictionary::store(const string &filename)
{
	ofstream ofs(filename);
	if(!ofs){
		cout << "ofstream open "<< filename << " error" <<endl;
		return ;
	}
	for(size_t idx = 0; idx != _dict.size(); ++idx){
		ofs << _dict[idx]._word << " " << _dict[idx]._frequency << "\n";
	
	}
	ofs.clear();

}
void Dictionary::insert(const string &word)
{
	if (word == string()){
		return;
	}
	size_t idx;
	for(idx = 0; idx != _dict.size(); ++idx){
		if(_dict[idx]._word == word){
			++(_dict[idx]._frequency);
			break;
		}
	}
	if(idx == _dict.size()){//出现新的词
		_dict.push_back(Record(word,1));
	}

}

string Dictionary::perprocess(const string & word)	
{
	for(size_t idx = 0; idx != word.size(); ++idx){
		if(!isalpha(word[idx])){
			return string();
			}
		}
	return word;
}
