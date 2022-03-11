#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INFINITY 10000
#define MAX_VERTEX_NUM 20
#define	OK	 1
#define TRUE 1
typedef int VRType;
typedef char VertexType;
typedef char InfoType;
typedef enum{DG,DN,UDG,UDN}GraphKind;
typedef struct
{
	VertexType vexs[MAX_VERTEX_NUM];//VertexType vexs[MAX_VERTEX_NUM];//��������
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];// arcstrix arcs;//�ڽӾ���
	int vexnum,arcnum;//ͼ�ĵ�ǰ�������ͻ���
}MGraph;

struct Prim
{
	char adjvex;
	int lowcost;
}closedge[MAX_VERTEX_NUM];

int LocateVex(MGraph G,VertexType v){
	int i;
	for (i=0;i<=G.vexnum;++i)
	{
		if(G.vexs[i]==v) 
		return i;
	}
	return -1;
}

void Print_UDG(MGraph G)//��ʾͼ 
{
	int i,j;
	printf("ͼ�Ķ����ǣ�\n");
	for(i=0;i<G.vexnum;i++)
	{
		printf("%-8c",G.vexs[i]);
	}
	printf("\n");
	printf("ͼ���ڽӾ����ǣ�\n");
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
		printf("%8d",G.arcs[i][j]);
		printf("\n");
	}
}
typedef struct QNode
{
    int data;
    struct QNode *next;
}QNode, *Queue;
typedef struct
{
    Queue Front;
    Queue Rear;
}LinkQueue;

bool visited[MAX_VERTEX_NUM];

void Init_Queue(LinkQueue *Q)
{
    Q->Front = (Queue)malloc(sizeof(QNode));
    if (!Q->Front)
    {
        printf("The memory allocation failed ! Queue initialization falied! \n");
        exit(0);
    }
    Q->Rear = Q->Front;
    Q->Front->next = NULL;
}

void EnQueue(LinkQueue *Q, int value)
{
    Queue qNew = (Queue)malloc(sizeof(QNode));
    if (!qNew)
    {
        printf("The memory allocation failed!Element can not enter queue!\n");
        exit(0);
    }
    qNew->data = value;
    qNew->next = NULL;
    Q->Rear->next = qNew;
    Q->Rear = qNew;
}

void DeQueue(LinkQueue *Q, int *value)
{
    Queue q;
    if (Q->Front == Q->Rear)
    {
        printf("The queue is empty!\n");
        exit(0);
    }

    q = Q->Front->next;
    *value = q->data;
    Q->Front->next = q->next;

    if (Q->Rear == q)
    {
        Q->Rear = Q->Front;
    }
    free(q);
    q = NULL;
}

bool isEmpty(LinkQueue Q)
{
    if (Q.Front == Q.Rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void DFS(MGraph G, int i)
{
    
    printf("%-3c", G.vexs[i]);//�ȴ�ӡ����
    visited[i] = true;//��Ƿ��ʹ�
    for (int j = 0; j < G.vexnum; j++)//��ʼ��ȱ���
    {
        if (!visited[j] && G.arcs[i][j]==1)//Ѱ��δ���ʹ����ڽӶ���
        {
            DFS(G,j);
        }
    }
}
void DFSTraverse(MGraph G)
{
    for (int i=0;i<G.vexnum; i++)//������ȫ�����Ϊδ����
    {
        visited[i]=false;
    }
    for (int i=0; i <G.vexnum; i++)
    {
        if (!visited[i])       //������ͨͼ��˵һ��Ϳ���
        {
            DFS(G, i);
        }
    }
}
void BFSTraverse(MGraph G)
{
    int i, j;
    LinkQueue Q;
    for (i = 0; i < G.vexnum; i++)//��ʼ����Ƕ���
    {
        visited[i] = false;
    }
    Init_Queue(&Q);
    for (i = 0; i <G.vexnum; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            printf("%-3c",G.vexs[i]);
            EnQueue(&Q,i);
            while(!isEmpty(Q))
            {
                DeQueue(&Q, &i);  //���ö���δ���ʹ���ȡ����i
                for (j = 0; j < G.vexnum; j++)
                {
                    //�ҳ�����i������δ���ʹ����ڽӵ�
                    if (!visited[j] && G.arcs[i][j] == 1)
                    {
                        visited[j] = true;
                        printf("%-3c", G.vexs[j]);
                        EnQueue(&Q, j);
                    }
                }
            }
        }
    }
	printf("\n");
}
void Create_UDG(MGraph &G)//����ͼ 
{
	int i,j,k;
	int cost;
	VertexType v1,v2;
	printf("���붥�����ͱ�����\n");
	scanf("%d,%d",&G.vexnum,&G.arcnum);
	getchar();
	printf("�����붥����Ϣ��\n");
	for(i=0;i<G.vexnum;i++)//���춥������
	{	
		scanf("%c",&G.vexs[i]); 
		getchar();
	}
	for(i=0;i<G.vexnum;i++)
		for(j=0;j<G.vexnum;j++)
			G.arcs[i][j]=INFINITY;//�ڽӾ����ʼ��	 
	for(k=0;k<G.arcnum;k++)//����arcnum���ߣ������ڽӾ��� 
	{
		printf("�����%d���������Ķ����Լ�Ȩֵ��\n",k+1);
		scanf("%c,%c,%d",&v1,&v2,&cost);//����һ���������Ķ��� 
		getchar(); 
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);//ȷ��v1,v2��G�е�λ�� 
		if(i==-1||j==-1) 
		return;
		G.arcs[i][j]=cost;
		G.arcs[j][i]=G.arcs[i][j];//����ͼ����Գ�
	}
	return;
}
int minimum(struct Prim closedge[],MGraph G)
{
	int i,min,lowcost=INFINITY;
	for(i=0;i<G.vexnum;i++)
	if(closedge[i].lowcost!=0&&closedge[i].lowcost<lowcost)
	{
		min=i;
		lowcost=closedge[i].lowcost;
	}
	return min;
}
void MiniSpanTree(MGraph G,char u)
{
	int i,k,j;
	k=LocateVex(G,u);
	for(j=0;j<G.vexnum;++j)
	{
		closedge[j].adjvex=u;
		if(j!=k)
		{
			closedge[j].lowcost=G.arcs[k][j];
		}
		else
			closedge[j].lowcost=0;
	}
	printf("��С�����������±���ɣ�\n");
	for(i=1;i<G.vexnum;++i)
	{
		k=minimum(closedge,G);//�����������������һ�����㣨k�� 
		printf("%c,%c,%d\n",G.vexs[k],closedge[k].adjvex,closedge[k].lowcost);//����������ϵ�һ���� 
		closedge[k].lowcost=0;//����k������0����ʾ����U��
		for(j=0;j<G.vexnum;++j)//ѭ�����¶��㲢��U���Ա�����ѡ����С��
		if(G.arcs[k][j]<closedge[j].lowcost)
		{
			closedge[j].lowcost=G.arcs[k][j];
			closedge[j].adjvex=G.vexs[k];
		} 
	}
	  
}
int main()
{
	MGraph G;
	int i,n;
	char start,v;
	int flag;
	while(1)
	{
		printf("******ͼ�Ļ�������ʵ�֣�******\n");
		printf("1.�����ڽӾ��󴴽�ͼ\n");
		printf("2.��ʾͼ�Լ�ͼ���ڽӾ���\n");
		printf("3.�������������������ͼ\n");
		printf("4.�������������������ͼ\n");
		printf("5.����ͼ����С����������\n");
		printf("\n");
		printf("������Ҫ���еĲ�����");
		scanf("%d",&flag);
		switch(flag)
		{
			case 1:
				Create_UDG(G);
				break;
			case 2:
				Print_UDG(G);
				break;
			case 3:
				DFSTraverse(G);
				printf("\n");
				break;
			case 4: 
				BFSTraverse(G);
				break;
			case 5:
				printf("����������һ�����㣬��ʼ������С��������\n");
				getchar();
				scanf("%c",&start);
				getchar();
				MiniSpanTree(G,start);
				printf("\n");
				break;
			default:
				printf("û������Ҫ�Ĺ���\n");
		}
		system("pause");
	}
}
