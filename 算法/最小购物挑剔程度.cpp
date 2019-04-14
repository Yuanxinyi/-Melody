#include<stdio.h>
int main()
{
	int N,K,k,j;
	int i=0;
	scanf("%d %d",&N,&K);
	int A[N];
	for(i<0;i<N;i++)
	{
		scanf("%d",&A[i]);
	 } 
	for(i=0;i<N;i++)
	{
		k=i;
		for(j=i+1;j<N;j++)
		{
			if(A[k]>A[j])
				k=j;
		}
		if(k!=j)
		{
			int temp=A[i];
			A[i]=A[k];
			A[k]=temp; 
		}
	}
	printf("%d\t",A[N-K-1]);
	return 0;
 } 
