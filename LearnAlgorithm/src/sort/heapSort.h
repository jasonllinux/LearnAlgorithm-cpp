
 /*
  *Heap
  *堆排序
  *最小堆
  *
  */


void minHeapFixUp(int a[], int i);
void minHeapAddNum(int a[], int n, int num);

void minHeapFixDown(int a[], int i, int n);
void minHeapDelNum(int a[], int n);


void makeMinHeap(int a[], int n);
void makeHeapSort(int a[], int n);

//测试用例
void testHeapSort();
