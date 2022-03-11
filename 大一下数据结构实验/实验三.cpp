#include<stdio.h>
#include<stdlib.h>
#define OK     1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW   -2
typedef int Status;
typedef char TElemType;

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef struct Stack
{
    BiTree data[100];
    int tag[100];   /*Ϊջ��ÿ��Ԫ�����õı�ǣ����ں������*/
    int top;        /*ջ��*/
}SeqStack;
 
//ǰ�������������� 
Status CreateBiTree(BiTree &T)
{
	char ch;
	ch=getchar();
	if(ch==' ') T=NULL;
	else
	{
		if(!(T=(BiTNode *)malloc(sizeof(BiTNode))))
		exit(OVERFLOW);
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}

//ǰ������������ĵݹ��㷨 
void PreOrderTraverse(BiTree T)
{
	if(T==NULL)
	return;
	printf("%c",T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

//��������������ĵݹ��㷨
void InOrderTraverse(BiTree T)
{
	if(T==NULL)
	return;
	InOrderTraverse(T->lchild);
	printf("%c",T->data);
	InOrderTraverse(T->rchild);
}

//��������������ĵݹ��㷨
void PostOrderTraverse(BiTree T)
{
	if(T==NULL)
	return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c",T->data);
}

//��������������ķǵݹ��㷨 
Status InOrderTraverse1(BiTree T)
{
    SeqStack s;
    s.top=-1;
    while((T)||(s.top!=-1))
    	{
			while(T)
        	{
            	s.top++;
            	s.data[s.top]=T;
            	T=T->lchild;
        	}
        	if(s.top>-1)
        	{
            	T=s.data[s.top];
            	s.top--;
	     		printf("%c",T->data);
            	T=T->rchild;
           }
        }
}

//�����ĸ߶�(�ݹ�)
Status high(BiTree T)
{
	int lchild,rchild;
	if(T==NULL)
		return 0;
	lchild=high(T->lchild);
	rchild=high(T->rchild);
	return (lchild>rchild)?(lchild+1):(rchild+1);
}

//��������Ľ���� 
Status NodeCountOfBiTree(BiTree T)
{
	if(T==NULL)
		return 0;
	else
		return 1+NodeCountOfBiTree(T->lchild)+NodeCountOfBiTree(T->rchild);
		//�������Ľ����=Ҷ�ӽ����+�������
}

int main()
{
	BiTree T=NULL;
	int a,b;
//	BiTree T;
	printf("�밴ǰ�������˳���������������ֵ���������ÿո����:");
	CreateBiTree(T); 
	printf("\n\n�ݹ�ǰ���������Ϊ:");
	PreOrderTraverse(T);
	
	printf("\n\n�ݹ������������Ϊ:");
	InOrderTraverse(T);
	
	printf("\n\n�ݹ�����������Ϊ:");
	PostOrderTraverse(T);
	
	printf("\n\n�ǵݹ������������Ϊ:");
	InOrderTraverse1(T);
	
	a=high(T);
	b=NodeCountOfBiTree(T);
	
	printf("\n\n�ö������ĸ�Ϊ:%d",a);
	printf("\n\n�ö������Ľ����Ϊ%d",b); 
	printf("\n\n");
	
	system("pause");								
} 
