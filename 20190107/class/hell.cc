 ///
 /// @file    hell.cc
 /// @author  kyle(kyleyang58@gmail.com)
 /// @date    2019-01-07 22:14:29
 ///
 
#include <iostream>
using std::cout;
using std::endl;
int a ;//全局变量自动初始化。不设置自动为0
char *p1;
//static int c = 0;

int main(void)
{
	//int b= 2;
	int b;//未赋值的时候就是野指针，会指向一个随机的地址，所以使用指针时一定要赋值

	char s[]="123456";
	char * p2;
	char * p3 = "123546";
	static int c = 0;
	printf("&a= %p\n",&a);
	printf("&p1= %p\n",&p1);
	printf("&p1= %p\n",p1);
	printf("a= %d\n",a);
	
	cout<< endl;
	
	printf("&b= %p\n",&b);
	printf("&p2 %p\n",&p2);
	printf("&p2= %p\n",p2);
	printf("b= %d\n",b);
	printf("s= %d\n",s);
	cout<< endl;
	printf("&p3= %p\n",&p3);
	printf("p3= %p\n",p3);
	printf("c= %d\n",c);
	printf("&c= %p\n",&c);
	return 0;

}



