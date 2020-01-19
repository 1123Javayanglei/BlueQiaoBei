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
		printf("����λ�ó�����󳤶�"); 
	}
	else if(i<1||i>seq->len+1)
	{
		printf("����Ƿ�");
		
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
	printf("˳���ĵ�ǰ����Ϊ%d:",seq->len);
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
		printf("ɾ������"); 
	}
	else{
		for(int j=i+1;j<=seq->len;j++)
		{
			seq->a[j-1]=seq->a[j];
			
		}
		seq->len--;
		printf("ɾ���ɹ�\n");
	}
}
locate(SEQ* seq,int x)
{
	for(int i=1;i<=seq->len;i++)
	if(seq->a[i]==x)
	{
		return i;
	}
		printf("δ��λ��%d\n",x);
		return -1;	
}
void qianqu(SEQ* seq,int c)
{
	for(int i=1;i<=seq->len;i++)
	{
		if(seq->a[i]==c)
		{
			printf("ǰ��Ϊ%d\n",seq->a[i-1]);
		}
	}

	
}
int prior(SEQ* seq,int x)
{
	int i=locate(seq,x);
	if(i==-1)
	{
		printf("%d����˳�����",x);
	}
	else if(i==1) 
	{
		printf("%d�ǵ�һ��Ԫ�أ�û��ǰ��",x);
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
	printf("��λ%d���±���%d\n",200,locate(p,200));
	printf("%d��ֱ��ǰ����%d",400,prior(p,400));
	
	return 0;
	
}
