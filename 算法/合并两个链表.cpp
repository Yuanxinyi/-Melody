//��������������ϲ�Ϊһ���µ������������أ��µ�������ͨ��ƴ�Ӹ�����������������н����ɵ�
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
	while(scanf("%d",&n) == 1)   //�����벻Ϊ����ʱ����
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
		printf("���:%d",p->num);
		p=p->next;
	}
	printf("\n");
	//printf("***");
	return 0;
} 
