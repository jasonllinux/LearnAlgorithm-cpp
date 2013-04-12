/*
 * sort.cpp
 *
 *  Created on: 2013-3-10
 *      Author: SHEN JIE
 */


#include <iostream>
#include "sort.h"
//TODO 头文件包含问题
#include "util/utility.h"

using namespace std;

void bubbleSort1(int a[], int n) {
	int i, j;
	bool need = true;  //如果已经拍好序  就不要排了
	for(i=0; i<n && need; i++) {
		need = false;
		for(j=0; j<n-i; j++) {
			if(a[j] > a[j+1]) {
				//交换两个数
				swap(a[j], a[j+1]);
				need = true;
			}
		}
	}
}


// 改进型的 冒泡排序
void bubbleSort2(int a[], int n) {

}


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

//-------------------测试用例----------------------------


void testBubbleSort() {
	cout<<"Test Bubble Sort.................."<<endl;
	int data[] = {1, 8, 5, 98, 56, 88, 45};
		bubbleSort1(data, 6);
		for(int i=0; i<=6; i++) {
			cout<< data[i]<< ",";
		}

		cout<<endl<<endl;
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
