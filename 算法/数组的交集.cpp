#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

void Intersection(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int k=0;
    int *result= (int*)malloc(sizeof(int) * (nums1Size<=nums2Size?nums2Size:nums1Size));
    for(int i=0;i<nums1Size;i++)
    {  
        int num=1;
        for(int l=0;l<k;l++){ //�жϼ���Ҫ�Ƚϵ�Ԫ�غͽ��������û���ظ�
            if(result[l]==nums1[i])
                num=0;
        }
        if(num==0)
            continue;
        else{
            for(int j=0;j<nums2Size;j++)
            {
                if(nums1[i]==nums2[j]){
                    result[k]=nums2[j];
                    k++;
                    break;
                }
            }
        }
    }
    int Size=k;
   	for(int j=0;j<k;j++)
	{
		printf("%d\t",result[j]);
	  }  
}
int main()
{
	int i,N,M;
	printf("����������1�ĳ��ȣ�");
	scanf("%d",&N);
	printf("����������2 �ĳ���:");
	scanf("%d",&M); 
	int nums1[N],nums2[M];
	printf("����������1����:");
	for(i=0;i<N;i++)
	{
		scanf("%d",&nums1[i]);
	}
	printf("����������2����:"); 
	for(i=0;i<M;i++)
	{
		scanf("%d",&nums2[i]);
	}
	Intersection(nums1,N,nums2,M);
	return 0;	
 } 
