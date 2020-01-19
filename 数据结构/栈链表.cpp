#include<stdio.h> 
#include<stdlib.h>

typedef struct link{
	int data;
	struct link* next;
}LINK;

void initstack(LINK* top)
{
	top->next=NULL;
}
//入栈
void push(LINK* top,int x)
{
	LINK* s=(LINK*)malloc(sizeof(LINK));
	s->data=x;
	s->next=top->next;
	top->next =s;
 } 
//出栈 
void pop(LINK* top){
	LINK* s=top->next;
	if(s==NULL){
		printf("栈空无法出栈");
	}
	else{
		top->next=s->next;
		free(s);
	}
}
void myprint(LINK* top)
{
	LINK* p=top->next;
	printf("栈顶：");
	while(p!=NULL)
	{
		printf("->%d",p->data);
		p=p->next;
	}
	printf("：栈底") ;
}




/**************************************执行方法*************************************************/
int main (){
	LINK* top=(LINK*)malloc(sizeof(LINK)); 
	initstack(top);
	push(top,100);
	push(top,200);
	push(top,300);
	push(top,400);
	push(top,500);
	push(top,600);
	push(top,700);
	push(top,800);
	push(top,900);
	 myprint(top);
	return 0; 
}
