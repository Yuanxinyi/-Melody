//������ 
#include <stdio.h>
//�ж�һ���ж����죬����366�죬ƽ��365�� 
int year(int y)
{
	if ((y%4==0) && (y%100!=0) || y%400==0)
		return 366;
	else
		return 365;
}
int main()
{
	int y,i,j,m;
	int sum=0;	
	int begin,week;
	int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	printf("���������:"); 
	scanf("%d",&y);        //�������� 
	printf("�������·�:");
	scanf("%d",&m);
	for(i=1;i<y;i++)
		sum+=year(i);
	week=(sum+1)%7;		//��ʾ����1��1��Ϊ���ڼ�
	if(year(y)==366)
		month[1]=29;	//�������29�� 
	printf(" �� һ �� �� �� �� �� \n");
	printf("========================\n");
	for(i=0;i<12;i++)
	{
		begin=1;
		for(j=0;j<week;j++)
		{
			if(i==m-1)
			{
				printf("   ");    //��ӡ���� �еĿ� 
			}
		}
		while(begin<=month[i])
		{
			if(i==m-1)
			{	
				printf("%3d",begin);
			}
				begin++;
				week=(week+1)%7;
				if(week%7==0)
				{
					if(i==m-1)
					{
						printf("\n");   //���� 	
					}
				}			
		}
	}
	return 0;
}

