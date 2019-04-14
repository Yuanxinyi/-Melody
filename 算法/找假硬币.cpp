// 有16个硬币的袋子，16个硬币中有一个是伪造的，并且那个伪造的硬币比真正的硬币要轻一点，我们要找出这个伪造的硬币，
//我们有一台可用来比较两组硬币重量的仪器，利用这台仪器，可以知道两组硬币的重量是否相同 。
#include<stdio.h>
int main()
{
	int i;
	int coins[16];//={1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1};     //假设1为真硬币，0为伪造币
	printf("输入16个硬币：");
	for(i=0;i<16;i++)
	{
		scanf("%d",&coins[i]);
	}
	printf("第一步:将16个硬币分为6组，3个硬币为一组有五组，最后一个硬币为一组\n"); 
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
	{	printf("第一组与第二组重量相等\n");
		if(sum3 == sum4)
		{	printf("第三组与第四组重量相等\n");
			if(sum4 == sum5)
			{
				printf("第五组与第四组重量相等\n");
				printf("假币在coins6中，为第16个硬币！\n");
			}
			else
			{
				printf("第五组与第四组重量不相等\n");
				printf("假币在coins5中!\n");
				if(coins5[0] == coins5[1])
				{
					printf("假币在coins5中第三个!在coins中第15个！\n"); 
				}
				else if(coins5[0] == 0)
				{
					printf("假币在coins5中第一个!在coins中第13个！\n"); 
				}
				else if(coins5[1] == 0)
				{
					printf("假币在coins5中第二个!在coins中第14个！\n");
				}
			}
		}	
		else if(sum4 < sum3)
		{
			printf("第四组重量小于第三组，则假币第四组中\n");
			if(coins4[0] == coins4[1])
			{
				printf("假币在coins4中第三个!在coins中第12个！\n");
		    }
		    else if(coins4[0] == 0)
			{
				printf("假币在coins4中第一个!在coins中第10个！\n");
			}
			else if(coins4[1] == 0)
			{
				printf("假币在coins4中第二个!在coins中第11个！\n");
			}
		}
		else if(sum3 < sum4)
		{
			printf("第四组重量大于第三组，则假币第三组中\n");	
			if(coins3[0] == coins3[1])
			{
				printf("假币在coins3中第三个!在coins中第9个！\n");
		    }
		    else if(coins3[0] == 0)
			{
				printf("假币在coins3中第一个!在coins中第7个！\n"); 
			}
			else if(coins3[1] == 0)
			{
				printf("假币在coins3中第二个!在coins中第8个！\n");
			}	
		}	
		}
	else if(sum2 < sum1)
	{
		printf("第一组重量大于第二组重量，则假币在第二组中\n");
		if(coins2[0] == coins2[1])
		{
			printf("假币在coins2中第三个!在coins中第6个！");
		}
		else if(coins2[0] == 0)
		{
			printf("假币在coins2中第一个!在coins中第4个！"); 
		}
		else if(coins2[1] == 0)
		{
			printf("假币在coins2中第二个!在coins中第5个！");
		}	
	}
	else if(sum1 <sum2)
	{
		printf("第一组重量小于第二组重量，则假币在第一组中\n"); 
		if(coins1[0] == coins1[1])
		{
			printf("假币在coins1中第三个!在coins中第3个！"); 
		}
		else if(coins1[0] == 0)
		{
			printf("假币在coins1中第一个!在coins中第1个！"); 
		}
		else if(coins1[1] == 0)
		{
			printf("假币在coins1中第二个!在coins中第2个！");
		}
	}
	return 0;
}
	
