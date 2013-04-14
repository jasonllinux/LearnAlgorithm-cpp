#include "heapSort.h"
#include "util/utility.h"

void minHeapFixUp(int a[], int i) {   //i 待插入的数据
	int j, temp;
	temp = a[i];
	j = (i - 1) / 2;  //父节点
	while (j >= 0 && i != 0) {
		if (a[j] <= temp) {   //拿出父节点比较
			break;
		}
		a[i] = a[j];      //较大的往下移动
		i = j;			//替换它的子节点
		j = (i - 1) / 2;		//往上爬

	}
	a[i] = temp;     // 最后赋值
}

//在数组末尾加入数据
void minHeapAddNum(int a[], int n, int num) {
	a[n] = num;
	minHeapFixUp(a, n);
}

void minHeapFixDown(int a[], int i, int n) {
	int j, temp;
	temp = a[i];
	j = 2 * i + 1;
	while (j < n) {
		if (j + 1 < n && a[j + 1] < a[j]) {
			j++;
		}
		if (a[j] >= temp) {
			break;
		}

		a[i] = a[j];
		i = j;
		j = 2 * i + 1;

	}
	a[i] = temp;
}

//堆化数组
void makeMinHeap(int a[], int n) {
	for(int i=n/2-1; i>=0; i--) {
		minHeapFixDown(a, i, n);
	}
}

//最终的排序算法
void makeHeapSort(int a[], int n) {
	for(int i=n-1; i>=1; i--) {
		swap(a[i], a[0]);
		minHeapFixDown(a, 0, i);
	}
}


//从数组中删除第一个数 然后自顶向下
void minHeapDelNum(int a[], int n) {
	swap(a[0], a[n - 1]);
	minHeapFixDown(a, 0, n - 1);
}
