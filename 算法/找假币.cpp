// ��16��Ӳ�ҵĴ��ӣ�16��Ӳ������һ����α��ģ������Ǹ�α���Ӳ�ұ�������Ӳ��Ҫ��һ�㣬����Ҫ�ҳ����α���Ӳ�ң�
//������һ̨�������Ƚ�����Ӳ��������������������̨����������֪������Ӳ�ҵ������Ƿ���ͬ ��
#include<stdio.h>
#include<math.h>
int main() 
{    
	int n;   
	printf("������Ӳ������:"); 
	while(scanf("%d",&n)!=EOF)
	{        
		if(n==0) 
		break;        
		int times=0;        
		while(pow(3,times)<n)
 		{           
 	 		times++;      
    	}    
		printf("�ҵ���ö�ٱ���Ҫ�����ٵĴ���Ϊ:");   
	 	printf("%d\n",times); 
	}    	
	return 0;
}
