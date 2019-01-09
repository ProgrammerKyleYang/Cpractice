#include <iostream>
//using namespace std;
#define max 100
using std::cout;
using std::cin;
using std::endl;
void inPut(int a[], int n);
void quickSort(int a[], int low, int high);
void outPut(int a[], int n);

int main() {
	int n; int a[max];
	cout << "輸入待排序數字個數：" <<endl;//cout表示一个对象 << 表示输出流运算符
	cin >> n;//cin 表示的也是对象>> 表示输出流运算符
	cout <<endl << "輸入待排序數組：" <<endl;
	inPut(a, n);
	quickSort(a, 0, n - 1);
	cout << "排序后为：" <<endl;
	outPut(a, n);
	cout<<""<<endl;
	return 0;
	system("pause");
}

void quickSort(int a[], int low, int high) {
	int i = low;  int j = high;
	int temp, l;
	temp = a[low];
	if (low<high) {
		while (i<j) {
			while (i<j && a[j] >= temp) --j;
			l = a[j]; a[j] = a[i]; a[i] = l;
			while (i<j && a[i] <= temp) ++i;
			l = a[i]; a[i] = a[j]; a[j] = l;
		}
		a[i] = temp;
		quickSort(a, low, i - 1);
		quickSort(a, i + 1, high);
	}
}

void inPut(int a[], int n) {
	for (int i = 0; i<n; ++i) cin >> a[i];
}
void outPut(int a[], int n) {
	for (int j = 0; j<n; ++j) cout << a[j] << ' ';
}

//int main() {
//	int n; int a[max];
//	std::cout << "輸入待排序數字個數：" << std::endl;//cout表示一个对象 << 表示输出流运算符
//	std::cin >> n;//cin 表示的也是对象>> 表示输出流运算符
//	std::cout << std::endl << "輸入待排序數組：" << std::endl;
//	inPut(a, n);
//	quickSort(a, 0, n - 1);
//	std::cout << "排序后为：" << std::endl;
//	outPut(a, n);
//	std::cout<<""<<std::endl;
//	return 0;
//	system("pause");
//}
