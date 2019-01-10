 ///
 /// @file    struct.cc
 /// @author  kyle(kyleyang58@gmail.com)
 /// @date    2019-01-08 20:15:05
 ///
#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;
 
struct Computer
{//大括号里为结构体
//public:
	void setBrand(const char * brand)//
	{
		strcpy(_brand,brand);//使用string对字符串进行复制

	}
	void setPrice(float price)
	{
		_price = price;
	}
	void print()
	{
		cout << "brand:" << _brand << endl
			 << "price:" << _price << endl;
	}

//private://封装,在类之外不可以直接访问，内部可以访问.这里可以类比struct
	char _brand[20];
	float _price;
};
int main(void)
{
 	
	Computer computer;
	computer.setBrand("Lenovo");
	computer.setPrice(5555);
	computer.print();
	
	//char brand[] = "Thinkpad";//不可以直接改数组值
	
	//computer._brand = brand;//这里和class下语句做对不，class下_brand是一个私有成员变量，不可以直接赋值
	computer._price = 8888;//class下为error
	computer.print();//运行ok,发现可以改值，体现出了struct和class的区别,struct在内部默认元素为public的
	return 0;
}		
 		
 		
 		

 		
 		
