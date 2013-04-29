#include "queue.h"


//入队
queue *insert(queue* HQ, int x)  {
	node *s;
	s = (node *)malloc(sizeof(node));
	s->data = x;
	s->next = NULL;

	if(HQ->rear == NULL) {  //判断队列为空
		HQ->fisrt = s;
		HQ->rear =s;
	}else {
		HQ->rear->next = s;  //从队列尾部插入
		HQ->rear = s;
	}

	return HQ;
}


//出队
queue *del(queue* HQ) {
	node *p;
//	int xx;
	if(HQ->fisrt == NULL) {
		printf("队列溢出 \n");
	}else {
//		xx = HQ->fisrt->data;
		p = HQ->fisrt;
		if(HQ->fisrt ==  HQ->rear) {  //如果只有一个元素
			HQ->fisrt = NULL;
			HQ->rear = NULL;
		}else {
			//fisrt向后退一个 删除原先的第一个
			HQ->fisrt = HQ->fisrt->next;
			free(p);
		}
		return HQ;
	}
	return NULL;
}
