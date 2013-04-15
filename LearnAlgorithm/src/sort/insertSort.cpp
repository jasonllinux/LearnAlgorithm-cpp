#include "insertSort.h"
#include "util/utility.h"
#include <iostream>
#include <stdio.h>
using namespace std;

//直接插入排序
void directInsertSort(int num[], int n) {
	cout << "直接插入排序: " << endl;
	int i, j;
	int temp;

	//逐个记录插入有序序列
	for (i = 1; i < n; i++) {
		temp = num[i];
		//把num[i]插入有序序列
		for (j = i - 1; j >= 0; j--) {
			if (temp < num[j]) {
				num[j + 1] = num[j];
			} else {
				break;
			}
		}
		num[j + 1] = temp; //上面--了
	}

}

//----------------------------------------------------------
//折半插入排序(减少比较次数)

void binaryInsertSort(int num[], int n) {
	cout << "折半插入排序 \n";

	int i, j, site, temp;
	for (i = 1; i < n; i++) {
		//折半查找要插入的位置
		site = binarySearch(num, 0, i, num[i]);
//		printf("site: %d", site);
		temp = num[i];

		//移位
		for (j = i; j>site; j--) {
			num[j] = num[j-1];
		}
		//插入
		num[site] = temp;
	}
}

//二分搜索
int binarySearch(int a[], int low, int high, int key) {
//	printf("low: %d, high %d, key %d \n", low, high, key);
	int mid = (low + high) / 2;
//	printf("mid: %d ,a[mid] %d \n", mid, a[mid]);
	if (low > high) {   //注意这里!!!!!!!!
		return low;
	}
	if (a[mid] == key) {
		return mid;
	} else if (key < a[mid]) {
		return binarySearch(a, low, mid-1, key);
	} else
		return binarySearch(a, mid+1, high, key);
}

//----------------------------------------------------------



//--------------Shell Sort-------------------------------
//一趟增量为dk的排序
void shellInsert(int a[], int n, int dk) {
	int i, j, temp;
	for (i = dk; i < n; i += dk) {
		temp = a[i];
		for (j = i-dk; j >= 0; j -= dk) {
			if (a[j] > temp) {
				a[j+dk] = a[j];
			} else
				break;
		}
		a[j+dk] = temp;      //最后插入赋值在这里
	}
}

void shellSort(int a[], int n) {
	cout << "Shell Sort............\n";
	int dk[] = { 5, 4, 3, 2, 1 };       //最后一个增量必须为1
	for (int i = 0; i < 5; i++) {
		shellInsert(a, n, dk[i]);
	}
}

//-------------------测试用例-------------------------

void testInsertSort() {
	int num[10] = { 76, 28, 24, 88, 80, 56, 52, 89, 32, 16 };
//	int num[10];
//	printf("n is : %d", binarySearch(num,0,1,28 ));
//	generateArray(num, 10);
	printArray(num, 10);

	//method
//	directInsertSort(num, 10);   //done
//	binaryInsertSort(num, 10);  //done
	shellSort(num, 10); //?????????????

	printArray(num, 10);

}
