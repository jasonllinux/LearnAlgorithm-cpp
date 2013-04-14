#include "mergeSort.h"
#include "util/utility.h"

using namespace std;

//合并两个数组
void mergeArray(int a[], int first, int mid, int last, int temp[]) {
	int i = first, j= mid+1;
	int m = mid; int n = last;
	int k = 0;

	while(i<=m && j<=n ) {
		if(a[i] <= a[j]) {
			temp[k++] = a[i++];
		}else {
			temp[k++] = a[j++];
		}
	}

	while(i <= m) {
		temp[k++] = a[i++];
	}
	while(j<=n) {
		temp[k++] = a[j++];
	}

	for(i=0; i<k; i++) {
		a[first+i] = temp[i];
	}
}



//归并排序
void mergeSort(int a[], int first, int last, int temp[]) {
	if(first< last) {
		int mid = (first+last)/2;
		mergeSort(a, first, mid, temp);
		mergeSort(a, mid+1, last, temp);
		mergeArray(a, first, mid, last, temp);
	}
}



//---------------------- 测试用例--------------------------
void testMergeSort() {
	int a[10];
	generateArray(a, 10);
	printArray(a, 10);
	int * p = new int[10];

	mergeSort(a, 0, 9, p);
	printArray(p, 10);
	delete p;

}

