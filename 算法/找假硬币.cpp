// ��16��Ӳ�ҵĴ��ӣ�16��Ӳ������һ����α��ģ������Ǹ�α���Ӳ�ұ�������Ӳ��Ҫ��һ�㣬����Ҫ�ҳ����α���Ӳ�ң�
//������һ̨�������Ƚ�����Ӳ��������������������̨����������֪������Ӳ�ҵ������Ƿ���ͬ ��
#include<stdio.h>
int main()
{
	int i;
	int coins[16];//={1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1};     //����1Ϊ��Ӳ�ң�0Ϊα���
	printf("����16��Ӳ�ң�");
	for(i=0;i<16;i++)
	{
		scanf("%d",&coins[i]);
	}
	printf("��һ��:��16��Ӳ�ҷ�Ϊ6�飬3��Ӳ��Ϊһ�������飬���һ��Ӳ��Ϊһ��\n"); 
	int coins1[3],sum1=0;
	int coins2[3],sum2=0; 
	int coins3[3],sum3=0;
	int coins4[3],sum4=0;
	int coins5[3],sum5=0;
	int coins6[1],sum6=0;
	for(i=0;i<3;i++)
	{
		coins1[i]=coins[i];
		sum1+=coins1[i];
		coins2[i]=coins[i+3];
		sum2+=coins2[i];
		coins3[i]=coins[i+6];
		sum3+=coins3[i];
		coins4[i]=coins[i+9];
		sum4+=coins4[i];
		coins5[i]=coins[i+12];
		sum5+=coins5[i];
		sum6=coins6[0]=coins[15];
	}
	if(sum1 == sum2)
	{	printf("��һ����ڶ����������\n");
		if(sum3 == sum4)
		{	printf("��������������������\n");
			if(sum4 == sum5)
			{
				printf("��������������������\n");
				printf("�ٱ���coins6�У�Ϊ��16��Ӳ�ң�\n");
			}
			else
			{
				printf("����������������������\n");
				printf("�ٱ���coins5��!\n");
				if(coins5[0] == coins5[1])
				{
					printf("�ٱ���coins5�е�����!��coins�е�15����\n"); 
				}
				else if(coins5[0] == 0)
				{
					printf("�ٱ���coins5�е�һ��!��coins�е�13����\n"); 
				}
				else if(coins5[1] == 0)
				{
					printf("�ٱ���coins5�еڶ���!��coins�е�14����\n");
				}
			}
		}	
		else if(sum4 < sum3)
		{
			printf("����������С�ڵ����飬��ٱҵ�������\n");
			if(coins4[0] == coins4[1])
			{
				printf("�ٱ���coins4�е�����!��coins�е�12����\n");
		    }
		    else if(coins4[0] == 0)
			{
				printf("�ٱ���coins4�е�һ��!��coins�е�10����\n");
			}
			else if(coins4[1] == 0)
			{
				printf("�ٱ���coins4�еڶ���!��coins�е�11����\n");
			}
		}
		else if(sum3 < sum4)
		{
			printf("�������������ڵ����飬��ٱҵ�������\n");	
			if(coins3[0] == coins3[1])
			{
				printf("�ٱ���coins3�е�����!��coins�е�9����\n");
		    }
		    else if(coins3[0] == 0)
			{
				printf("�ٱ���coins3�е�һ��!��coins�е�7����\n"); 
			}
			else if(coins3[1] == 0)
			{
				printf("�ٱ���coins3�еڶ���!��coins�е�8����\n");
			}	
		}	
		}
	else if(sum2 < sum1)
	{
		printf("��һ���������ڵڶ�����������ٱ��ڵڶ�����\n");
		if(coins2[0] == coins2[1])
		{
			printf("�ٱ���coins2�е�����!��coins�е�6����");
		}
		else if(coins2[0] == 0)
		{
			printf("�ٱ���coins2�е�һ��!��coins�е�4����"); 
		}
		else if(coins2[1] == 0)
		{
			printf("�ٱ���coins2�еڶ���!��coins�е�5����");
		}	
	}
	else if(sum1 <sum2)
	{
		printf("��һ������С�ڵڶ�����������ٱ��ڵ�һ����\n"); 
		if(coins1[0] == coins1[1])
		{
			printf("�ٱ���coins1�е�����!��coins�е�3����"); 
		}
		else if(coins1[0] == 0)
		{
			printf("�ٱ���coins1�е�һ��!��coins�е�1����"); 
		}
		else if(coins1[1] == 0)
		{
			printf("�ٱ���coins1�еڶ���!��coins�е�2����");
		}
	}
	return 0;
}
	
