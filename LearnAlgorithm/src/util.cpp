/*
 * util.cpp
 *
 *  Created on: 2013-3-10
 *      Author: rescue01
 */

#include "util.h"
#include <iostream>
#include <cstdlib>

//void swap(int *a, int *b) {
//	int tmp;
//	tmp = *a;
//	*a = *b;
//	*b = tmp;
//}


//随机产生随机数组
void generateArray(int n[], int num) {
	srand(time(NULL));
	for (int i=0; i<num; i++) {

		n[i] = abs(rand())*100%100;
	}
}
