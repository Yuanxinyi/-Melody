#include<stdio.h>
int main()
{
	int num,sum,a;
	printf("请输入一个数:");
	scanf("%d",&num); 
	while(num/10>=1)  //三位数 
	{
		a=num%10;
		num/=10;
		if(num<10)
			sum+=num;11
		sum+=a;
		if(sum>=10)
		{
			num=sum;
			sum=0;
		}
	}
	printf("%d",sum);
	return 0;
 } 
