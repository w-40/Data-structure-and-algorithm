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
    int tag[100];   /*为栈中每个元素设置的标记，用于后序遍历*/
    int top;        /*栈顶*/
}SeqStack;
 
//前序遍历构造二叉树 
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

//前序遍历二叉树的递归算法 
void PreOrderTraverse(BiTree T)
{
	if(T==NULL)
	return;
	printf("%c",T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

//中序遍历二叉树的递归算法
void InOrderTraverse(BiTree T)
{
	if(T==NULL)
	return;
	InOrderTraverse(T->lchild);
	printf("%c",T->data);
	InOrderTraverse(T->rchild);
}

//后序遍历二叉树的递归算法
void PostOrderTraverse(BiTree T)
{
	if(T==NULL)
	return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c",T->data);
}

//中序遍历二叉树的非递归算法 
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

//求树的高度(递归)
Status high(BiTree T)
{
	int lchild,rchild;
	if(T==NULL)
		return 0;
	lchild=high(T->lchild);
	rchild=high(T->rchild);
	return (lchild>rchild)?(lchild+1):(rchild+1);
}

//求二叉树的结点数 
Status NodeCountOfBiTree(BiTree T)
{
	if(T==NULL)
		return 0;
	else
		return 1+NodeCountOfBiTree(T->lchild)+NodeCountOfBiTree(T->rchild);
		//二叉树的结点数=叶子结点数+根结点数
}

int main()
{
	BiTree T=NULL;
	int a,b;
//	BiTree T;
	printf("请按前序遍历的顺序输入二叉树结点的值，空子树用空格代替:");
	CreateBiTree(T); 
	printf("\n\n递归前序遍历序列为:");
	PreOrderTraverse(T);
	
	printf("\n\n递归中序遍历序列为:");
	InOrderTraverse(T);
	
	printf("\n\n递归后序遍历序列为:");
	PostOrderTraverse(T);
	
	printf("\n\n非递归中序遍历序列为:");
	InOrderTraverse1(T);
	
	a=high(T);
	b=NodeCountOfBiTree(T);
	
	printf("\n\n该二叉树的高为:%d",a);
	printf("\n\n该二叉树的结点数为%d",b); 
	printf("\n\n");
	
	system("pause");								
} 
