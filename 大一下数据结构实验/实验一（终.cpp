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
//��Ԫ��ĳ�ʼ��
Status initTriplet(Triplet &T, ElemType v0, ElemType v1, ElemType v2)
{
	T.e[0] = v0;
	T.e[1] = v1;
	T.e[2] = v2;
	return OK;
}
//������Ԫ��
Status DestroyTriplet(Triplet &T)
{
	return OK;
}
//��e��ȡT�ĵ�i(1~3)��Ԫ�ص�ֵ
Status getElem(Triplet T, int i, ElemType &e)
{
	if (i < 1 || i > 3)
		return ERROR;
	else
		e = T.e[i - 1];
	return OK;
}
//��T�ĵ�iԪ��ֵ��Ϊe
Status putElem(Triplet &T, int i, ElemType e)
{
	if (i < 1 || i > 3)
		return ERROR;
	else
		T.e[i - 1] = e;
	return OK;
}
//���T������Ԫ�ذ��������У��򷵻�1�����򷵻�0
Status isAscending(Triplet T)
{
	return (T.e[0] <= T.e[1]) && (T.e[1] <= T.e[2]);
}
//���T������Ԫ�ذ��������У��򷵻�1�����򷵻�0
Status isDescending(Triplet T)
{
	return (T.e[0] >= T.e[1]) && (T.e[1] >= T.e[2]);
}
//��e����ָ��T�����Ԫ�ص�ֵ
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
//��e����ָ��T����СԪ�ص�ֵ
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
//���Գ���
int main()
{
	Triplet T;
	Status flag = 0;
	int flag1 = 0;
	int i;
	ElemType v0, v1, v2, e;
	while (1)
	{
		printf("�����������͵ı�ʾ��ʵ��\n");
		printf("1.��ʼ����Ԫ��\n");
		printf("2.������Ԫ���i��Ԫ�ص�ֵ\n");
		printf("3.������Ԫ��\n");
		printf("4.�ҳ���Ԫ������ֵ��Сֵ\n");
		printf("5.�û���Ԫ���i��Ԫ�ص�ֵ\n");
		printf("6.��ʾ��Ԫ��\n");
		scanf("%d", &flag);
		switch (flag)
		{
		case 1:
			printf("��������Ԫ�������ֵv0,v1,v2:\n");
			scanf("%f,%f,%f", &v0, &v1, &v2);
			initTriplet(T, v0, v1, v2);
			printf("���ó�ʼ��������flag=%d,T������ֵΪ��%4.2f,%4.2f,%4.2f\n", flag, T.e[0], T.e[1], T.e[2]);
			break;
		case 2:
			printf("������Ԫ�ص�λ��\n");
			scanf("%d", &i);
			flag1 = getElem(T, i, e);
			if (flag1)
			{
				printf("%d λ����Ԫ�ص�ֵΪ %f", i, e);
			}
			else
			{
				printf("iλ�ô���\n");
			}
			break;
		case 3:
			DestroyTriplet(T);
			break;
		case 4:
			if (isAscending(T))
				printf("����Ԫ��Ԫ��Ϊ����\n");
			if (isDescending(T))
				printf("����Ԫ��Ԫ��Ϊ����\n");
			printf("����Ԫ���е����ֵΪ��%4.2f,��СֵΪ��%4.2f\n", getMax(T, e), getMin(T, e));
			break;
		case 5:
			printf("������Ҫ�û�Ԫ�ص�λ��\n");
			scanf("%d", &i);
			printf("�������û����Ԫ�ص�ֵe\n");
			scanf("%f", &e);
			flag1 = putElem(T, i, e);
			if (flag1)
			{
				printf("%d λ����Ԫ�ص�ֵ���û�Ϊ %f", i, e);
			}
			else
			{
				printf("iλ�ô���\n");
			}
			break;
		case 6:
			printf("T������ֵΪ��%4.2f,%4.2f,%4.2f\n", T.e[0], T.e[1], T.e[2]);
			break;
		default:
			printf("û������Ҫ�Ĺ���\n");
		}
		system("pause");
	}
	return OK;
}
