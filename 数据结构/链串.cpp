/*
链串的实现
核心运算：插入，删除，定位 
与链表区别：链表操作的是1个元素，链串是多个
*/
#include<stdio.h>
#include<stdlib.h>
//结构体
 typedef struct linkstring{
     char data;  //元素类型
	 struct linkstring*next;//指针存放下一个元素的地址  
 }LS;
 


//头插法
LS*headcreate(int n){     //节点的个数
      LS*p;
      LS*head=(LS*)malloc(sizeof(LS));       //为head申请存储空间 
      head->next=NULL;      //  head的下一个元素地址为空
	  for(int i=1;i<=n;i++)    //o为头结点为空从1开始插入 
	  {
	  	  p=(LS*)malloc(sizeof(LS));  // 为p申请存储空间 
		  printf("请输入第%d个字符：",i);     
		  scanf(" %c",&p->data) ;    //输入p的元素类型 
		  p->next=head->next;       
		  head->next=p;           // 
	   } 
         return head;
	
} 
//打印链串
void myprint(LS* head)
{
	printf("链串为：");
	LS* p= head->next;
	while(p!=NULL)
	{
		printf(" %c",p->data);   //输出p的元素类型 
		p=p->next;        //p向下游走循环输出 
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
	 	printf("插入位置非法，插入失败");
		  
	 }else{
	 	q = s->next;
	 	while((q!=NULL)&&(k<j)){
	 	   q = q->next;
			k++;	
		 }
		 if(q == NULL){
		 	//元素不够，释放i之后的所有节点 
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
