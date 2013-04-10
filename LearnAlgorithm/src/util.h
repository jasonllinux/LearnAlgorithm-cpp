/*
 * util.h
 *
 *  Created on: 2013-3-10
 *      Author: rescue01
 */



#define GET_ARRAY_LEN(array,len){len = (sizeof(array) / sizeof(array[0]));}

//void swap(int *a, int *b);


//产生num个从0到100的数组
void generateArray(int a[], int num);



//交换数组中的两个数
inline void swap(int &a, int &b ) {
	int temp = b;
	b = a;
	a = temp;
}
