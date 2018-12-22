/*
综合实验二 约瑟夫问题实验
*/
/*
1.构造一个具有n个结点的循环单链表，用于存储圆桌周围的人的编号，链表结点的data域存放桌子周围的人的编号。
2.为保持程序的通用性,问题中的n、m、k可由用户从键盘输入.
3.要求编写函数模拟约瑟夫问题的实现过程,并输出n个人的出列顺序。
4.n个人，从m开始报数，目标数字k
*/
#include<stdio.h>
#include<malloc.h>
#include<iostream>

typedef struct node
{
	int data;
	struct node*next;
}Listnode;

int main()
{
	int n;
	printf("请输入n：（n<20）\n");
	scanf_s("%d", &n);

	//创建头结点
	Listnode*head = (Listnode*)malloc(sizeof(Listnode));
	Listnode*q;
	Listnode*p;
	head->next = NULL;
	head->data = 1;//第一个人序号1
	p = head;
	int i;

	//创建单链表
	for(i=2;i<=n;i++)
	{
		q = (Listnode*)malloc(sizeof(Listnode));
		q->data = i;
		q->next = NULL;
		p->next = q;
		p = q;
	}

	p->next = head;//使链表循环
	p = head;//p指头方便后续操作

	int m;
	putchar('\n');
	printf("从m开始报数，请输入m：（m<%d）\n", n);
	scanf_s("%d", &m);

	//把p指针移到m处
	for (i = 0; i < m-1; i++)
	{
		p = p->next;
		
	}

	int k;
	printf("请输入出局数字k：\n");
	scanf_s("%d", &k);

	int a[20];//储存出局顺序

	//游戏开始
	int count = 0;//计数器
	int out = 0;//出局人数

	while(out<=n-1)//当出局n-1人，只剩1个人，游戏结束
	{
		//开始报数
		count++;
		
		//报数到k-1时，下个节点报数k，删除下个节点
		if(count==k-1)
		{
			out++;//出局人数+1
			q = p->next;//q指报数为k节点，准备删除
			a[out-1] = q->data;//储存出局序号

			//删除节点
			p->next = q->next;
			free(q);

			count = 0;//重置计数器
		}
		p = p->next;//指向下一人
	}

	a[out]=head->data;//最后剩余节点为最终出局的人

	//打印结果
	printf("出局顺序为：");
	for (i = 0; i < n; i++)
	{
		printf("%d  ", a[i]);
	}
	putchar('\n');
}
