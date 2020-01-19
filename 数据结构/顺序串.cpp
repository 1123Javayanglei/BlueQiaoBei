#include<stdio.h>
#include<stdlib.h> 
//顺序串核心运算：插入、定位、删除
typedef struct sequencestring{
	char ch[50];
	int len ;
}STR; 
//插入在字符串s的下标为i的地方插入t 
void insert(STR* s,STR* t,int i) {
if(s->len+t->len>50){
	
	printf("超出容量插入失败");
}else if(i<0||i>s->len){
	printf("插入位置非法，插入失败");
}else{
	//后移t的长度个位置 
	for(int j=s->len-1;j>=i;j--){
		s->ch[j+t->len]=s->ch[j];
	}
	//赋值 
	for(int j=0;j<t->len;j++)
	{
		s->ch[i+j]=t->ch[j];
	}
	//修改长度 
	s->len =s->len+t->len;
}
} 
void myprint(STR* s){
	int i=0;
	printf("字符串的当前长度为%d ",s->len);
	for(i=0;i<s->len;i++)
	{
		printf("%c",s->ch[i]);
	}
	printf("\n"); 
} 



void dele(STR* s,int i,int j)
{
	if(i<0||i>s->len)
	{
		printf("删除位置非法删除失败");
	}else{
		//满足条件无需移动元素 
		if(i+j>=s->len)
		{
			s->len = i; 
		}else{
			for(int k=i+j;k<s->len;k++)
			{
				s->ch[k-j]=s->ch[k];
			}
			//修改长度
			s->len =s->len-j; 
		}
	}
	
}

int match(STR* s,STR* t,int i)
{
	int j;
	for(j=0;j<t->len;j++)
	{
		if(t->ch[j]!=s->ch[i+j])
		{
		return 0; 
	}
	
}
return 1;
}
//字符串t在字符串s中的位置 
int index(STR*s,STR*t){
	//遍历比较 
	for(int i=0;i<=s->len-t->len;i++){
		if(match(s,t,i)){
			return i;
			
		}
		
	} 
	
}


int main(){
	STR s1={"abcdefh",7};
	STR s2={"xyz",3};
	myprint(&s1);
	insert(&s1,&s2,2);
	myprint(&s1);
	dele(&s1,5,2);
	myprint(&s1);
	printf("s2的下标为%d",index(&s1,&s2));
	return 0;
}	 
