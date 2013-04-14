

#include "quickSort.h"
#include "util/utility.h"
#include <iostream>
using namespace std;


void quickSort(int a[], int l, int r) {
	if(l < r) {
		int i = adjustArray(a, l, r);
		quickSort(a, l, i-1);
		quickSort(a,i, r);
	}
}


int adjustArray(int a[], int l, int r) {

	int i = l;
	int j = r;
	int x = a[i];  //以第一个数为主元（基准数）
	while(i<j) {

		while(i<j && a[j]>=x) {
			j--;
		}
		if(i<j) {
			a[i] = a[j];
			i++;
		}

		while(i<j && a[i]<=x) {
			i++;
		}
		if(i<j) {
			a[j] = a[i];
			j--;
		}

	}
	a[i] = x;
	return i;

}





void testQuickSort() {
	int data[] = {1, 8, 5, 98, 56, 88, 45, 12, 15, 8, 95};
	int length = 0;
	//获得数组的长度
	GET_ARRAY_LEN(data, length);

	quickSort(data, 0 , length-1);
	for(int i=0; i<5; i++) {

		cout<<data[i]<<endl;
	}
}
