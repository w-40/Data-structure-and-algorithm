#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE  100
typedef int Status;
typedef int KeyType;
// 顺序表中记录（数据元素）之其它数据项类型先定义为int,可以随时变换成别的类型 
typedef int InfoType;
typedef struct{
	KeyType key;//关键字项 
	InfoType otherinfo;//其他数据项 
}RedType;
typedef struct{
	RedType r[MAXSIZE+1];
	int length;
}SqList;
Status CreateList(SqList &L, int n)
{
	int i;
	printf("请为待创建的顺序表输入%d个整数：\n",n);
	for(i=1;i<n+1;i++)
	{
		scanf("%d",&L.r[i].key);
		L.r[i].otherinfo=i;
	}
	L.length=n;
	return OK;
}
Status ListLength(SqList L)
{
	return L.length;
}
Status Print(SqList L)
{
	int i;
	for(i=1;i<=L.length;++i)
	{
		printf("%d[%d]  ", L.r[i].key, L.r[i].otherinfo);
	}
	return OK;
}
Status InsertSort(SqList &L)
{
	//对顺序表L作直接插入排序 
	int i, j;
	for (i=2;i<=L.length; ++i){
		if(L.r[i].key < L.r[i-1].key){  // 如果满足给定条件，则需要将L.r[i]插入有序序列中 
			L.r[0] = L.r[i];  //  复制为哨兵 
			for(j=i-1;L.r[0].key<L.r[j].key;--j) 
			L.r[j+1] = L.r[j];  // 记录后移 
			L.r[j+1]=L.r[0];  // 插入到正确位置 
		} 
	}
	return OK;
} // InsertSort
Status bubble_sort(SqList &L)
{
	int i,j,t;
	for(i=0;i<L.length+1;i++)
	{
		for(j=i;j<L.length;j++)
		{
			if(L.r[j].key>L.r[j+1].key)
			{
				
				L.r[0]=L.r[j];
				L.r[j]=L.r[j+1];
				L.r[j+1]=L.r[0];
			}
		}
	}
}
Status BInsertSort(SqList &L)
{
	//对顺序表L作折半插入排序 
	int i, j, low, high, mid;
	for ( i=2;i<=L.length; ++i ){
		L.r[0] = L.r[i];    // 将L.r[i]暂存到L.r[0]中 
		low = 1; high = i-1;
		while (low<=high){   // 在r[low..high]中折半查找有序插入的位置 
			mid = (low+high)/2;        // 折半 
			if (L.r[0].key<L.r[mid].key) high = mid-1;  // 插入位置在低半区 
			else low = mid+1;                          // 插入位置在高半区
		} // while
		for(j=i-1; j>=high+1; --j) L.r[j+1] = L.r[j];  // 记录后移 
		L.r[high+1]=L.r[0];  // 插入到正确位置  
	}
	return OK;
} // BInsertSort

int main()
{
	SqList L;
	int key,flag,n=0,i,e;
	while(1)
	{
		
		printf("******查找的基本操作实现：******\n");
		printf("1.创建顺序表\n");
		printf("2.直接插入排序\n");
		printf("3.冒泡排序\n");
		printf("4.折半插入排序 \n");
		printf("5.退出");
		printf("\n");
		printf("请输入要进行的操作：");
		scanf("%d",&flag);
		switch(flag)
		{
			case 1:
				printf("请输入要创建的顺序表的长度：");
				scanf("%d",&n);	
				CreateList(L, n);  // 调用CreateList_Sq（）函数创建非空顺序表（长度为n) 
				printf("您创建的顺序表长度为%d,内容如下:\n", ListLength(L));
				Print(L);
				printf("\n");
				break;
			case 2:
				InsertSort(L);   // 调用InsertSort()函数对顺序表L进行直接插入排序
				printf("直接插入排序结果如下:\n");
				Print(L);
				break;
			case 3:
			 	bubble_sort(L);
			 	printf("冒泡排序结果如下:\n");
			 	Print(L);
				printf("\n");
				break;
			case 4:
				BInsertSort(L);
				Print(L);
				printf("\n");
				break;
			case 5: 
				printf("\n谢谢使用...再见！");
				return 0;	
			default:
				printf("没有您想要的功能\n");
		}
		printf("\n说明：方括号[]里面显示的是记录的原始位序号");	
		printf("\n");
		system("pause");
	}
}
