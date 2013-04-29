#include "stack.h"


//压栈
stack *push(stack* HQ, int x) {
	node *s;
	s = (node *)malloc(sizeof(node));
	s->data = x;
	s->next = NULL;

	//入栈
	if(HQ->bottom == NULL) {
		HQ->bottom = s;
		HQ->top = s;
	}else {
		//压栈
		HQ->top->next = s;  // 栈的next是 从底向上的
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
			}  //找出第二高的栈元素
			HQ->top = p;  //改变栈顶元素
			HQ->bottom->next = NULL;
		}
		return HQ;
	}

	return NULL;
}
