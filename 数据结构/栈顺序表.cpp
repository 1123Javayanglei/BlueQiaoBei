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
		printf("±¨¸ö´í,Õ»ÂúÎÞ·¨ÈëÕ»");
	}
	sta->stack[sta->top]=x;
	sta->top++;
}
void pop(STA*sta)
{
	if(sta->top==0){
	printf("Õ»¿Õ£¬ÎÞ·¨ÍËÕ»");	
	}else{
		sta->top--;
	}
 } 
 void print(STA*sta)
 {
 	printf("Õ»µ×£º");
	 for(int i=0;i<sta->top;i++)
	 {
	 	printf("-%d",sta->stack[i]);
	  } 
	  printf("Õ»¶¥\n");
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
