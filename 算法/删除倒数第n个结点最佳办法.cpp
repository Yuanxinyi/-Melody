#include<stdio.h>        //ɾ��������n�����
#include<stdlib.h>
#include<string.h>
//˼·��������һ������Ȼ��������ָ�룬���õ�һ��ָ�뿪ʼ��n-1����Ȼ������ָ��ͬʱ�ߣ�ͬʱ����������ʱ����һ��ָ���ߵ�����ĩβ��ʱ�򣬵ڶ���ָ��պ��ߵ�Ŀ��ڵ㣬����ɾ���������ɡ�
//����ṹ��
typedef struct Node
{
	int data;
	struct Node *next;
 }Node;
Node* Creat()      //����Ĵ���
{
	Node *head,*p,*s;
	head =(struct Node *)malloc(sizeof(struct Node));
	int x,flag = 1;
	if(head == NULL)
		printf("ͷ��㴴��ʧ��!\n");
	p = head;   //p��Զָ��head��β�� 
	printf("����(��0��������С����):");
	while(flag)
	{
		scanf("%d",&x);
		if(x != 0)
		{
			s =(struct Node *)malloc(sizeof(struct Node));
			s->data = x;
			p->next = s;
			p = s;	
		}
		else
			flag = 0;		
	}
	head = head->next;
	p->next = NULL;	
    return head;	
}
 //��ӡ����
void Print(Node *head)
{
	Node *p=head;
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p=p->next;
	 } 
	 printf("\n");
 } 
 //ɾ�� 
Node *Del(Node *head)
{
	int i=0,n;
	Node *first=head;
	Node *second=head;
	printf("������Ҫɾ���Ľ�㵹�����:");
	scanf("%d",&n);
	while(i<n)
	{
		first=first->next;
		i++;
	}
	for(i=0;first->next!=NULL;i++)
	{
		first=first->next;
		second=second->next;
	}
	second->next=second->next->next;
	return head;
}
int main()
{
	Node *head;
	head=Creat();
	Print(head);
	head=Del(head);
	Print(head);
	return 0; 
}
  
