/* ���ݽṹʵ��� 
   ����������Ĵ���������
*/
/*	  1������һ����ͷ���ĵ�����ͷָ��Ϊhead�����ұ�����������������и�����ֵ������
      2�����ҵ������еĵ�i����㣬��������Ԫ�ص�ֵ����
      3���ڵ������еĵ�i�����ǰ����һ�����ֵΪe��������(���ⲿ����);��
      4��ɾ���������еĵ�j����㣻��
     *5�����������еĸ����͵����򣨲�������һ����������
*/
#include<stdio.h>
#include<malloc.h>
struct Linklist
	{
		int data;
		Linklist *next;
	};

void Createlist(Linklist *&L,int n)//nΪ���ڸ���,LΪͷ���
{
	int i;
	Linklist*p;//ָ��ڵ�
	L = (Linklist*)malloc(sizeof(Linklist));
	L->next = NULL;//��ʼ��ͷ���

	//��ͷ��������½ڵ�
	for (i = 0; i <n; i++)
	{
		p = (Linklist*)malloc(sizeof(Linklist));
		printf("����������\n");
		scanf_s("%d", &p->data);//����
		p->next = L->next;
		L->next = p;

	}

}
int main()
{
	//ͷ���
	Linklist *head;
	
	printf("������5�����֣�\n");
	//����5���ڵ������
	Createlist(head, 5);
	Linklist*p = head->next;
	//���
	
	printf("�����");
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	putchar('\n');

	int k;
	printf("���ҵ�k��Ԫ�ص�ֵ��������k:\n");
	scanf_s("%d", &k);

	int i;
	p = head->next;//��ʼ��p
	
	//�����k��Ԫ�ص�ֵ
	for (i = 1; i <= k; i++)
	{
		
		if (i == k)
		{
			printf("��%d��Ԫ��Ϊ��%d\n",k, p->data);
			break;
		}
		p = p->next;
	}

	//��kǰ����e
	printf("��kǰ����e��������k��");
	scanf_s("%d", &k);
	int e;
	printf("������������ֵe��");
	scanf_s("%d", &e);

	p = head->next;//��ʼ��p
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
	//�������
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	putchar('\n');

	//ɾ�������е�j���ڵ�
	int j;
	printf("ɾ�������е�j���ڵ㣬������j��");
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
	//�������
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	putchar('\n');
	//�͵�����
	p = head->next;
	head->next = NULL;
	while (p != NULL)
	{
		q = p->next;
		p->next = head->next;
		head->next = p;
		p = q;
	}
	printf("���������Ϊ��\n");
	p = head->next;

	//�������
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	putchar('\n');
	return 0;
}