#include<stdio.h>
#include<stdlib.h>
typedef struct seqstack
{
	int stack[10];
	int top;
}STA;
void initstack(STA* sta)
{
	sta->top=0;
}
void push(STA* sta,int x)
{
	if(sta->top>=10)
	{
		printf("������,ջ���޷���ջ");
	}
	sta->stack[sta->top]=x;
	sta->top++;
}
void pop(STA*sta)
{
	if(sta->top==0){
	printf("ջ�գ��޷���ջ");	
	}else{
		sta->top--;
	}
 } 
 void print(STA*sta)
 {
 	printf("ջ�ף�");
	 for(int i=0;i<sta->top;i++)
	 {
	 	printf("-%d",sta->stack[i]);
	  } 
	  printf("ջ��\n");
 }
int main(){
	STA* p=(STA*)malloc(sizeof(STA));
	initstack(p);
	push(p,100);
	push(p,200);
	push(p,300);
	push(p,400);
	push(p,500);
	print(p);
	pop(p);
	print(p); 
	return 0;
}
