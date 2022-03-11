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
//�������� 
void CreateList_L(LinkList &L,int n)
{
	LinkList p;
	int i;
	L=(LinkList)malloc (sizeof(LNode));         //��̬����洢�ռ� 
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

//���� 
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
//ɾ�� 
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
//���� 
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
//������ 
int main()
{
	LinkList L;
	int n;
	ElemType e;
	Status flag=0,flag1=0,flag2=0;
	int i;
	while(1)
	{
		printf("���Ա�Ļ�������ʵ��\n");
		printf("1.����������\n");
		printf("2.���������Ԫ��\n");
		printf("3.�������ɾ��\n");
		printf("4.������Ĳ���\n");
		printf("5.���������ʾ\n");
		scanf("%d",&flag);
		switch(flag)
		{
			case 1:
				printf("������Ҫ������������ĸ���\n");
				scanf("%d",&n);
				printf("�����뵥���������data:\n");
				CreateList_L(L,n);
				break;
			case 2:
				printf("������Ҫ�������λ��\n");
				scanf("%d",&i);
				printf("������Ҫ����Ľ���ֵe\n");
				scanf("%f",&e);
				flag1=ListInsert_L(L,i,e); 
				if(flag1) 
				{ 
					printf("%d λ�����ѳɹ������� %f",i,e);
				}	
				break;
			case 3:
				printf("������Ҫɾ������λ��\n");
				scanf("%d",&i);
				printf("������Ҫɾ���Ľ���ֵe\n");
				scanf("%f",&e);
				flag1=ListDelete_L(L,i,e);
				if(flag1) 
				{ 
					printf("%d λ�����ѳɹ�ɾ����� %f",i,e);
				}	
				break;
			case 4: 
				printf("������Ҫ���ҽ���λ��\n");
				scanf("%d",&i);
				flag1=GetElem_L(L,i,e);
				if(flag1) 
				{ 
					printf("%d λ���Ͻ���ֵΪ %f",i,e);
				}
				break;
			case 5:
				print_L(L);
				break;
			default:
				printf("û������Ҫ�Ĺ���\n");
		}
		system("pause");
	}
}
