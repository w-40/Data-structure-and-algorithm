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
	VertexType vexs[MAX_VERTEX_NUM];//VertexType vexs[MAX_VERTEX_NUM];//顶点向量
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];// arcstrix arcs;//邻接矩阵
	int vexnum,arcnum;//图的当前顶点数和弧数
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

void Print_UDG(MGraph G)//显示图 
{
	int i,j;
	printf("图的顶点是：\n");
	for(i=0;i<G.vexnum;i++)
	{
		printf("%-8c",G.vexs[i]);
	}
	printf("\n");
	printf("图的邻接矩阵是：\n");
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
    
    printf("%-3c", G.vexs[i]);//先打印顶点
    visited[i] = true;//标记访问过
    for (int j = 0; j < G.vexnum; j++)//开始深度遍历
    {
        if (!visited[j] && G.arcs[i][j]==1)//寻找未访问过的邻接顶点
        {
            DFS(G,j);
        }
    }
}
void DFSTraverse(MGraph G)
{
    for (int i=0;i<G.vexnum; i++)//将顶点全部标记为未访问
    {
        visited[i]=false;
    }
    for (int i=0; i <G.vexnum; i++)
    {
        if (!visited[i])       //对于连通图来说一遍就可以
        {
            DFS(G, i);
        }
    }
}
void BFSTraverse(MGraph G)
{
    int i, j;
    LinkQueue Q;
    for (i = 0; i < G.vexnum; i++)//初始化标记顶点
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
                DeQueue(&Q, &i);  //若该顶点未访问过，取出给i
                for (j = 0; j < G.vexnum; j++)
                {
                    //找出顶点i的所有未访问过的邻接点
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
void Create_UDG(MGraph &G)//无向图 
{
	int i,j,k;
	int cost;
	VertexType v1,v2;
	printf("输入顶点数和边数：\n");
	scanf("%d,%d",&G.vexnum,&G.arcnum);
	getchar();
	printf("请输入顶点信息：\n");
	for(i=0;i<G.vexnum;i++)//构造顶点向量
	{	
		scanf("%c",&G.vexs[i]); 
		getchar();
	}
	for(i=0;i<G.vexnum;i++)
		for(j=0;j<G.vexnum;j++)
			G.arcs[i][j]=INFINITY;//邻接矩阵初始化	 
	for(k=0;k<G.arcnum;k++)//输入arcnum条边，建立邻接矩阵 
	{
		printf("请入第%d条边依附的顶点以及权值：\n",k+1);
		scanf("%c,%c,%d",&v1,&v2,&cost);//输入一条边依附的顶点 
		getchar(); 
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);//确定v1,v2在G中的位置 
		if(i==-1||j==-1) 
		return;
		G.arcs[i][j]=cost;
		G.arcs[j][i]=G.arcs[i][j];//无向图矩阵对称
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
	printf("最小生成树是以下边组成：\n");
	for(i=1;i<G.vexnum;++i)
	{
		k=minimum(closedge,G);//求出加入生成树的下一个顶点（k） 
		printf("%c,%c,%d\n",G.vexs[k],closedge[k].adjvex,closedge[k].lowcost);//输出生成树上的一条边 
		closedge[k].lowcost=0;//将第k顶点置0，表示加入U集
		for(j=0;j<G.vexnum;++j)//循环将新顶点并入U集以便重新选择最小边
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
		printf("******图的基本操作实现：******\n");
		printf("1.利用邻接矩阵创建图\n");
		printf("2.显示图以及图的邻接矩阵\n");
		printf("3.深度优先搜索（遍历）图\n");
		printf("4.广度优先搜索（遍历）图\n");
		printf("5.计算图的最小代价生成树\n");
		printf("\n");
		printf("请输入要进行的操作：");
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
				printf("请输入任意一个顶点，开始生成最小生成树：\n");
				getchar();
				scanf("%c",&start);
				getchar();
				MiniSpanTree(G,start);
				printf("\n");
				break;
			default:
				printf("没有您想要的功能\n");
		}
		system("pause");
	}
}
