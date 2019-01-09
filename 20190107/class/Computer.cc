 ///
 /// @file    Computer.cc
 /// @author  kyle(kyleyang58@gmail.com)
 /// @date    2019-01-08 19:21:04
 ///
#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;
class Computer
{//大括号里为类内部.在大括号里的函数都是Inline函数,想对于Demo中的函数来说，在类外部的函数不能用Inline函数
	//对于struct而言，内部元素默认访问权限是public
	//而class分为public，protect和private三种类型
	//在C++中这是class和struct的唯一区别
public://规范为顶格
	void setBrand(const char * brand)
	{
		strcpy(_brand,brand);//使用string对字符串进行复制

	}
	void setPrice(float price)
	{
		_price = price;//规范：在成员变量前面加上"_"，如_price
				                	//增加代码可读性
	}
	void print()
	{
		cout << "brand:" << _brand << endl
			 << "price:" << _price << endl;
	}

private://封装,在类之外不可以直接访问，内部可以访问.这里可以类比struct
	char _brand[20];
	float _price;
	
};
int main(void)
{
	Computer computer;
	computer.print();//还没有对下面两个成员进行初始化，所以打印出来会是乱码
	computer.setBrand("Lenovo");//初始化通过两个成员函数构成
	computer.setPrice(5555);
	computer.print();
	
//	computer._brand = "Thinkpad";//error！_brand是一个私有成员变量，不可以直接赋值
//	computer._price = 8888;
	

	return 0;
}
