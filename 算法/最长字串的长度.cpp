//����һ���ַ����������ҳ����в������ظ��ַ�����ִ��ĳ��� 
#include<stdio.h>
#include<string.h>
#define N  100
int main()
{
	char A[N]; 
	int i,j,k,l,length,max=0;
	printf("�������ַ���:");
	gets(A);
	length=strlen(A);
	for(i=0;i<length;i++)
	{
		for(j=1+i;j<length;j++)
		{
			for(k=i;k<j;k++)
			{
				if(A[k]==A[j])
				{
					l=j;
					j=length;
					k=j;
				 } 
			}		
		} 
		if(l-i>max)     //�Ƚϳ��� 
			max=l-i;
	} 
	if(max==0)
		max=length;
	printf("%d",max);
	return 0; 
} 
