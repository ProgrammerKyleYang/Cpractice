 ///
 /// @file    Computer.cc
 /// @author  kyle(kyleyang58@gmail.com)
 /// @date    2019-01-08 19:21:04
 ///
#include <stdio.h>
#include "Computer.h"//导入自定义头文件
#include <string.h> 
#include <iostream>
using std::cout;	
using std::endl;
			
//Computer::Computer(const char *brand, float price)//const chat *为c风格的代码
//: _brand(new char[sizeof(brand) + 1]())//初始化  数组加上小括号之后有清零的效果
//, _price(price)
//{
//    // _brand = new char[sizeof(brand) + 1]()//与上面13行是一个意思，写法的问题
//	//cout <<  "sizeof(brand) = " << sizeof(brand) << endl;
//	strcpy(_brand, brand);//复制操作
//	cout << "Computer(const chat *,float)" << endl;
//}
//把方法放到类外进行定义，使用::定义域作用符
void Computer:: setBrand(const char * brand)//成员函数的第二种实现方式，在类外部定义
{
	size_t len = strlen(_brand);
	if(len > strlen(brand))
		strcpy(_brand,brand);
	else{
		delete [] _brand;
		_brand = new char[strlen(brand)+1]();
		strcpy(_brand,brand);
	
	}
}
void  Computer:: setPrice(float price)//只要加上了作用域都，那么都可以访问
{
	_price = price;//
			                	//增加代码可读性
}
void Computer:: print()
{
	printf("brand: %p\n", _brand);
	cout << "brand:" << _brand << endl
		 << "price:" << _price << endl;
}

