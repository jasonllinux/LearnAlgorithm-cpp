/*
 * sort.cpp
 *
 *  Created on: 2013-3-10
 *      Author: SHEN JIE
 */


#include "sort.h"
#include "util.h"

void bubbleSort1(int a[], int n) {
	int i, j;
	bool need = true;  //如果已经拍好序  就不要排了
	for(i=0; i<n && need; i++) {
		need = false;
		for(j=0; j<n-i; j++) {
			if(a[j] > a[j+1]) {
//				swap(&a[j], &a[j+1]);  //TODO
				need = true;
			}
		}
	}
}


// 改进型的 冒泡排序
void bubbleSort2(int a[], int n) {

}


void quickSort(int a[], int l, int r) {
	if(l<r) {
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
