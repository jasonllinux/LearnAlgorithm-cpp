/*
 * utility.cpp
 *
 *  Created on: 2013-4-12
 *      Author: rescue01
 */

#include "utility.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

//随机产生随机数组
void generateArray(int n[], int num) {

	srand(time(NULL));
	for (int i=0; i<num; i++) {
		n[i] = abs(rand() * 100 % 100);
	}
}

void printArray(int a[], int n) {
	printf("\n");
	for (int i = 0; i <= n-1; i++) {
		printf("%d  ", a[i]);
	}
	printf("\n");
}


void swap(int &a, int &b ) {
	int temp = b;
	b = a;
	a = temp;
}
