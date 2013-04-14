#include "selectSort.h"
#include "util/utility.h"
#include <iostream>
using namespace std;

void selectSort(int a[], int n) {
	cout<<"直接选择排序: ";
	int i, j, nMinIndex;
	for(i=0; i<n; i++) {
		nMinIndex = i;
		for(j=i+1; j<n; j++) {
			if(a[j]<a[nMinIndex]) {
				nMinIndex = j;
			}
		}
		swap(a[i], a[nMinIndex]);
	}
}



void testSelectSort() {
	int a[10];
	generateArray(a, 10);
	printArray(a, 10);

	selectSort(a, 10);
	printArray(a, 10);
}
