//预处理不能少
#ifndef __COMPUTER_H__
#define __COMPUTER_H__
class Computer
{
public://规范为顶格
	void setBrand(const char * brand);//声明
	void setPrice(float price);
	void print();
private://封装,在类之外不可以直接访问，内部可以访问.这里可以类比struct
	char _brand[20];
	float _price;

};

#endif
