/*
ʵ��6��������ȱ������������ȱ�����һ������n�����������ͼ��
//�������
https://blog.csdn.net/wqc_csdn/article/details/52673664
*/

#include<stdio.h>
#include<stdlib.h>
#define N 8 //�ڵ����

//�ڽӱ��ʾ�� ��ͷ���
typedef struct VNode  
{
	int data;//������Ϣ
	VNode* firstarc;//ָ�������е�һ���ڵ�
}VNode;

//����ͼ
VNode* Creat(VNode*a) 
{
	int i = 0;
	for (i = 0; i < N; i++)//��ʼ��
	{
		a[i].data = i;
	}

	VNode* p0, *q0;
	p0 = (VNode*)malloc(sizeof(VNode));
	a[0].firstarc = p0;
	p0->data = 1;
	q0 = (VNode*)malloc(sizeof(VNode));
	p0->firstarc = q0;
	q0->data = 2;
	q0->firstarc = NULL;
	
	

	VNode* p1, *q1, *r1;
	p1 = (VNode*)malloc(sizeof(VNode));
	p1->data = 0;
	a[1].firstarc = p1;
	q1 = (VNode*)malloc(sizeof(VNode));
	q1->data = 3;
	p1->firstarc = q1;
	r1 = (VNode*)malloc(sizeof(VNode));
	r1->data = 4;
	r1->firstarc = NULL;
	q1->firstarc = r1;

	VNode* p2, *q2,*r2;
	p2 = (VNode*)malloc(sizeof(VNode));
	p2->data = 0;
	a[2].firstarc = p2;
	q2 = (VNode*)malloc(sizeof(VNode));
	q2->data = 5;
	p2->firstarc = q2;
	r2 = (VNode*)malloc(sizeof(VNode));
	r2->data = 6;
	r2->firstarc = NULL;
	q2->firstarc = r2;


	VNode* p3,*q3;
	p3 = (VNode*)malloc(sizeof(VNode));
	p3->data = 1;
	a[3].firstarc = p3;
	q3 = (VNode*)malloc(sizeof(VNode));
	q3->data = 7;
	q3->firstarc = NULL;
	p3->firstarc = q3;

	VNode* p4,*q4;
	p4 = (VNode*)malloc(sizeof(VNode));
	p4->data = 1;
	a[4].firstarc = p4;
	q4 = (VNode*)malloc(sizeof(VNode));
	q4->data = 7;
	q4->firstarc = NULL;
	p4->firstarc = q4;

	VNode* p5;
	p5 = (VNode*)malloc(sizeof(VNode));
	p5->data = 2;
	p5->firstarc = NULL;
	a[5].firstarc = p5;

	VNode *p6;
	p6 = (VNode*)malloc(sizeof(VNode));
	p6->data = 2;
	p6->firstarc = NULL;
	a[6].firstarc = p6;

	VNode*p7,*q7;
	p7 = (VNode*)malloc(sizeof(VNode));
	p7->data = 3;
	q7 = (VNode*)malloc(sizeof(VNode));
	q7->data = 4;
	p7->firstarc = q7;
	q7->firstarc = NULL;
	a[7].firstarc = p7;
	

	return a;
}

//��ӡͼ���ڽӱ�
void Print(VNode*a)
{
	VNode* p;
	printf("��ͼ���ڽӱ����£�\n");
	for (int i = 0; i < N; i++)//���ͼ
	{
		printf("v%d��", a[i].data);
		if (a[i].firstarc)//���a��β��,��ӡβ��
		{
			p = a[i].firstarc;
			while (1)
			{
				printf("%d��", p->data);
				if (p->firstarc == NULL)
				{
					printf("NULL\n");
					break;
				}
				p = p->firstarc;
			}
		}
		else
		{
			printf("NULL\n");
		}
	}
}

//������ȱ���ͼ
void WScan(VNode* a)
{
	printf("������ȱ������£�\n");
	int visited[N] = { 0 };//���
	visited[0] = 1;
	printf("v0  ");
	VNode *p;
	//������ȱ���ͼ
	for (int i = 0; i < N; i++)
	{
		if (a[i].firstarc)//���a��β��,��ʼ����β��
		{
			p = a[i].firstarc;//��ʼ��p��ͷ���
			while(1)
			{
				if (visited[p->data] == 0 )//���p��ָ���δ�����ʣ������
				{
					printf("v%d  ", p->data);
					visited[p->data] = 1;
				}
				
				if (p->firstarc == NULL)//���ڽӱ����������ѭ������ʼ��һ���ڽӱ����
				{
					break;
				}
				p = p->firstarc;
			}
		}
		else//���aûβ�ͣ���ʼ�µ�ѭ��
		{
			continue;
		}
	}
	

	
}


int main()
{
	struct VNode a[N];//��ͷ����

	Creat(a);//�����ڽӱ�
	Print(a);//��ӡͼ���ڽӱ�
	printf("\n");
	WScan(a);//������ȱ���
	

	return 0;
}
