/*
 * main.cpp
 *
 *  Created on: 2013-3-10
 *      Author: rescue01
 */

#include "util.h"
#include "sort.h"
#include "stdio.h"
#include <iostream>

using namespace std;

//test
void testBubbleSort();
void testQuickSort();
void testPointerSize();
void testSize();
void testIntArray();
void testSwap();

int main_test(void) {
//	testBubbleSort();
//	testPointerSize();
//	testSize();
//	testIntArray();
//	testSwap();
	testQuickSort();
	return 0;
}

void testBubbleSort() {
	cout<<"Test Bubble Sort.................."<<endl;
	int data[] = {1, 8, 5, 98, 56, 88, 45};
		bubbleSort1(data, 6);
		for(int i=0; i<=6; i++) {
			cout<< data[i]<< ",";
		}

		cout<<endl<<endl;
}


void testIntArray() {
	int num[10] = {};
	generateArray(num, 10);
	for(int i=0; i<10; i++) {
//		cout<<*(num+i)<<endl;
		cout<<num[i]<<endl;
	}
}

//TODO 测试快速排序
void testQuickSort() {
	int data[] = {1, 8, 5, 98, 56, 88, 45, 12, 15, 8, 95};
	int length = 0;
	GET_ARRAY_LEN(data, length);

	quickSort(data, 0 , length-1);
	for(int i=0; i<5; i++) {

		cout<<data[i]<<endl;
	}
}


void testPointerSize() {

	cout << "Test Pointer Size ..........." << endl;
	cout << "Size int *: ";
	cout << sizeof(int*);
	cout << endl;
	cout << "Size double *: ";
	cout << sizeof(double*);
	cout << endl;

}

void testSize() {

}


void testSwap() {
	int a = 4;
	int b = 10;
	swap(a, b);
	printf( "a is: %d \n" , a );
	printf("b is: %d \n ", b );
}
