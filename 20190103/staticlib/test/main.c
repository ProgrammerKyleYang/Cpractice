#include "qs.h"
#include <iostream>
using std::cout;
	
int main(){
	int a[5] = [5,4,3,2,1];
	int low = 0;
	int high = 5;
	qs(a,low,high);
	for(int i=0; i<5; ++i)
		cout<< a[i]<<' ';
	return 0;
}
