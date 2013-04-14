/*
 * main.cpp
 *
 *  Created on: 2013-3-10
 *      Author: rescue01
 */

#include <iostream>
#include "sort/sort.h"
#include "stdio.h"
#include "string/string_util.h"
#include "util/utility.h"
#include <ctime>

using namespace std;

clock_t start, end;

//test
void testCases();
void testPointerSize();
void testSize();
void testIntArray();
void testSwap();

//测试的总入口
int main(void) {
	start = clock();

	testCases();

	end = clock();
//	printf("run time: %f \n", double(end-start));

	return 0;
}

void testCases() {
	//	testBubbleSort();
	//	testPointerSize();
	//	testSize();
	//	testIntArray();
	//	testSwap();
	//	testQuickSort();

	//	test_atoi();
	//	test_itoa();
	//	test();
	//	test_string_copy();
	//	test_string_match();
	testInsertSort();
}

void testIntArray() {
	int num[10] = { };
	generateArray(num, 10);
	for (int i = 0; i < 10; i++) {
//		cout<<*(num+i)<<endl;
		cout << num[i] << endl;
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
	printf("a is: %d \n", a);
	printf("b is: %d \n ", b);
}
