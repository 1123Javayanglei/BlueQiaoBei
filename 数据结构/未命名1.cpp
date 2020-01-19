#include<stdio.h>
#include<stdlib.h>
typedef struct link {
	int data;
	struct link*next;
}LINK;
LINK* headcreat(int n)
{
	LINK* head = (LINK*)malloc(sizeof(LINK));
	//申请空间 
	head->data = n;
	//空间长度为5 
	head->next = NULL;
	//head的下一个值为空 
	for (int i = 0; i < n; i++) {
		//遍历输入 
		LINK* p = (LINK*)malloc(sizeof(LINK));
		//为p申请空间 
		printf("请输入第%d结点的值：",(i + 1));
	
		scanf("%d", &p->data);
		
		p->next = head->next;
		
		head->next = p;
		
	}
	
	return head;
}
void print(LINK* head) {
	LINK* p = head->next;
	while (p != NULL)
	{
		printf("->%d", p->data);
		p = p->next;
	}
    printf("\n");

}
LINK* locate(LINK* head,int x)
{
	LINK* p=head->next;
	while(p!=NULL)
	{
		if(p->data==x)
		{
			printf("已定位到%d\n",x);
			break;
		}
		else{
			p=p->next; 
		}
	}
	return p;
}
void insert (LINK* head,int x,int y){
	LINK* p=locate(head,y);
	if(p==NULL)
	{
	
	printf("%d在链表中不存在，插入非法",y);
}
else{
	LINK* q=(LINK*)malloc(sizeof(LINK));
	q->data=x;
	q->next=p->next;
	p->next=q;
}
}
void shanchu(LINk* head,int f) 
{
	q=head
	p=head->next
	while(p!=NUll&&p!=f)
	{
		q=p;
		p=p->next;
	}
	
	if(p!=NULL)
	{
		q->next=p->next;
		free(p);
	} 
	 
}

int main()
{
	LINK* head = headcreat(5);
	print(head);
	locate(head,10);
	insert(head,100,20);
	print(head);
	system("pause");
	return 0;
}
