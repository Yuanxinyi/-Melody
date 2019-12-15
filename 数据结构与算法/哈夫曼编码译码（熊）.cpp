#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LENG 500
#define N 6
#define M 2*N-1

typedef struct
{
	int Weight;
	int Lchild, Rchild, Parent;
}HFNode, *PHFTree;

typedef char * HFCode[N+1];
void CreateHuffmanTree(PHFTree hftree);
void HuffCode(PHFTree hftree, HFCode hfcode);
void select(PHFTree hftree, int i, int * s1, int * s2);
void PrintCode(PHFTree hftree, HFCode hfcode);
void TransCode(HFCode hfcode, char * inputChar);
void TransChar(PHFTree hftree, HFCode hfcode, char * inputCode);
void Destory(HFCode hfcode);

int main()
{
	char inputChar[LENG]; 
	char inputCode[LENG];
	HFNode hftree[M+1]={0};
	HFCode hfcode;
	
	CreateHuffmanTree(hftree);
	HuffCode(hftree, hfcode);
	scanf("%s",inputChar);
	scanf("%s",inputCode);
	PrintCode(hftree, hfcode);
	TransCode(hfcode, inputChar);
	TransChar(hftree, hfcode, inputCode);
	Destory(hfcode);
	return 0;
} 

void CreateHuffmanTree(PHFTree hftree)  //������������ 
{
	int i, s1, s2;
	
	for(i = 1; i <= N; i++)
		scanf("%d",&hftree[i].Weight);

	for(i = N+1; i <= M; i++)
	{
		
		select(hftree, i-1,&s1, &s2);
		hftree[i].Weight = hftree[s1].Weight + hftree[s2].Weight;
		hftree[i].Lchild = s1;
		hftree[i].Rchild = s2;
		hftree[s1].Parent = hftree[s2].Parent = i;
	}
}

void select(PHFTree hftree, int i, int * s1, int * s2)
{
	int j, t, flag;
	*s1 = *s2 = 0; //Ĭ��Ϊ0 
	for(j = 1; j <= i; j++)
	{  //���ҵ�����˫��ָ��Ϊ0��С�Ľ�㣬���λ�ã������κͺ����˫�׽��Ϊ0�Ľ��Ƚ� 
		if(hftree[j].Parent == 0)
		{
			if(*s1 == 0)
			{
				*s1 = j;
			}
			else if(*s2 == 0)
			{
				*s2 = j;
				flag = j;
				break;
			}
		}
	}
	if(hftree[*s1].Weight > hftree[*s2].Weight)
	{
		t = *s1;
		*s1 = *s2;
		*s2 = t;
	} 
	for(j = flag; j <= i; j++)
	{	
		if(hftree[j].Parent == 0 && hftree[j].Weight < hftree[*s1].Weight )
		{
			*s2 = *s1;
			*s1 = j;
		}
		else if(hftree[j].Parent == 0 && hftree[j].Weight < hftree[*s2].Weight )
		{
			*s2 = j; 
		}
	}
}

void HuffCode(PHFTree hftree, HFCode hfcode)  //���ɱ��룬��Ҷ����� 
{
	int i, start, c, p;
	char * temp = (char *)malloc(N * sizeof(char));
	temp[N-1]='\0';
	for(i = 1; i <= N; i++)
	{
		start = N-1;
		c = i;
		p = hftree[c].Parent;
		while(p != 0) //���Ǹ��ڵ� 
		{
			if(hftree[p].Lchild == c)   //�����˫�׵����� 
			{
				temp[--start] = '0';
			}
			else
			{
				temp[--start] = '1';
			}
			c = p;
			p = hftree[p].Parent;
		}
		hfcode[i] = (char *)malloc((N-start) * sizeof(char));
		strcpy(hfcode[i], &temp[start]);
	}
	free(temp);
}

void PrintCode(PHFTree hftree, HFCode hfcode) //��ӡ���� A:XXX; 
{
	int i;
	char x = 'A';
	for(i = 1; i <= N; i++)
		printf("%c:%s\n",x+i-1, hfcode[i]);
}

void TransCode(HFCode hfcode, char * inputChar) //���� AB...->0��1��ʽ 
{
	int i, index;
	for(i = 0; i < strlen(inputChar); i++) 
	{
		index = inputChar[i] - 'A' + 1;
		printf("%s",hfcode[index]);
	}
	printf("\n");
}

void TransChar(PHFTree hftree, HFCode hfcode, char * inputCode) //����0��1->AB...,�Ӹ��ڵ���Ҷ���� 
{
	int i = 0, j, p = M, start;
	char * temp = (char *)malloc(N * sizeof(char));
	while(inputCode[i] != '\0')
	{
		p = M; //���ڵ��±� 
		start = 0; 
		while(1)
		{
			if(hftree[p].Lchild != 0) //����Ҷ�ӽڵ� 
			{
				if(inputCode[i] == '0')
				{
					p = hftree[p].Lchild;
					temp[start++] = '0';
				}
				else
				{
					p = hftree[p].Rchild;
					temp[start++] = '1'; 	
				}
			}
			else
			{
				break;
			}
			i++;
		}
		temp[start] = '\0'; 
		for(j = 1; j <= N; j++)
		{
			if(strcmp(hfcode[j], temp) == 0)
			{
				printf("%c",'A'+j-1);
				break;
			}
		}
	}
	free(temp);
}

void Destory(HFCode hfcode)  //�ͷ� 
{
	int i;
	for(i = 1; i <= N; i++)
		free(hfcode[i]);
}

