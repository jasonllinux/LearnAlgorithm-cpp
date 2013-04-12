/*
 * utility.cpp
 *
 *  Created on: 2013-4-12
 *      Author: rescue01
 */

#include "utility.h"
#include <iostream>
#include <cstdlib>

//随机产生随机数组
void generateArray(int n[], int num) {
	srand(time(NULL));
	for (int i=0; i<num; i++) {

		n[i] = abs(rand())*100%100;
	}
}



void swap(int &a, int &b ) {
	int temp = b;
	b = a;
	a = temp;
}
