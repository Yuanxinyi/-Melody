/*第六周题目：给行一个排序链表，删除所有重复的元素，使得每个元素只出现一次 
思路：依次比较每个结点的数是否相等，定义两个指针p1,p2,p1指向头结点,p2下一个结点，如果头结点的数据和下一节点的数组相等，则直接将头结点和下下个结点连接，指针指向下下个结点，继续比较；
如果头结点和下一节点的数不相等，则两个指针依次向后移动继续比较 
*/ 
#include<stdio.h>
#include<stdlib.h>
//创建结构体 
typedef struct Node
{
	int data;
	struct Node *next;
}Node;
//函数声明 
Node* Create(Node *head); //创建链表
void print(Node *head);   //打印
Node * Del(Node *head);   //删除 
//主函数 
int main()
{
	Node *head=(Node *)malloc(sizeof(Node));
	head->next=NULL;	//head的结尾指向空 
	head=Create(head);
	head=Del(head);
	printf("\n删除后:");
	print(head);
	return 0;
 } 
//创建 
Node* Create(Node *head)
{
	Node *p=head,*a;
	printf("请输入结点数据（0结束）：\n");
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
//链表的打印
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
//删除 
Node * Del(Node *head)
{
	Node *p1=head->next,*p2=p1->next;
	while(p2)
	{
		if(p1->data==p2->data)
		{
			while(p1->data==p2->data)   //有连续相等的结点则循环判断  
			{
				p2=p2->next;     //p2一直向后指，如果最后结束的数字是一连串相等则到最后p2==NULL,退出
				if(p2==NULL)
					break;	
			}                    //如果结尾为 8 8 9，当p2=9,p1=8,然后p1向后指向p2,p2再向后指就为NULL了
			p1->next=p2;          
			p1=p2;
			if(p2!=NULL) 
				p2=p2->next;
		}
		else
		{
			p1=p1->next;        //如果不同则向后指 
			p2=p2->next;
		}
	}
	return head;
}

