#include "stack.h"


//TODO 入栈 有问题
stack *push(stack* HQ, int x) {
	node *s;
	s = (node *)malloc(sizeof(node));
	s->data = x;
	s->next = NULL;

	if(HQ->bottom == NULL) {
		HQ->bottom = s;
		HQ->top = s;
	}else {
		HQ->top->next = s;
		HQ->top = s;
	}
	return HQ;
}


//出栈
stack* pop(stack* HQ) {
	node *p;
//	int x = 0;

	if(HQ->bottom == NULL) {
		printf("栈溢出  \n");
	}else {
//		x = HQ->bottom->data;
		p = HQ->bottom;
		if(HQ->top == HQ->bottom) {
			HQ->bottom = NULL;
			HQ->top = NULL;
		}else {
			while(p->next != HQ->top) {
				p = p->next;
			}
			HQ->top = p;
			HQ->bottom->next = NULL;
		}
		return HQ;
	}

	return NULL;
}
