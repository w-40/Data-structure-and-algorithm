#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define OK 1
#define ERROR 0
typedef int Status;
typedef float ElemType;
typedef struct
{
	ElemType e[3];
} Triplet;
//三元组的初始化
Status initTriplet(Triplet &T, ElemType v0, ElemType v1, ElemType v2)
{
	T.e[0] = v0;
	T.e[1] = v1;
	T.e[2] = v2;
	return OK;
}
//销毁三元组
Status DestroyTriplet(Triplet &T)
{
	return OK;
}
//用e获取T的第i(1~3)个元素的值
Status getElem(Triplet T, int i, ElemType &e)
{
	if (i < 1 || i > 3)
		return ERROR;
	else
		e = T.e[i - 1];
	return OK;
}
//将T的第i元的值置为e
Status putElem(Triplet &T, int i, ElemType e)
{
	if (i < 1 || i > 3)
		return ERROR;
	else
		T.e[i - 1] = e;
	return OK;
}
//如果T的三个元素按升序排列，则返回1，否则返回0
Status isAscending(Triplet T)
{
	return (T.e[0] <= T.e[1]) && (T.e[1] <= T.e[2]);
}
//如果T的三个元素按降序排列，则返回1，否则返回0
Status isDescending(Triplet T)
{
	return (T.e[0] >= T.e[1]) && (T.e[1] >= T.e[2]);
}
//用e返回指向T的最大元素的值
ElemType getMax(Triplet T, ElemType &e)
{
	if (T.e[0] > T.e[1])
		e = T.e[0];
	else
		e = T.e[1];
	if (T.e[2] > e)
		e = T.e[2];
	return e;
}
//用e返回指向T的最小元素的值
ElemType getMin(Triplet T, ElemType &e)
{
	if (T.e[0] < T.e[1])
		e = T.e[0];
	else
		e = T.e[1];
	if (T.e[2] < e)
		e = T.e[2];
	return e;
}
//测试程序
int main()
{
	Triplet T;
	Status flag = 0;
	int flag1 = 0;
	int i;
	ElemType v0, v1, v2, e;
	while (1)
	{
		printf("抽象数据类型的表示和实现\n");
		printf("1.初始化三元组\n");
		printf("2.返回三元组第i个元素的值\n");
		printf("3.销毁三元组\n");
		printf("4.找出三元组的最大值最小值\n");
		printf("5.置换三元组第i个元素的值\n");
		printf("6.显示三元组\n");
		scanf("%d", &flag);
		switch (flag)
		{
		case 1:
			printf("请输入三元组的三个值v0,v1,v2:\n");
			scanf("%f,%f,%f", &v0, &v1, &v2);
			initTriplet(T, v0, v1, v2);
			printf("调用初始化函数后，flag=%d,T的三个值为：%4.2f,%4.2f,%4.2f\n", flag, T.e[0], T.e[1], T.e[2]);
			break;
		case 2:
			printf("请输入元素的位置\n");
			scanf("%d", &i);
			flag1 = getElem(T, i, e);
			if (flag1)
			{
				printf("%d 位置上元素的值为 %f", i, e);
			}
			else
			{
				printf("i位置错误\n");
			}
			break;
		case 3:
			DestroyTriplet(T);
			break;
		case 4:
			if (isAscending(T))
				printf("该三元组元素为升序\n");
			if (isDescending(T))
				printf("该三元组元素为降序\n");
			printf("该三元组中的最大值为：%4.2f,最小值为：%4.2f\n", getMax(T, e), getMin(T, e));
			break;
		case 5:
			printf("请输入要置换元素的位置\n");
			scanf("%d", &i);
			printf("请输入置换后的元素的值e\n");
			scanf("%f", &e);
			flag1 = putElem(T, i, e);
			if (flag1)
			{
				printf("%d 位置上元素的值已置换为 %f", i, e);
			}
			else
			{
				printf("i位置错误\n");
			}
			break;
		case 6:
			printf("T的三个值为：%4.2f,%4.2f,%4.2f\n", T.e[0], T.e[1], T.e[2]);
			break;
		default:
			printf("没有您想要的功能\n");
		}
		system("pause");
	}
	return OK;
}
