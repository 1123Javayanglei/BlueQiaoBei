/*
������ʵ��
�������㣺���룬ɾ������λ 
���������������������1��Ԫ�أ������Ƕ��
*/
#include<stdio.h>
#include<stdlib.h>
//�ṹ��
 typedef struct linkstring{
     char data;  //Ԫ������
	 struct linkstring*next;//ָ������һ��Ԫ�صĵ�ַ  
 }LS;
 


//ͷ�巨
LS*headcreate(int n){     //�ڵ�ĸ���
      LS*p;
      LS*head=(LS*)malloc(sizeof(LS));       //Ϊhead����洢�ռ� 
      head->next=NULL;      //  head����һ��Ԫ�ص�ַΪ��
	  for(int i=1;i<=n;i++)    //oΪͷ���Ϊ�մ�1��ʼ���� 
	  {
	  	  p=(LS*)malloc(sizeof(LS));  // Ϊp����洢�ռ� 
		  printf("�������%d���ַ���",i);     
		  scanf(" %c",&p->data) ;    //����p��Ԫ������ 
		  p->next=head->next;       
		  head->next=p;           // 
	   } 
         return head;
	
} 
//��ӡ����
void myprint(LS* head)
{
	printf("����Ϊ��");
	LS* p= head->next;
	while(p!=NULL)
	{
		printf(" %c",p->data);   //���p��Ԫ������ 
		p=p->next;        //p��������ѭ����� 
	}
 } 
 void insert(LS* p,LS* q,int i) 
 {
 	
 }
 
 void dele(LS* p,int i,int j)
 {
 	int k = 0;
 	int l= 0;
 	LS* s = p;
 	LS* q;
 	while((s!=NULL)&&(l<i-1))
 	{
 		s = s->next;
 		 l++;
	 }
	 if(s == NULL)
	 {
	 	printf("����λ�÷Ƿ�������ʧ��");
		  
	 }else{
	 	q = s->next;
	 	while((q!=NULL)&&(k<j)){
	 	   q = q->next;
			k++;	
		 }
		 if(q == NULL){
		 	//Ԫ�ز������ͷ�i֮������нڵ� 
		 	s->next = NULL;
		 }else{
		 	s->next = q;
		 }
	 }
 }
int main()
{
	LS*p1=headcreate(5);
	LS*p2=headcreate(3);
	myprint(p1);
	myprint(p2);
	dele(p1,2,2);
	myprint(p1);
	return 0;
 } 
