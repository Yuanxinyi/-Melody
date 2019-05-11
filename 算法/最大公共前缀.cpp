//编写一个函数来查找字符串数组的最大公共前缀，如果不存在公共前缀，返回空字符串""
#include<stdio.h>
#include<string.h>
#include<conio.h> 
#define N 3
#define M 20
void qianzhui(char str[][M]) 
{
	int i,j,m=0,flag=1,length,shortlength=0;
	char result[M];
	length=strlen(str[0]);
	shortlength=length;
	for(i=1;i<N;i++)
	{
		length=strlen(str[i]);
		if(length<shortlength)
			shortlength=length;
	}
	for(i=0;i<shortlength;i++)   //以第最短的字符串长度为基准 
	{
		for(j=1;j<N;j++)
		{
			if(str[0][i] != str[j][i])
			{
				result[m]='\0';
				flag=0;
				break;
			}
		}
		if(flag==0)
			break; 
		result[m++]=str[0][i];
	}
	if(flag)
		result[m]='\0';
	printf("\"%s\"",result);
}
int main()
{
	char str[N][M];
	for(int i=0;i<N;i++)
	{
		gets(str[i]);
	}
	qianzhui(str);
	getchar();
	return 0;
 } 
