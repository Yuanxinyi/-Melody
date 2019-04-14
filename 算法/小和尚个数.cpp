#include<stdio.h>
void hs(int N,int M)    
{
	unsigned long long sum=0;
	while(N<=M)
	{
		sum+=N*(N+1);
		N=N+1;
	 } 
	printf("%u\n",sum); 
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	int A[n][2];    //输入为n行2列 
	for(i=0;i<n;i++)
	{
		for(j=0;j<2;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		hs(A[i][0],A[i][1]);
	}
	return 0;
 } 
