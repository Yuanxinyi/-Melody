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
	int arcs[MAXVEX][MAXVEX];  //�� 
	int visited[MAXVEX];
	char vex[MAXVEX]; //���� 
	int vexnum;
	int arcnum;
}AdjMatrix;
void Create(AdjMatrix *G) 
{
	int i, j, k, vex1, vex2;
	char Vex1, Vex2;
	scanf("%d %d", &G->vexnum, &G->arcnum);
	for (i = 1; i <= G->vexnum; i++) { // �ÿ��ڽӾ��� 
		for (j = 1; j <= G->vexnum; j++) {
			G->arcs[i][j] = 0;
		}
	}
	getchar();
	for (i = 1; i <= G->vexnum; i++) {
		scanf("%c", &G->vex[i]);   //����������� 
	}
	getchar();
	for (k = 0; k < G->arcnum; k++) {
		scanf("%c", &Vex1);
		vex1 = Vex1 - 64; //Vex1���±����� 
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
int FirstAdj(AdjMatrix *G, int Vo) { //���һ���ڽӵ� 
	for (int i = 1; i <= G->vexnum; i++) {
		if (G->arcs[Vo][i] == 1 && G->visited[i] != 1) {
			return i;
		}
	}
	return -1;
}
int NextAdj(AdjMatrix *G, int Vo, int w) {  //����һ���ڽӵ� 
	for (int i = w + 1; i <= G->vexnum; i++) {
		if (G->arcs[Vo][i] == 1 && G->visited[i] != 1) {
			return i;
		}
	}
	return -1;
}
/*
void DFS1(AdjMatrix *G, int Vo) {  //������ȱ��� 
	printf("%c", G->vex[Vo]);
	G->visited[Vo] = 1;
	for (int i = 1; i <= G->vexnum; i++) {
		if (!G->visited[i] && G->arcs[Vo][i] == 1) {
			DFS1(G, i);
		}
	}
}
*/
void DFS(AdjMatrix *G ,int Vo)   //��������������� 
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

void BFS(AdjMatrix *G, int Vo) {  //��������������� 
	printf("%c", G->vex[Vo]);
	G->visited[Vo] = 1;
	SqQueue *Q = (SqQueue *)malloc(sizeof(SqQueue));
	Q->front = 0;
	Q->rear = 0;
	Q->front++;
	Q->vex[Q->front] = Vo;  //��� 
	while (Q->front - Q->rear != 0) //���в�Ϊ�� 
	{
		Vo = Q->vex[Q->front];  //����Vo 
		Q->rear++;  //���� 
		int w = FirstAdj(G, Vo); //��һ���ڽӵ� 
		while (w != -1) 
		{  
			if (!G->visited[w]) {  //����û�б����ʹ� 
				printf("%c", G->vex[w]);
				G->visited[w] = 1;
				Q->front++;
				Q->vex[Q->front] = w;  //��� 
			}
			w = NextAdj(G, Vo, w); //����Vo����һ���ڽӵ� 
		}
	}
}
void degree(AdjMatrix * G)  //����ȣ���ȣ��� 
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
		out[i] = countout; //���� 
		in[i] = countin; //��� 
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

