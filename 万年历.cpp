//万年历 
#include <stdio.h>
//判断一年有多少天，闰年366天，平年365天 
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
	printf("请输入年份:"); 
	scanf("%d",&y);        //输入的年份 
	printf("请输入月份:");
	scanf("%d",&m);
	for(i=1;i<y;i++)
		sum+=year(i);
	week=(sum+1)%7;		//表示该年1月1日为星期几
	if(year(y)==366)
		month[1]=29;	//闰年二月29天 
	printf(" 日 一 二 三 四 五 六 \n");
	printf("========================\n");
	for(i=0;i<12;i++)
	{
		begin=1;
		for(j=0;j<week;j++)
		{
			if(i==m-1)
			{
				printf("   ");    //打印日历 中的空 
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
						printf("\n");   //换行 	
					}
				}			
		}
	}
	return 0;
}

