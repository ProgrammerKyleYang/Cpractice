 ///
 /// @file    static.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-20 15:05:45
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int test()//C中的强制转换方法
{
	int number1 = 10;
	double number2 = 17.17;
	cout << "now , the number1 is : " << number1 << endl;
	cout << "now , the number2 is : " << number2 << endl;
	number1 = (int) number2;//强制转换方式1
//	number1 = int(number2);//强制转换方式2
	cout << "after, the number1 is : " << number1 << endl;
	return 0;
}
void test1()//C中的强制转换方法
{
	int number3 = 17 ;
	double number4 = 17.31;
	cout << "now , the number3 is : " << number3 << endl;
	cout << "now , the number4 is : " << number4 << endl;
	number3 = static_cast<int>(number4);
	cout << "after, the number3 is : " << number3 << endl;

	int * pInt = static_cast<int *>(malloc (sizeof(int)));//对指针做转换
	*pInt = 10;
	cout << "pInt = " << *pInt << endl ;
	free(pInt);
}
//const_pointer_cast

int main(void)
{
	test();
	test1();
	return 0;
}
