
/*

	Name: 

	Copyright: 

	Author: 

	Date: 27/07/17 08:43

	Description: 

		【程序1】题目：有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？

		1.程序分析：可填在百位、十位、个位的数字都是1、2、3、4。

					组成所有的排列后再去掉不满足条件的排列。 

*/

 

#include <stdio.h>

 
/*
int main()

{

	int i,j,k,count = 0;

	printf("\n");

	for(i = 1;i < 5;i++)

	{

		for(j = 1;j < 5;j++)

		{

			for(k = 1;k < 5;k++)

			{

				if(i != k && i != j && j != k)

				{

					printf("%d%d%d\n",i,j,k);

					count++;

				}

			}

		}

	}

	printf("\n");

	printf("总共有%d个\n",count);

	return 0;

}

*/
/*程序改进：增加一个 int 变量 t，用来记录第一次循环中 i 的值。跳出第一次循环后判断 i-t 的值是否为1（即百位数是否增1），若为1，则打印1个换行符。改进代码如下*/
int main()

{

	int i, j, k, t = 1;

	for (i = 1; i < 5; i++)//以下为三重循环
	

	{

		if (i - t)//若百位数加1

			printf("\n");//则打印一个换行符

		for (j = 1; j < 5; j++)

			for (k = 1; k < 5; k++)

			{

				if (i != k && i != j && j != k)//确保i、j、k三位互不相同

				{

					printf("%d%d%d ", i, j, k);

				}

			}

		t = i;//记录循环前i的值

	}

	getchar();

}

