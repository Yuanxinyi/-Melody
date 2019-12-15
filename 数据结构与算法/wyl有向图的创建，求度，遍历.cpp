#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXVEX 20
typedef struct SqStack {
	int vex[MAXVEX];
	int front;
	int rear;
}SqQueue;
typedef struct
{
	int arcs[MAXVEX][MAXVEX];  //边 
	int visited[MAXVEX];
	char vex[MAXVEX]; //顶点 
	int vexnum;
	int arcnum;
}AdjMatrix;
void Create(AdjMatrix *G) 
{
	int i, j, k, vex1, vex2;
	char Vex1, Vex2;
	scanf("%d %d", &G->vexnum, &G->arcnum);
	for (i = 1; i <= G->vexnum; i++) { // 置空邻接矩阵 
		for (j = 1; j <= G->vexnum; j++) {
			G->arcs[i][j] = 0;
		}
	}
	getchar();
	for (i = 1; i <= G->vexnum; i++) {
		scanf("%c", &G->vex[i]);   //输入各个顶点 
	}
	getchar();
	for (k = 0; k < G->arcnum; k++) {
		scanf("%c", &Vex1);
		vex1 = Vex1 - 64; //Vex1的下标索引 
		scanf("%c", &Vex2);
		vex2 = Vex2 - 64;
		getchar();
		G->arcs[vex1][vex2] = 1;
	}
}
void initialise(AdjMatrix *G) {
	for (int i = 1; i <= G->vexnum; i++) {
		G->visited[i] = 0;
	}
}
int FirstAdj(AdjMatrix *G, int Vo) { //求第一个邻接点 
	for (int i = 1; i <= G->vexnum; i++) {
		if (G->arcs[Vo][i] == 1 && G->visited[i] != 1) {
			return i;
		}
	}
	return -1;
}
int NextAdj(AdjMatrix *G, int Vo, int w) {  //求下一个邻接点 
	for (int i = w + 1; i <= G->vexnum; i++) {
		if (G->arcs[Vo][i] == 1 && G->visited[i] != 1) {
			return i;
		}
	}
	return -1;
}
/*
void DFS1(AdjMatrix *G, int Vo) {  //深度优先遍历 
	printf("%c", G->vex[Vo]);
	G->visited[Vo] = 1;
	for (int i = 1; i <= G->vexnum; i++) {
		if (!G->visited[i] && G->arcs[Vo][i] == 1) {
			DFS1(G, i);
		}
	}
}
*/
void DFS(AdjMatrix *G ,int Vo)   //深度优先搜索遍历 
{
	printf("%c", G->vex[Vo]);
	G->visited[Vo] = 1;
	int w = FirstAdj(G,Vo);
	while(w!=-1)
	{
		if(!G->visited[w])
			DFS(G,w);
		w=NextAdj(G,Vo,w); 
	}
	
 } 

void BFS(AdjMatrix *G, int Vo) {  //广度优先搜索遍历 
	printf("%c", G->vex[Vo]);
	G->visited[Vo] = 1;
	SqQueue *Q = (SqQueue *)malloc(sizeof(SqQueue));
	Q->front = 0;
	Q->rear = 0;
	Q->front++;
	Q->vex[Q->front] = Vo;  //入队 
	while (Q->front - Q->rear != 0) //队列不为空 
	{
		Vo = Q->vex[Q->front];  //保存Vo 
		Q->rear++;  //出队 
		int w = FirstAdj(G, Vo); //第一个邻接点 
		while (w != -1) 
		{  
			if (!G->visited[w]) {  //顶点没有被访问过 
				printf("%c", G->vex[w]);
				G->visited[w] = 1;
				Q->front++;
				Q->vex[Q->front] = w;  //入队 
			}
			w = NextAdj(G, Vo, w); //顶点Vo的下一个邻接点 
		}
	}
}
void degree(AdjMatrix * G)  //求出度，入度，度 
{
	int i, j;
	int in[MAXVEX];
	int out[MAXVEX];
	for (i = 1; i <= G->vexnum; i++) {
		int countout = 0,countin = 0; 
		for (j = 1; j <= G->vexnum; j++) {
			if (G->arcs[i][j] == 1) {
				countout++;
			}
			if (G->arcs[j][i] == 1) {
				countin++;
			}
		}
		out[i] = countout; //出度 
		in[i] = countin; //入度 
	}
	for (i = 1; i <= G->vexnum; i++) {
		printf("%c %d %d %d\n", G->vex[i], out[i], in[i], in[i] + out[i]);
	}
} 
int main(void) 
{
	AdjMatrix *G = (AdjMatrix *)malloc(sizeof(AdjMatrix));
	Create(G);
	degree(G); 
	initialise(G);
	DFS(G,1);
	printf("\n");
	initialise(G);
	BFS(G,1);
	return 0;
}

