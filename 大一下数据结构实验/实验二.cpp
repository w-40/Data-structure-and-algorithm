#include<stdio.h>
#include<stdlib.h>
#define TRUE   1
#define FALSE  0
#define OK     1
#define ERROR  0
typedef int Status;
typedef float ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next; 
}LNode, *LinkList;
//创建链表 
void CreateList_L(LinkList &L,int n)
{
	LinkList p;
	int i;
	L=(LinkList)malloc (sizeof(LNode));         //动态分配存储空间 
	L->next=NULL; 
	for(i=n;i>0;--i)
	{
		p=L->next;
		p=(LinkList)malloc(sizeof(LNode));
		scanf("%f",&p->data);
		p->next=L->next;
		L->next=p;
	}
	p=NULL;
}

//插入 
Status ListInsert_L(LinkList &L,int i,ElemType e)
{
	LNode *p,*s;
	int j;
	p=L;
	j=0;
	while(p&&j<i-1)
	{
		p=p->next;
		++j;
	}
	if(!p||j>i-1) 
	return ERROR;
	s=(LinkList)malloc (sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}
//删除 
Status ListDelete_L(LinkList &L,int i,ElemType &e)
{
	LNode *p,*q;
	int j;
	p=L;
	j=0;
	while(p->next&&j<i-1)
	{
		p=p->next;
		++j;
	}
	if(!(p->next)||j>i-1) 
	return ERROR;
	q=p->next;
	p->next=q->next;
	e=q->data;
	free(q);
	return OK; 
}
//查找 
Status GetElem_L(LinkList &L,int i,ElemType &e)
{
	LNode *p;
	int j;
	p=L->next;
	j=1;
	while(p&&j<i)
	{
		p=p->next;
		++j;
	}
	if(!p||j>i) return ERROR;
	e=p->data;
	return OK;
}
void print_L(LinkList L)
{
		
	LNode *p;
	p=L->next;
	if(L!=NULL)
	{
		while(p!=NULL)
		{
			printf("[data: %lf]\n",p->data);
			p=p->next;
		}
	}
}
//主函数 
int main()
{
	LinkList L;
	int n;
	ElemType e;
	Status flag=0,flag1=0,flag2=0;
	int i;
	while(1)
	{
		printf("线性表的基本操作实现\n");
		printf("1.创建单链表\n");
		printf("2.单链表插入元素\n");
		printf("3.单链表的删除\n");
		printf("4.单链表的查找\n");
		printf("5.单链表的显示\n");
		scanf("%d",&flag);
		switch(flag)
		{
			case 1:
				printf("请输入要创建单链表结点的个数\n");
				scanf("%d",&n);
				printf("请输入单链表的数据data:\n");
				CreateList_L(L,n);
				break;
			case 2:
				printf("请输入要插入结点的位置\n");
				scanf("%d",&i);
				printf("请输入要插入的结点的值e\n");
				scanf("%f",&e);
				flag1=ListInsert_L(L,i,e); 
				if(flag1) 
				{ 
					printf("%d 位置上已成功插入结点 %f",i,e);
				}	
				break;
			case 3:
				printf("请输入要删除结点的位置\n");
				scanf("%d",&i);
				printf("请输入要删除的结点的值e\n");
				scanf("%f",&e);
				flag1=ListDelete_L(L,i,e);
				if(flag1) 
				{ 
					printf("%d 位置上已成功删除结点 %f",i,e);
				}	
				break;
			case 4: 
				printf("请输入要查找结点的位置\n");
				scanf("%d",&i);
				flag1=GetElem_L(L,i,e);
				if(flag1) 
				{ 
					printf("%d 位置上结点的值为 %f",i,e);
				}
				break;
			case 5:
				print_L(L);
				break;
			default:
				printf("没有您想要的功能\n");
		}
		system("pause");
	}
}
