/*
ʵ������ 
*/ 
#include <stdio.h>
#include <stdlib.h>
typedef struct link{
	int data;
	struct link* next;
}LK;
//ͷ�巨����������
LK* headcreate(int n){
	int i;
	LK* s;
	LK* head=malloc(sizeof(LK));
	head->data=10;
	head->next=NULL;
	for(i=1;i<=n;i++){
		s=malloc(sizeof(LK));
		printf("�������%d������ֵ��",i);
		scanf("%d",&s->data);
		s->next=head->next;
		head->next=s;
	}
	return head;
} 
void myprint(LK* head){
	LK* p=head->next;
	while(p!=NULL){
		printf("->%d",p->data);
		p=p->next;
	}
	printf("\n");
}
//��λ
LK* locate(LK* head,int x){
	LK* p=head->next;
	while(p!=NULL){
		if(p->data==x){
			return p;
		}
		p=p->next;
	}
	return p;
} 
int locate2(LK* head,int x){
	LK* p=head;
	int num=0;
	while(p->next!=NULL){
		p=p->next;
		num++;
		if(p->data==x){
			return num;
		}
	}
	return 0;
}
//����,������ֵΪy�Ľ������x��� 
void insert(LK* head,int x,int y){
	LK* p;
	LK* q=locate(head,y);
	if(NULL==q){
		printf("%d�������в����ڣ��޷�ȷ������λ��");	
	}else{
	p=malloc(sizeof(LK));
	p->data=x;
	p->next=q->next;
	q->next=p;
	}

} 
void dele(LK* head,int x){
	LK* q=head;
	LK* p=head->next;
	while(p!=NULL){
		if(p->data==x){
			break;
		}
		p=p->next;
		q=q->next;
	}
	if(NULL==p){
		printf("%d�������в����ڣ��޷�ɾ��",x);
	}else{
		q->next=p->next;
		free(p);
	}
}
int main(){
	LK* head=headcreate(5);
	myprint(head);
	insert(head,123,300);
	myprint(head);
	printf("��λ123���������ǵ�%d��\n",locate2(head,123));
	printf("��λ1000���������ǵ�%d��\n",locate2(head,1000));
	dele(head,200);
	myprint(head);
	dele(head,1000);
	myprint(head);
	return 0;
}
