#include<stdio.h>
int main()
{
	int num[105][105];
	int i,j;
	num[1][1]=1;
	for(i=2;i<105;i++)
	{
		num[i][1]=1;
		for(j=2;j<i;j++)
		{
			num[i][j]=num[i-1][j-1]+num[i-j][j];
		}
		num[i][i]=1;
	}
	while(true)
	{
		int m,n;
		scanf("%d%d",&m,&n);
		printf("%d",num[m][n]);
	 } 
	 return 0;
 } 
