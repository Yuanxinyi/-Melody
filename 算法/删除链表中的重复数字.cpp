/*��������Ŀ������һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�� 
˼·�����αȽ�ÿ���������Ƿ���ȣ���������ָ��p1,p2,p1ָ��ͷ���,p2��һ����㣬���ͷ�������ݺ���һ�ڵ��������ȣ���ֱ�ӽ�ͷ�������¸�������ӣ�ָ��ָ�����¸���㣬�����Ƚϣ�
���ͷ������һ�ڵ��������ȣ�������ָ����������ƶ������Ƚ� 
*/ 
#include<stdio.h>
#include<stdlib.h>
//�����ṹ�� 
typedef struct Node
{
	int data;
	struct Node *next;
}Node;
//�������� 
Node* Create(Node *head); //��������
void print(Node *head);   //��ӡ
Node * Del(Node *head);   //ɾ�� 
//������ 
int main()
{
	Node *head=(Node *)malloc(sizeof(Node));
	head->next=NULL;	//head�Ľ�βָ��� 
	head=Create(head);
	head=Del(head);
	printf("\nɾ����:");
	print(head);
	return 0;
 } 
//���� 
Node* Create(Node *head)
{
	Node *p=head,*a;
	printf("�����������ݣ�0��������\n");
	while(1)
	{
		a=(Node *)malloc(sizeof(Node));
		scanf("%d",&a->data);
		p->next=a;
		if(a->data==0)
			break;
		p=a;
	}
	p->next=NULL;
	return head;
}
//����Ĵ�ӡ
void print(Node *head)
{
	Node *p=head->next;
	while(p!=NULL)
	{
		printf("%d\t ",p->data);
		p=p->next ;
	}
	printf("\n");
}
//ɾ�� 
Node * Del(Node *head)
{
	Node *p1=head->next,*p2=p1->next;
	while(p2)
	{
		if(p1->data==p2->data)
		{
			while(p1->data==p2->data)   //��������ȵĽ����ѭ���ж�  
			{
				p2=p2->next;     //p2һֱ���ָ�������������������һ������������p2==NULL,�˳�
				if(p2==NULL)
					break;	
			}                    //�����βΪ 8 8 9����p2=9,p1=8,Ȼ��p1���ָ��p2,p2�����ָ��ΪNULL��
			p1->next=p2;          
			p1=p2;
			if(p2!=NULL) 
				p2=p2->next;
		}
		else
		{
			p1=p1->next;        //�����ͬ�����ָ 
			p2=p2->next;
		}
	}
	return head;
}

