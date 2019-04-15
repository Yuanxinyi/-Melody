//��֪��������head1 ��head2 ��������������Ǻϲ���һ��������Ȼ���� 
#include<stdio.h>
#include<stdlib.h> 
typedef struct Node
{
	int data;
	struct Node *next;
}Node;
Node* Hebing(Node* head1, Node* head2)  //�ϲ��������������һ����������
{
	if(head1 == NULL)
		return head2;
	if(head2 == NULL)
		return head1;
	Node *head, *p1, *p2;
	if(head1->data < head2->data)   //ȷ���úϲ����ͷ��� ����С���� 
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
	Node *move = head;   //����һ����ʱָ��,(���ô���������ռ�ÿռ�)����������������һ��
	while(p1 && p2)      //p1,p2����Ϊ�� 
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
	if(p1)   //p1��p2�����Ƚ�����С���ȵ�����ڵ����Ϊ����ʣ�µ�ֱ�Ӽӵ��Ƚ���ĺ�� 
		move->next = p1;     // ����p1ʣ��δ�ȽϵĽڵ�
	if(p2)
		move->next = p2;     // ����p2ʣ��δ�ȽϵĽڵ�
	return head;
}
Node* Creat()      //����Ĵ���
{
	Node *head,*p,*s;
	head =(struct Node *)malloc(sizeof(struct Node));
	int x,flag = 1;
	if(head == NULL)
		printf("ͷ��㴴��ʧ��!\n");
	p = head;
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
	printf("�������ɹ���\n");	
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
