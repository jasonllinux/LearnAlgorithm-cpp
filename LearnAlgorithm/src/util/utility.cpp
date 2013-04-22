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

//数组逆序
void reverse(int a[], int i, int j) {
	int n = j-i+1;  //数组元素个数
//	printf("n: %d",n);
	int max = n/2 + i;  //边界值
//	printf("max: %d \n",max);
	int temp;		//临时存储变量
	for(; i<max; i++) {
//		printf("i : %d j: %d \n", i, j);
//		printf("move %d %d \n", a[i], a[j--]);
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		j--;    //这个很重要
//		printArray(a, 8);
	}
}


//数组循环移位
void cycleMove(int a[], int n, int i) {  //n为数组长度 i为移位的那个点
	printf("循环移 %d 位 \n", i+1);
	reverse(a, 0, i);
	reverse(a, i+1, n-1);
	reverse(a, 0, n-1);
}

//数组逆序 参考版本
//void change(int array[],int n)
//{
//   int i,temp;
//   for(i=0;i<n/2;i++)
//   {
//     temp=array[i];
//     array[i]=array[n-1-i];
//     array[n-1-i]=temp;
//   }
//}

void test_util() {
	int a[] = {1, 2, 3, 4 ,5,6,7,8};
	printArray(a, 8);
//	reverse(a, 0, 3);
//	change(a, 4);
	cycleMove(a, 8, 2);
	printArray(a, 8);
}
