#include<stdio.h>
#include<stdlib.h> 
//˳�򴮺������㣺���롢��λ��ɾ��
typedef struct sequencestring{
	char ch[50];
	int len ;
}STR; 
//�������ַ���s���±�Ϊi�ĵط�����t 
void insert(STR* s,STR* t,int i) {
if(s->len+t->len>50){
	
	printf("������������ʧ��");
}else if(i<0||i>s->len){
	printf("����λ�÷Ƿ�������ʧ��");
}else{
	//����t�ĳ��ȸ�λ�� 
	for(int j=s->len-1;j>=i;j--){
		s->ch[j+t->len]=s->ch[j];
	}
	//��ֵ 
	for(int j=0;j<t->len;j++)
	{
		s->ch[i+j]=t->ch[j];
	}
	//�޸ĳ��� 
	s->len =s->len+t->len;
}
} 
void myprint(STR* s){
	int i=0;
	printf("�ַ����ĵ�ǰ����Ϊ%d ",s->len);
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
		printf("ɾ��λ�÷Ƿ�ɾ��ʧ��");
	}else{
		//�������������ƶ�Ԫ�� 
		if(i+j>=s->len)
		{
			s->len = i; 
		}else{
			for(int k=i+j;k<s->len;k++)
			{
				s->ch[k-j]=s->ch[k];
			}
			//�޸ĳ���
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
//�ַ���t���ַ���s�е�λ�� 
int index(STR*s,STR*t){
	//�����Ƚ� 
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
	printf("s2���±�Ϊ%d",index(&s1,&s2));
	return 0;
}	 
