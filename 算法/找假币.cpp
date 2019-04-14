// 有16个硬币的袋子，16个硬币中有一个是伪造的，并且那个伪造的硬币比真正的硬币要轻一点，我们要找出这个伪造的硬币，
//我们有一台可用来比较两组硬币重量的仪器，利用这台仪器，可以知道两组硬币的重量是否相同 。
#include<stdio.h>
#include<math.h>
int main() 
{    
	int n;   
	printf("请输入硬币总数:"); 
	while(scanf("%d",&n)!=EOF)
	{        
		if(n==0) 
		break;        
		int times=0;        
		while(pow(3,times)<n)
 		{           
 	 		times++;      
    	}    
		printf("找到这枚假币需要的最少的次数为:");   
	 	printf("%d\n",times); 
	}    	
	return 0;
}
