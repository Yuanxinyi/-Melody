#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 20
#define INF 32767
typedef struct
{
	int arcs[MAXVEX][MAXVEX];
	char vex[MAXVEX];
	int vexnum;
	int arcnum;
}AdjMatrix; //图 
typedef struct {
	int start;
	int end;
	int weight;
	int isUsed;
} Brim;  //边 

int LocateVex(AdjMatrix* G, char v)
{
	int i;
	for (i = 0; i < G->vexnum; i++)
	{
		if (G->vex[i] == v)
			return i;
	}
	return 0;
}
void Create(AdjMatrix *G)
{
	int i, j, k;
	char vex1, vex2;
	int weight;
	scanf("%d%d", &G->vexnum, &G->arcnum);
	getchar();
	for (i = 0; i < G->vexnum; i++)
	{
		for (j = 0; j < G->vexnum; j++)
		{
			G->arcs[i][j] = INF;
		}
	}
	for (i = 0; i < G->vexnum; i++)
	{
		scanf("%c", &G->vex[i]); //输入各个顶点 
	}
	getchar();
	for (i = 0; i < G->arcnum; i++)
	{
		scanf("(%c,%c,%d)", &vex1, &vex2, &weight);  //输入边的信息 
		j = LocateVex(G, vex1);
		k = LocateVex(G, vex2);
		G->arcs[j][k] = weight;
		G->arcs[k][j] = weight;
	}
}

int Find(int *parent, int f)
{
	//从下标f开始寻找parent数组中元素为0的下标
	int x;
	for(x = f;parent[x] > 0; x=parent[x]);
	return x;
}
void Kruskal(AdjMatrix *G)
{

	Brim brim[MAXVEX];
	int i, j;
	int k = 0;
	int n, m;
	for (i = 0; i < G->vexnum- 1; i++) {  //生成树最多只有n-1条边 
		for (j = i + 1; j < G->vexnum; j++) {
			if (G->arcs[i][j] != INF) {
				brim[k].start = i;
				brim[k].end = j;
				brim[k].weight = G->arcs[i][j];
				brim[k].isUsed = 0;
				k++;
			}
		}
	}
	for (i = 0; i < k - 1; i++)
	{
		for (j = i + 1; j < k; j++)
		{
			if (brim[i].weight > brim[j].weight)
			{
				Brim tmp = brim[i];
				brim[i] = brim[j];
				brim[j] = tmp;
			}
		}
	}

	int parent[MAXVEX] = { 0 };
	for (int i = 0; i < G->arcnum; i++)
	{
		n = Find(parent, brim[i].start);  //找到根节点 
		m = Find(parent, brim[i].end);    //找到根节点 
		if (n != m)//m=n说明有环
		{
			parent[n] = m;   //将根节点n所在的树作为m的子树  合并 
			brim[i].isUsed = 1;
		}
		printf("(%c,%c,%d,%d)", G->vex[brim[i].start], G->vex[brim[i].end], brim[i].weight, brim[i].isUsed);
	}
	 
}

int main()
{
	AdjMatrix* G = (AdjMatrix*)malloc(sizeof(AdjMatrix));
	Create(G);
	Kruskal(G);
	return 0;
}

