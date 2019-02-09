 ///
 /// @file    io2.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-17 14:38:46
 ///
#include <fstream>
#include <string>
#include <iostream>
#include <ostream>
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::fstream;


void test1()
{
	ifstream ifs("io.cc");
	if(!ifs){
		cout << "ifstream open file error!" << endl;
		return;
	}
	string file("test3.txt");//没有文件创建文件，有文件则把新内容写入
	ofstream ofs(file);
	if(!ofs){
		cout << "ofstream file error!" << endl;
		ifs.close();
	}
	string line;
	while(getline(ifs,line)){
		ofs << line << '\n'; 
	}
		ofs.close();//使用后都要记得关闭
}
void test2()
{
	string file("test2.txt");
	fstream fs(file);
	if(!fs){
		cout << "fstream open file" << file << "error!" << endl;
		return ;
	}
	int number = 0;
	for (size_t idx = 0; idx != 10; ++idx){
		std::cin >> number;
		fs << number << " " ;//文件输入流功能
	}
	cout << "文件已写入"<< endl;
		size_t pos = fs.tellg();
		cout << "pos = " << pos << endl;
	//fs.seekg(0)://绝对路径
	fs.seekg(0,std::ios::beg);//偏移到相对位置
	for (size_t idx = 0; idx != 10; ++idx){
		fs >> number ;
		cout << number << " ";//文件输出流功能
	}
	cout << endl ;
	fs.close();
}
	
int main(void)
{
	test2();
	return 0;
}
