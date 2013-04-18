



typedef struct student {
	int data;
	struct student *next;
}node;


//生成链表
node* createSingleList();

//获得链表长度
int length(node *head);

//打印链表
void print(node *head);


node *del(node *head, int num);


node *insert(node *head, int num);


node *sort(node *head);



void testSingleList();
