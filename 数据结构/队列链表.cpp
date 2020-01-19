#include<stdio.h> 
#include<stdlib.h>
typedef struct link{
	int data;
	struct link* next;
}LINK;
typedef struct linkqueue{
	LINK* front;
	LINK*rear;
}QE;
void initqueue(QE* qu){
	LINK* head=(LINK*)malloc(sizeof(LINK));
	head->next=NULL;
	qu->front=head;
	qu->rear=head;
}
void enqueue(QE* qu, int x){
   LINK* s=(LINK*)malloc(sizeof(LINK));
   s->data=x;
   s->next=NULL;
   LINK* p = qu->rear;
   p->next=s; 
   qu->rear=s;
}
void delqueue(QE* qu){
	if(qu->front==qu->rear)
	{
		printf("队空,无法处理！"); 
	}else{
		LINK* head=qu->front;
		LINK* p=qu->front->next;
		head->next=p->next;
		
	}
}
void myprint(QE* qu){
	LINK* p=qu->front->next;
	printf("队尾："); 
	while(p!= NULL)
	{
		printf("->%d",p->data);
		p=p->next;
	}
	printf(":队尾");
}

int main(){
	QE* qu=(QE*)malloc(sizeof(QE));
	initqueue(qu);
	enqueue(qu,100);
	enqueue(qu,200);
	enqueue(qu,300);
	enqueue(qu,400);
	enqueue(qu,500);
	enqueue(qu,600);
	enqueue(qu,700);
	enqueue(qu,800);
	enqueue(qu,900);
	myprint(qu);
	return 0;
}
