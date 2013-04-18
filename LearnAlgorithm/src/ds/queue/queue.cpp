#include "queue.h"


//入队列
queue *insert(queue* HQ, int x)  {
	node *s;
	s = (node *)malloc(sizeof(node));
	s->data = x;
	s->next = NULL;

	if(HQ->rear == NULL) {
		HQ->fisrt = s;
		HQ->rear =s;
	}else {
		HQ->rear->next = s;
		HQ->rear = s;
	}

	return HQ;
}


//出队列
queue *del(queue* HQ) {
	node *p;
//	int xx;
	if(HQ->fisrt == NULL) {
		printf("队列溢出 \n");
	}else {
//		xx = HQ->fisrt->data;
		p = HQ->fisrt;
		if(HQ->fisrt ==  HQ->rear) {
			HQ->fisrt = NULL;
			HQ->rear = NULL;
		}else {
			HQ->fisrt = HQ->fisrt->next;
			free(p);
		}
		return HQ;
	}
	return NULL;
}
