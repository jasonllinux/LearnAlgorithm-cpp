#include "bubbleSort.h"
#include "util/utility.h"
#include <iostream>
using namespace std;


void bubbleSort1(int a[], int n) {
	int i, j;
	bool need = true;  //如果已经拍好序  就不要排了
	for(i=0; i<n && need; i++) {
		need = false;
		for(j=0; j<n-i; j++) {
			if(a[j] > a[j+1]) {
				//交换两个数
				swap(a[j], a[j+1]);
				need = true;
			}
		}
	}
}


// 改进型的 冒泡排序
void bubbleSort2(int a[], int n) {

}



//

void testBubbleSort() {
	cout<<"Test Bubble Sort.................."<<endl;
	int data[] = {1, 8, 5, 98, 56, 88, 45};
		bubbleSort1(data, 6);
		for(int i=0; i<=6; i++) {
			cout<< data[i]<< ",";
		}

		cout<<endl<<endl;
}

