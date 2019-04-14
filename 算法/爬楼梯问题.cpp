#include<stdio.h>
int louti(int n){
	long int f;
	if(n==1)
		return 1;
	if(n==2)
		return 2;
	f=louti(n-1)+louti(n-2);
	return f;
} 
int main(void) {
 	int n; 
 	printf("请输入台阶总数:");
 	scanf("%d",&n);
 	printf("方法:%ld",louti(n)); 
}
