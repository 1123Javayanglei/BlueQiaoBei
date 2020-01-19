 #include<stdio.h>
#include<stdlib.h> 
typedef struct sequenlist {
	int a[10];
	int len;
}SEQ;

void init(SEQ* seq){
	seq->a[0]=0;
	seq->len=0;
}

void insert(SEQ* seq,int i,int x) 
{
	if(i>9){
		printf("插入位置超过最大长度"); 
	}
	else if(i<1||i>seq->len+1)
	{
		printf("插入非法");
		
	}else{
		for(int j=seq->len;j>=i;j--)
		{
			seq->a[j+1]=seq->a[j];
		}
		seq->a[i]=x;
		seq->len++;
	}
}

void myprint(SEQ* seq){
	printf("顺序表的当前长度为%d:",seq->len);
	for(int i=1;i<=seq->len;i++)
	{
		printf("-%d",seq->a[i]);
	}
	printf("\n");
	
} 
void dele(SEQ* seq,int i)
{
	if(i<1||i>seq->len)
	{
		printf("删除报错"); 
	}
	else{
		for(int j=i+1;j<=seq->len;j++)
		{
			seq->a[j-1]=seq->a[j];
			
		}
		seq->len--;
		printf("删除成功\n");
	}
}
locate(SEQ* seq,int x)
{
	for(int i=1;i<=seq->len;i++)
	if(seq->a[i]==x)
	{
		return i;
	}
		printf("未定位到%d\n",x);
		return -1;	
}
void qianqu(SEQ* seq,int c)
{
	for(int i=1;i<=seq->len;i++)
	{
		if(seq->a[i]==c)
		{
			printf("前驱为%d\n",seq->a[i-1]);
		}
	}

	
}
int prior(SEQ* seq,int x)
{
	int i=locate(seq,x);
	if(i==-1)
	{
		printf("%d不在顺序表中",x);
	}
	else if(i==1) 
	{
		printf("%d是第一个元素，没有前驱",x);
	}
	else{
		return seq->a[i-1];
	}
}

int main()
{
	SEQ* p=(SEQ*)malloc(sizeof(SEQ));
	init(p);
	insert(p,1,100);
	insert(p,1,200);
	insert(p,1,300);
	insert(p,1,400);
	insert(p,1,500);
	myprint(p);
	qianqu(p,400);
	dele(p,3);
	myprint(p);
	printf("定位%d的下标是%d\n",200,locate(p,200));
	printf("%d的直接前驱是%d",400,prior(p,400));
	
	return 0;
	
}
