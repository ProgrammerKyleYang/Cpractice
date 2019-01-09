#include "qs.h"
#include <iostream>
void qs(int a[], int low, int high) {
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
		qs(a, low, i - 1);
		qs(a, i + 1, high);
	}
}
