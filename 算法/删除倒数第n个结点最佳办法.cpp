#include<stdio.h>        //删除倒数第n个结点
#include<stdlib.h>
#include<string.h>
//思路：创建好一个链表，然后定义两个指针，先让第一个指针开始走n-1步，然后两个指针同时走，同时遍历链表，这时当第一个指针走到链表末尾的时候，第二个指针刚好走到目标节点，进行删除操作即可。
//定义结构体
typedef struct Node
{
	int data;
	struct Node *next;
 }Node;
Node* Creat()      //链表的创建
{
	Node *head,*p,*s;
	head =(struct Node *)malloc(sizeof(struct Node));
	int x,flag = 1;
	if(head == NULL)
		printf("头结点创建失败!\n");
	p = head;   //p永远指向head的尾部 
	printf("输入(以0结束，从小到大):");
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
 //打印链表
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
 //删除 
Node *Del(Node *head)
{
	int i=0,n;
	Node *first=head;
	Node *second=head;
	printf("请输入要删除的结点倒数序号:");
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
  
