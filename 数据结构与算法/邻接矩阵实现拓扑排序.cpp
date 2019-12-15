#include<stdio.h>
#include<stdlib.h>
#define VEX 100
typedef struct
{
	int vexNum;
	int arcNum;
	char vexs[VEX];
	int arcs[VEX][VEX]; 
}Graph;

typedef struct
{
	int vex[VEX];
	int top;
}Stack;

Stack* initStack();
int IsEmpty(Stack* S);
int Push(Stack* S, int vex);
int Pop(Stack* S, int* vex);

void Create(Graph* g, int* inDegree, Stack* S);
void TuoPuSort(Graph* g, Stack* S, int* inDegree);
int main()
{
	Graph g;
	Stack* S = initStack();
	int inDegree[VEX]={0};
	Create(&g,inDegree, S);
	TuoPuSort(&g, S, inDegree);
	free(S);
	return 0;
} 

void TuoPuSort(Graph* g, Stack* S, int* inDegree)
{
	int i, v;
	while(!IsEmpty(S)) {
		Pop(S, &v);
		printf("%c",g->vexs[v]);
		for(i = 1; i <= g->vexNum; i++) {
			if(g->arcs[v][i] == 1) {
				inDegree[i]--;
				if(inDegree[i] == 0) {
					Push(S, i);
				}
			}
		}
	}
}

void Create(Graph* g, int* inDegree, Stack* S)
{
	int i, j, h, t;
	char head, tail;
	scanf("%d%d",&g->vexNum, &g->arcNum);	// 输入顶点个数和弧数
	getchar();
	for(i = 1; i <= g->vexNum; i++)			// 输入顶点
		g->vexs[i] = getchar();
	for(i = 1; i <= g->vexNum;i++) {		// 初始化弧 
		for(j = 1; j <= g->vexNum; j++) {
			g->arcs[i][j] = 0;	
		}
	}
	getchar();
	for(i = 1; i <= g->arcNum; i++)			// 输入弧尾和弧头
	{
		scanf("<%c,%c>",&tail,&head);
		t = tail - 64;
		h = head - 64;
		g->arcs[t][h] = 1;
		inDegree[h]++;
	}
	for(i = 1; i <= g->vexNum; i++) {
		if(inDegree[i] == 0)
			Push(S, i);
	}	
} 

Stack* initStack()
{
	Stack* S = (Stack* )malloc(sizeof(Stack));
	S->top = -1;
	return S;
}

int IsEmpty(Stack* S)
{
	if(S->top == -1)
		return 1;
	return 0;
}

int Push(Stack* S, int vex)
{
	if(S->top < VEX-1) {
		S->vex[++S->top] = vex;
		return 1;
	}
	return 0;
}

int Pop(Stack* S, int* vex)
{
	if(!IsEmpty(S)) {
		*vex = S->vex[S->top--];
		return 1;
	}
	return 0;
}
