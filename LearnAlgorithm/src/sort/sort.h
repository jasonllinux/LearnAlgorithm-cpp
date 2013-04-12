/*
 * sort.h
 *
 *  Created on: 2013-3-10
 *      Author: rescue01
 */

#ifndef SORT_H_
#define SORT_H_

//#include "util/utility.h"

void bubbleSort1(int a[], int n);
void bubbleSort2(int a[], int n);


void quickSort(int a[], int l, int r);
int adjustArray(int a[], int l, int r);




//------------------测试用例---------------
void testBubbleSort();
void testQuickSort();


#endif /* SORT_H_ */
