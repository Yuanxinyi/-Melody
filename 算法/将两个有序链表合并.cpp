//已知两个链表head1 和head2 各自有序，请把它们合并成一个链表依然有序。 
#include<stdio.h>
#include<stdlib.h> 
typedef struct Node
{
	int data;
	struct Node *next;
}Node;
Node* Hebing(Node* head1, Node* head2)  //合并两个有序链表成一个有序链表
{
	if(head1 == NULL)
		return head2;
	if(head2 == NULL)
		return head1;
	Node *head, *p1, *p2;
	if(head1->data < head2->data)   //确定好合并后的头结点 （从小到大） 
	{
		head = head1;
		p1 = head1->next;
		p2 = head2;
	}
	else{
		head = head2;
		p1 = head1;
		p2 = head2->next;
	}	
	Node *move = head;   //定义一个临时指针,(不用创建新链表占用空间)将两个链表连接在一起
	while(p1 && p2)      //p1,p2都不为空 
	{
		if(p1->data <= p2->data)
		{
			move->next = p1;
			move = p1;
			p1 = p1->next;
		}
		else
		{
			move->next = p2;
			move = p2;
			p2 = p2->next;
		}
	}
	if(p1)   //p1比p2长，比较完最小长度的链表节点后，因为有序，剩下的直接加到比较完的后边 
		move->next = p1;     // 补齐p1剩余未比较的节点
	if(p2)
		move->next = p2;     // 补齐p2剩余未比较的节点
	return head;
}
Node* Creat()      //链表的创建
{
	Node *head,*p,*s;
	head =(struct Node *)malloc(sizeof(struct Node));
	int x,flag = 1;
	if(head == NULL)
		printf("头结点创建失败!\n");
	p = head;
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
	printf("链表建立成功！\n");	
    return head;	
}
void Print(Node *head)
{
	Node *p = head;
	while(p!=NULL)
	{
		printf("%d  ",p->data);
		p = p->next;
	}
	//printf("\n");
}
int main()
{
	Node *head1 = Creat();
	Node *head2 = Creat();
	Node *head3 = Hebing(head1, head2);
	Print(head3);
	return 0;
}
