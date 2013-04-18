#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


typedef struct student {
	int data;
	struct student * next;

}node;


typedef struct linkqueue {
	node * fisrt;
	node *rear;  //头和尾巴
} queue;


//入队列
queue *insert(queue* HQ, int x) ;


//出队列
queue *del(queue* HQ);
