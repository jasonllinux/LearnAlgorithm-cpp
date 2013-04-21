
#include "singleList.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>

using namespace std;

//生成链表
node* createSingleList() {
	node *head, *p, *s;
	int x;
	bool isCycle = true;  //判断是否要继续创建
	head = (node *)malloc(sizeof(node));
	p = head;

	while(isCycle) {
		printf("please input a data: \n");
		scanf("%d", &x);
		//判断输入是否合法
		if(x != 0 && x!='\n') {
			s = (node *)malloc(sizeof(node));
			s->data = x;
//			printf("%d \n", s->data);
			p->next = s;
			p = s;
//			free(s);
		}else {
			isCycle = false;
		}
	}
	head = head->next;  //最早的一个的内容是NULL
	p->next = NULL;
	return head;
}

//获得链表长度
int length(node *head) {
	int n = 0;
	node *p;
	p = head;
	while(p!=NULL) {
		p = p->next;
		n++;
	}

	return n;
}


//打印链表
void print(node *head) {
	node *p;
	int n;
	n = length(head);
	printf("These %d records are:  \n",n);
	p = head;
	if(head == NULL) {
		return ;
	}
	while(p!=NULL) {
		printf(" %d ,", p->data);

		p = p->next;
	}
	printf("\n");
}


//删除某个节点
node *del(node *head, int num) {
	printf("delete a num node : %d" , num);
	node *p1, *p2;
	p1 = head;
	while(num != p1->data && p1->next!=NULL) {
		p2 = p1;
		p1 = p1->next;
	}

	if(num == p1->data) {
		//如果是头节点
		if(p1==head) {
			head = p1->next;
			free(p1);
		}else {
			p2->next = p1->next;
//			free(p1); //TODO 测试
		}
	}else {
		printf("%d could not been found ", num);

	}
	return head;
}


//插入某个节点
node *insert(node *head, int num) {
	printf("insert a num: %d \n", num);
	node *p0, *p1, *p2;  //p1 p2 原始的相邻的两个指针
	p1 = head;
	p0 = (node *)malloc(sizeof(node));
	p0->data = num;
	while(p0->data>p1->data && p1->next!=NULL) {
		p2 = p1;
		p1 = p1->next;
	}
	if(p0->data <= p1->data) {
		if(head == p1) {
			//要在head节点插入
			p0->next = p1;
			head = p0;
		}else {
			//普通情况下
			p2->next = p0;
			p0->next = p1;
		}
	}else {
		//TODO 只有一个头节点吗
		p1->next = p0;
		p0->next = NULL;
	}
	return head;
}


//TODO 简单排序
node *sort(node *head) {
	printf("sort the list \n");
	node *p;
	int n, temp;
	n = length(head);

	if(head ==NULL || head->next == NULL) {  //头结点为空或者 只有一个头节点
		return head;
	}

	p = head;
	//冒泡排序 (经过上面判断 必有两个元素以上)
	for(int j=1; j<n; ++j) {
		p = head;  //每趟从head节点开始
		for(int i=0; i<n-j; ++i) {
			if(p->data > p->next->data) {
				//交换
				temp = p->data;
				p->data = p->next->data;
				p->next->data = temp;
			}
			p = p->next;
		}

	}
	return head;
}

//----------------------测试用例-------------------
void testSingleList() {
	node *head =  createSingleList();
//	int len = length(head);
//	printf("length is : %d", len);
	print(head);
	head = del(head, 2);
	print(head);
	head = insert(head, 2);
	print(head);
	head = sort(head);
	print(head);

}
