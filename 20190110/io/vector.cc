 ///
 /// @file    vector.cc / @author    kyle(kyleyang58@gmail.com) / @date    2019-01-16 22:15:35
 ///
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
 

void printvectorCapacity(const  vector<int> & vec)
{

	cout << "vec's size = " << vec.size() << endl
		 << "vec's capacity = " << vec.capacity() <<endl;
}
//capacity() 动态扩容技术
int main(void)
{
	vector<int> numbers;//vector 可以按照2^n自动扩容
	printvectorCapacity(numbers);
	
	numbers.push_back(1);
	printvectorCapacity(numbers);
	numbers.push_back(2);
	printvectorCapacity(numbers);
	numbers.push_back(3);
	printvectorCapacity(numbers);
	numbers.push_back(4);
	printvectorCapacity(numbers);
	numbers.push_back(5);
	printvectorCapacity(numbers);

	return 0;

 
}
