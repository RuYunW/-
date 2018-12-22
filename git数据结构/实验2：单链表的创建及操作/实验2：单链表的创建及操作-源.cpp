/* 数据结构实验二 
   ——单链表的创建及操作
*/
/*	  1、创建一个带头结点的单链表（头指针为head），且遍历此链表（输出链表中各结点的值）；√
      2、查找单链表中的第i个结点，并输出结点元素的值；√
      3、在单链表中的第i个结点前插入一个结点值为e的正整数(从外部输入);√
      4、删除单链表中的第j个结点；√
     *5、将单链表中的各结点就地逆序（不允许另建一个链表）；√
*/
#include<stdio.h>
#include<malloc.h>
struct Linklist
	{
		int data;
		Linklist *next;
	};

void Createlist(Linklist *&L,int n)//n为链节个数,L为头结点
{
	int i;
	Linklist*p;//指向节点
	L = (Linklist*)malloc(sizeof(Linklist));
	L->next = NULL;//初始化头结点

	//从头结点后插入新节点
	for (i = 0; i <n; i++)
	{
		p = (Linklist*)malloc(sizeof(Linklist));
		printf("请输入数字\n");
		scanf_s("%d", &p->data);//输入
		p->next = L->next;
		L->next = p;

	}

}
int main()
{
	//头结点
	Linklist *head;
	
	printf("请输入5个数字：\n");
	//创建5个节点的链表
	Createlist(head, 5);
	Linklist*p = head->next;
	//输出
	
	printf("输出：");
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	putchar('\n');

	int k;
	printf("查找第k个元素的值，请输入k:\n");
	scanf_s("%d", &k);

	int i;
	p = head->next;//初始化p
	
	//输出第k个元素的值
	for (i = 1; i <= k; i++)
	{
		
		if (i == k)
		{
			printf("第%d个元素为：%d\n",k, p->data);
			break;
		}
		p = p->next;
	}

	//在k前插入e
	printf("在k前插入e，请输入k：");
	scanf_s("%d", &k);
	int e;
	printf("请输入插入的数值e：");
	scanf_s("%d", &e);

	p = head->next;//初始化p
	Linklist*q;
	for(i=1;i<=k;i++)
	{
		
		if (i == k-1)
		{
			q = (Linklist *) malloc(sizeof(Linklist));
			q->data = e;
			q->next = p->next;
			p->next = q;
			break;
		}
		p = p->next;
	}
	p = head->next;
	putchar('\n');
	//输出链表
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	putchar('\n');

	//删除链表中第j个节点
	int j;
	printf("删除链表中第j个节点，请输入j：");
	scanf_s("%d", &j);
	p = head->next;
	q = head->next;
	for (i = 1; i <= j;i++)
	{
		
		if (i == j-1)
		{
			q=p->next;
			
			p->next = q->next;
			free(q);
			break;
		}
		p = p->next;
	}
	p = head->next;
	//输出链表
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	putchar('\n');
	//就地逆序
	p = head->next;
	head->next = NULL;
	while (p != NULL)
	{
		q = p->next;
		p->next = head->next;
		head->next = p;
		p = q;
	}
	printf("逆序后链表为：\n");
	p = head->next;

	//输出链表
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	putchar('\n');
	return 0;
}