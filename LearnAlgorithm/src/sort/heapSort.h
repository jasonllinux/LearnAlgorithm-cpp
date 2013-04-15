
 /*
  *Heap
  *堆排序
  *最小堆
  *
  */

//从顶向下 roll down
void minHeapFixUp(int a[], int i);
void minHeapAddNum(int a[], int n, int num);


//从底向上 roll up
void minHeapFixDown(int a[], int i, int n);
void minHeapDelNum(int a[], int n);

//构造堆
void makeMinHeap(int a[], int n);
//堆排序
void makeHeapSort(int a[], int n);

//测试用例
void testHeapSort();
