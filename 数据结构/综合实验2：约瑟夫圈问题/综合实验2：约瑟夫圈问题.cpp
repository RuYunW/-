/*
�ۺ�ʵ��� Լɪ������ʵ��
*/
/*
1.����һ������n������ѭ�����������ڴ洢Բ����Χ���˵ı�ţ��������data����������Χ���˵ı�š�
2.Ϊ���ֳ����ͨ����,�����е�n��m��k�����û��Ӽ�������.
3.Ҫ���д����ģ��Լɪ�������ʵ�ֹ���,�����n���˵ĳ���˳��
4.n���ˣ���m��ʼ������Ŀ������k
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
	printf("������n����n<20��\n");
	scanf_s("%d", &n);

	//����ͷ���
	Listnode*head = (Listnode*)malloc(sizeof(Listnode));
	Listnode*q;
	Listnode*p;
	head->next = NULL;
	head->data = 1;//��һ�������1
	p = head;
	int i;

	//����������
	for(i=2;i<=n;i++)
	{
		q = (Listnode*)malloc(sizeof(Listnode));
		q->data = i;
		q->next = NULL;
		p->next = q;
		p = q;
	}

	p->next = head;//ʹ����ѭ��
	p = head;//pָͷ�����������

	int m;
	putchar('\n');
	printf("��m��ʼ������������m����m<%d��\n", n);
	scanf_s("%d", &m);

	//��pָ���Ƶ�m��
	for (i = 0; i < m-1; i++)
	{
		p = p->next;
		
	}

	int k;
	printf("�������������k��\n");
	scanf_s("%d", &k);

	int a[20];//�������˳��

	//��Ϸ��ʼ
	int count = 0;//������
	int out = 0;//��������

	while(out<=n-1)//������n-1�ˣ�ֻʣ1���ˣ���Ϸ����
	{
		//��ʼ����
		count++;
		
		//������k-1ʱ���¸��ڵ㱨��k��ɾ���¸��ڵ�
		if(count==k-1)
		{
			out++;//��������+1
			q = p->next;//qָ����Ϊk�ڵ㣬׼��ɾ��
			a[out-1] = q->data;//����������

			//ɾ���ڵ�
			p->next = q->next;
			free(q);

			count = 0;//���ü�����
		}
		p = p->next;//ָ����һ��
	}

	a[out]=head->data;//���ʣ��ڵ�Ϊ���ճ��ֵ���

	//��ӡ���
	printf("����˳��Ϊ��");
	for (i = 0; i < n; i++)
	{
		printf("%d  ", a[i]);
	}
	putchar('\n');
}
