#include<stdio.h>
#include<stdlib.h>
typedef struct bitree{
	char data;
	struct bitree* lchild;
	struct bitree* rchild;
}BT;

BT* createbitree(){
	BT* q[50];
	char ch;
	BT* s;
	BT* root=NULL;
	int i = 0;
	int j;
	printf("����������ڵ��е�ֵ,��ֵ����,�ţ���������#��:");
	scanf(" %c",&ch);
	while(ch!='#')
	{
		i++;
		s = NULL;
		if(ch != ',')
		{
			s = (BT*)malloc(sizeof(BT));
			s->data = ch;
			s->lchild = NULL;
			s->rchild = NULL;	
		}
		q[i] = s;
		if(i == 1)
		{
			root = s;
		}else{
			j = i/2;
			if(i%2==0)
			{
				q[j]->lchild = s;
			}else{
				q[j]->rchild = s;
			}
			
		}
		printf("����������ڵ��е�ֵ,��ֵ����,�ţ���������#��:");
		scanf(" %c",&ch);
	}
		return root;
}
void preorder(BT* root)
{
	BT* p=root;
	if(p!=NULL)
	{
		printf("%c",p->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}
void inorder(BT* root)
{
	BT* p = root;
	if(p!=NULL)
	{
		
		inorder(root->lchild);
		printf("%c",p->data);
		inorder(root->rchild);
	}
}
int main()
{
BT* root = createbitree();
printf("ǰ�����:");
preorder(root);
printf("\n���������");
inorder(root);
return 0;	
 } 
