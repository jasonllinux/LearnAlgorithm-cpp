#include "insertSort.h"
#include "util/utility.h"
#include <iostream>
using namespace std;

//直接插入排序
void directInsertSort(int num[], int n) {
	cout<<"直接插入排序: "<<endl;
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

//折半插入排序
void binaryInsertSort(int num[], int n) {
	int i, j, site, temp;
	for (i = 1; i < n; i++) {
		//折半查找要插入的位置
		site = binarySearch(num, 0, n - 1, num[i]);
		temp = num[i];
		//移位
		for (j = i; j > site; j--) {
			num[j] = num[j - 1];
		}
		//插入
		num[site] = temp;
	}
}


//二分搜索
int binarySearch(int a[], int low, int high, int key) {
	int mid = (low + high) / 2;
	if (low > high) {
		return low;
	}
	if (a[mid] == key) {
		return mid;
	} else if (key < a[mid]) {
		return binarySearch(a, low, mid - 1, key);
	} else
		return binarySearch(a, mid, high, key);
}



//---------------------------------------------
void shellInsert(int a[], int n, int dk) {
	int i, j, temp;
	for(i=dk+1; i<n; i+=dk) {
		temp = a[i];
		for(j=i-dk; j>=0; j-=dk) {
			if(a[j] > temp) {
				a[j+dk] = a[j];
			}else
				break;
			a[j+dk] = temp;
		}
	}
}


void shellSort(int a[], int n) {

	int dk[] ={5, 4, 3, 2, 1, 0};
	for(int i=0; i<5; i++) {
		shellInsert(a, n, dk[i]);
	}
}




//-------------------测试用例-------------------------

void testInsertSort() {
	int num[10];
	generateArray(num, 10);
	printArray(num, 10);

	//method
	directInsertSort(num, 10);
//	binaryInsertSort(num, 10);  //??????????????
//	shellSort(num, 10); //?????????????

	printArray(num, 10);

}
