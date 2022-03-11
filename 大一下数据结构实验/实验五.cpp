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
int Search(SSTable ST, KeyType key)//未改进 
{ // 在顺序表ST中顺序查找其关键字等于key的数据元素，// 若找到，则返回它在表中的位置，否则返回 0。
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
int Search_Seq(SSTable ST,KeyType key)//改进后
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
				printf("找到了：%d",mid);
				return mid;
			}
		else if(LT(key,ST.elem[mid].key))
			high = mid - 1;
		else low = mid + 1;
	}
	printf("没找到!"); 
	return 0;
}
int CreateList(SSTable &ST,int n)
{
	int i;
	printf("请为待创建的顺序表输入%d个整数：\n",n);
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
		ST.elem[0]=ST.elem[i];//待比较的元素存入0号单元
		for(j=i+1;j<=ST.length;j++)
		{
			if(LT(ST.elem[j].key,ST.elem[0].key))
			{
				k=j;
				ST.elem[0]=ST.elem[j];
			}		
		}
		if(k!=i)//有更小的值则交换
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
		printf("******查找的基本操作实现：******\n");
		printf("1.创建静态查找表\n");
		printf("2.显示静态查找表\n");
		printf("3.未改进的顺序查找\n");
		printf("4.改进后的顺序查找\n");
		printf("5.将静态查找表改为有序表\n");
		printf("6.对有序表进行二分查找\n");
		printf("7.退出");
		printf("\n");
		printf("请输入要进行的操作：");
		scanf("%d",&flag);
		switch(flag)
		{
			case 1:
				printf("请输入要创建的顺序表的长度：");
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
			 	printf("请输入要查找的关键字:"); 
				scanf("%d",&key);
				Search(ST,key);
				printf("\n");
				break;
			case 4:
				printf("请输入要查找的关键字:"); 
				scanf("%d",&key);
				Search_Seq(ST,key);
				printf("\n");
				break;
			case 5: 
				Ascend(ST);
				printf("有序化成功！"); 
				printf("\n");
				break;
			case 6:
				printf("请输入要查找的关键字"); 
				scanf("%d",&key);
				Search_Bin(ST,key);
				printf("\n");
				break;
			case 7:
				printf("\n谢谢使用...再见！");
				return 0;
			default:
				printf("没有您想要的功能\n");
		}
		system("pause");
	}
}
