#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE  100
typedef int Status;
typedef int KeyType;
// ˳����м�¼������Ԫ�أ�֮���������������ȶ���Ϊint,������ʱ�任�ɱ������ 
typedef int InfoType;
typedef struct{
	KeyType key;//�ؼ����� 
	InfoType otherinfo;//���������� 
}RedType;
typedef struct{
	RedType r[MAXSIZE+1];
	int length;
}SqList;
Status CreateList(SqList &L, int n)
{
	int i;
	printf("��Ϊ��������˳�������%d��������\n",n);
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
	//��˳���L��ֱ�Ӳ������� 
	int i, j;
	for (i=2;i<=L.length; ++i){
		if(L.r[i].key < L.r[i-1].key){  // ��������������������Ҫ��L.r[i]�������������� 
			L.r[0] = L.r[i];  //  ����Ϊ�ڱ� 
			for(j=i-1;L.r[0].key<L.r[j].key;--j) 
			L.r[j+1] = L.r[j];  // ��¼���� 
			L.r[j+1]=L.r[0];  // ���뵽��ȷλ�� 
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
	//��˳���L���۰�������� 
	int i, j, low, high, mid;
	for ( i=2;i<=L.length; ++i ){
		L.r[0] = L.r[i];    // ��L.r[i]�ݴ浽L.r[0]�� 
		low = 1; high = i-1;
		while (low<=high){   // ��r[low..high]���۰������������λ�� 
			mid = (low+high)/2;        // �۰� 
			if (L.r[0].key<L.r[mid].key) high = mid-1;  // ����λ���ڵͰ��� 
			else low = mid+1;                          // ����λ���ڸ߰���
		} // while
		for(j=i-1; j>=high+1; --j) L.r[j+1] = L.r[j];  // ��¼���� 
		L.r[high+1]=L.r[0];  // ���뵽��ȷλ��  
	}
	return OK;
} // BInsertSort

int main()
{
	SqList L;
	int key,flag,n=0,i,e;
	while(1)
	{
		
		printf("******���ҵĻ�������ʵ�֣�******\n");
		printf("1.����˳���\n");
		printf("2.ֱ�Ӳ�������\n");
		printf("3.ð������\n");
		printf("4.�۰�������� \n");
		printf("5.�˳�");
		printf("\n");
		printf("������Ҫ���еĲ�����");
		scanf("%d",&flag);
		switch(flag)
		{
			case 1:
				printf("������Ҫ������˳���ĳ��ȣ�");
				scanf("%d",&n);	
				CreateList(L, n);  // ����CreateList_Sq�������������ǿ�˳�������Ϊn) 
				printf("��������˳�����Ϊ%d,��������:\n", ListLength(L));
				Print(L);
				printf("\n");
				break;
			case 2:
				InsertSort(L);   // ����InsertSort()������˳���L����ֱ�Ӳ�������
				printf("ֱ�Ӳ�������������:\n");
				Print(L);
				break;
			case 3:
			 	bubble_sort(L);
			 	printf("ð������������:\n");
			 	Print(L);
				printf("\n");
				break;
			case 4:
				BInsertSort(L);
				Print(L);
				printf("\n");
				break;
			case 5: 
				printf("\nллʹ��...�ټ���");
				return 0;	
			default:
				printf("û������Ҫ�Ĺ���\n");
		}
		printf("\n˵����������[]������ʾ���Ǽ�¼��ԭʼλ���");	
		printf("\n");
		system("pause");
	}
}
