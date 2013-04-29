#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


typedef struct student {
	int data;
	struct student * next;
}node;


typedef struct stackqueue {
	node * bottom, *top;  //栈底和栈顶
} stack;

stack *push(stack* HQ, int x);

stack* pop(stack* HQ);
