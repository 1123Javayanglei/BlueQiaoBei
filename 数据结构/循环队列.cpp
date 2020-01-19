#include<stdio.h>
#include<stdlib.h>
typedef struct seqqueue{
	int queue[10];
	int front;
	int rear;
}QUE;
void initqueue(QUE*que)
{
	que->front = 9;
	que->rear = 9;
}
void enqueue(QUE*que,int x){
	if((que->rear+1)%10==que->front){
		printf("队列已满无法进队"); 
		
	}
	else{
	que->rear=(que->rear+1)%10;
	que->queue[que->rear] = x; 
	}
	
}
void delqueue(QUE* que){
	if(que->front==que->rear)
	{
		printf("队列已空");
	}else{
		que->front=(que->front+1)%10;
	}
}
print(QUE* que)
{
	printf("队头");
	for(int i=(que->front+1)%10;i<=que->rear;i=(i+1)%10)
	{
		printf("-%d",que->queue[i]);
	}
	printf(":队尾") ;
}
int main()
{
    QUE* p=(QUE*)malloc(sizeof(QUE));
	initqueue(p);
	enqueue(p,100);
	enqueue(p,200);
	enqueue(p,300);
	enqueue(p,400);
	enqueue(p,500);
	enqueue(p,600);
	enqueue(p,700);
	enqueue(p,800);
	enqueue(p,900);
	enqueue(p,1000);
	print(p);
	return 0;
}
