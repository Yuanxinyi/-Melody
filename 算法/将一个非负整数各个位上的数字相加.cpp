#include<stdio.h>
int main()
{
	int num,sum,a;
	printf("������һ����:");
	scanf("%d",&num); 
	while(num/10>=1)  //��λ�� 
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
