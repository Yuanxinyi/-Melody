//将两个有序链表合并为一个新的有序链表并返回，新的链表是通过拼接给定的两个链表的所有结点组成的
#include<stdio.h>
#include<stdlib.h> 
struct node{
	int num;
	struct node *next;
}; 
int main(void){
	int n;
	struct node *head = NULL;
	struct node *p ;
	struct node *tail = NULL;
	while(scanf("%d",&n) == 1)   //当输入不为整数时结束
	{
		p=(struct node *)malloc(sizeof(struct node));
		if(head == NULL)
			head = p;
		else
			tail->next = NULL;
		p->num = n;
		p->next = NULL;
		tail = p;
	}
	p = head;
	while(p != NULL)
	{
		printf("输出:%d",p->num);
		p=p->next;
	}
	printf("\n");
	//printf("***");
	return 0;
} 
