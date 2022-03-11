#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define MAXSIZE  100
#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a)<(b))
#define LQ(a,b) ((a)<=(b))
typedef int KeyType;
typedef struct{
	KeyType key;
}ElemType;
typedef struct{
	ElemType elem[MAXSIZE+1];
	int length;
}SSTable;
int Search(SSTable ST, KeyType key)//δ�Ľ� 
{ // ��˳���ST��˳�������ؼ��ֵ���key������Ԫ�أ�// ���ҵ����򷵻����ڱ��е�λ�ã����򷵻� 0��
	int i=0;
	for(i=1;i<=ST.length;++i)
	{
  		if(EQ(ST.elem[i].key,key))	
		{
			printf("%d",i);
			return i;
		}
  	}
  	return 0;
}
int Search_Seq(SSTable ST,KeyType key)//�Ľ���
{
	int i;
	ST.elem[0].key = key;
	i=ST.length;
	while(!EQ(ST.elem[i].key,key))
	{
		i--;
	}
	printf("%d",i);
	return i;
}
int Search_Bin(SSTable ST,KeyType key)
{
	int low,high,mid;
	low=1;
	high = ST.length;
	while(low<=high)
	{
		mid = (low + high)/2;
		if(EQ(key,ST.elem[mid].key)) 
			{
				printf("�ҵ��ˣ�%d",mid);
				return mid;
			}
		else if(LT(key,ST.elem[mid].key))
			high = mid - 1;
		else low = mid + 1;
	}
	printf("û�ҵ�!"); 
	return 0;
}
int CreateList(SSTable &ST,int n)
{
	int i;
	printf("��Ϊ��������˳�������%d��������\n",n);
	for(i=1;i<n+1;i++)
	{
		scanf("%d",&ST.elem[i].key);
	}
	ST.length=n;
	return OK;
}
void Ascend(SSTable &ST)
{
	int i,j,k;
	for(i=1;i<ST.length;i++)
	{
		k=i;
		ST.elem[0]=ST.elem[i];//���Ƚϵ�Ԫ�ش���0�ŵ�Ԫ
		for(j=i+1;j<=ST.length;j++)
		{
			if(LT(ST.elem[j].key,ST.elem[0].key))
			{
				k=j;
				ST.elem[0]=ST.elem[j];
			}		
		}
		if(k!=i)//�и�С��ֵ�򽻻�
		{
			ST.elem[k]=ST.elem[i];
			ST.elem[i]=ST.elem[0];
		}
	}
}
int main()
{
	SSTable ST;
	int key,flag,n=0,i;
	while(1)
	{
		system("cls");
		printf("******���ҵĻ�������ʵ�֣�******\n");
		printf("1.������̬���ұ�\n");
		printf("2.��ʾ��̬���ұ�\n");
		printf("3.δ�Ľ���˳�����\n");
		printf("4.�Ľ����˳�����\n");
		printf("5.����̬���ұ��Ϊ�����\n");
		printf("6.���������ж��ֲ���\n");
		printf("7.�˳�");
		printf("\n");
		printf("������Ҫ���еĲ�����");
		scanf("%d",&flag);
		switch(flag)
		{
			case 1:
				printf("������Ҫ������˳���ĳ��ȣ�");
				scanf("%d",&n);	
				CreateList(ST,n);
				printf("\n");
				break;
			case 2:
				for(i=1;i<n+1;i++)
				{
					printf("%d",ST.elem[i].key);
					printf("\n");
				}
				break;
			case 3:
			 	printf("������Ҫ���ҵĹؼ���:"); 
				scanf("%d",&key);
				Search(ST,key);
				printf("\n");
				break;
			case 4:
				printf("������Ҫ���ҵĹؼ���:"); 
				scanf("%d",&key);
				Search_Seq(ST,key);
				printf("\n");
				break;
			case 5: 
				Ascend(ST);
				printf("���򻯳ɹ���"); 
				printf("\n");
				break;
			case 6:
				printf("������Ҫ���ҵĹؼ���"); 
				scanf("%d",&key);
				Search_Bin(ST,key);
				printf("\n");
				break;
			case 7:
				printf("\nллʹ��...�ټ���");
				return 0;
			default:
				printf("û������Ҫ�Ĺ���\n");
		}
		system("pause");
	}
}
