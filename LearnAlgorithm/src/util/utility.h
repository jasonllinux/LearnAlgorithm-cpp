/*
 * utility.h
 *
 *  Created on: 2013-4-12
 *      Author: rescue01
 */

#ifndef UTILITY_H_
#define UTILITY_H_

#define GET_ARRAY_LEN(array,len){len = (sizeof(array) / sizeof(array[0]));}


//产生num个从0到100的数组
void generateArray(int a[], int num);

void printArray(int a[], int num);

//交换数组中的两个数
void swap(int &a, int &b);

//void swap(int *a, int *b);


#endif /* UTILITY_H_ */
