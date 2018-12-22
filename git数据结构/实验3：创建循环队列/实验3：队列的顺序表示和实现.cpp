/*	����һ��ѭ������, ʵ�����в���
1����ʼ������(���)��
2����ӣ�
3������;
4������г��ȣ�
5���ж϶����Ƿ�Ϊ�գ�
*/

#include<stdio.h>
#include<stdlib.h>

#define QUEUE_SIZE 10

typedef struct queue
{
	int front;
	int rear;//rearָ��ָ���βԪ�ص���һ��λ��,��front����rearʱ���˶��в��ǻ�ʣһ��Ԫ�أ����ǿն���
}Queue;

//����г���
int countLength(int *a, int rear, int front)
{
	int length = 0;
	length = (rear - front + QUEUE_SIZE) % QUEUE_SIZE;
	return length;
}

//���
 int enterQueue(int * a, int rear, int front)
{
	printf("----��Ӳ���----\n");

	int length;//�������λ�ø���
	length = countLength(a, rear, front);
	printf("\t���л�������%d��Ԫ��\n",QUEUE_SIZE-length-1);
	int n;//���Ԫ�ظ���
	printf("\t���������Ԫ�ظ�����");
	scanf_s("%d", &n);
	
	if (n < QUEUE_SIZE - length-1)//�ж϶���δ��,ִ�в���
	{
		printf("\t��ǰ����δ��,������%d������\n",n);
		for (int i = 0; i < n; i++)//���
		{
			printf("\t������Ԫ��%d��", i + 1);
			scanf_s("%d", &a[rear%QUEUE_SIZE]);//���
			rear = (rear + 1) % QUEUE_SIZE;//rear����
		}
	}
	else
	{
		printf("----����\n");
	}
	//��ӡ��Ӳ�����ɺ����
	printf("\t��Ӻ����Ϊ:");
	for (int i = 0; i < QUEUE_SIZE; i++)
	{
		if (a[i] == NULL)
		{
			continue;
		}
		else
		{
			printf("  %d", a[i]);
		}
	}
	return rear;//���ֻ�ı�rear 
	putchar('\n');
}

//��ʼ������
void clrarQueue(int *a, int rear, int front)
{
	printf("----����ʼǰ��ʼ������----\n");
	for (int i = 0; i < QUEUE_SIZE; i++)
	{
		a[i] = NULL;
	}
	front = rear = 0;
	putchar('\n');
}

//����
int deleteQueue(int *a, int rear, int front)
{
	printf("\n----���Ӳ���----\n");
	int n;
	printf("\t���������Ԫ�ظ�����");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("\t%d����  ", a[front]);
		a[front] = NULL;
		front++;
	}
	
	//��ӡ������ɺ�Ķ���
	printf("\n\t���Ӻ����Ϊ��");
	for (int i = 0; i < QUEUE_SIZE; i++)
	{
		if (a[i] == NULL)
		{
			continue;
		}
		printf("  %d", a[i]);
	}
	putchar('\n');
	return front;
}



//�ж϶����Ƿ�Ϊ�գ�����Ϊ�գ�������г���
void judgeVoid(int *a, int rear, int front)
{
	printf("\n----�ж϶����Ƿ�Ϊ��----\n");
	if (rear == front)
	{
		printf("\t����Ϊ��\n");
	}
	else
	{
		int length;
		length = countLength(a, rear, front);
		printf("\t���в�Ϊ��\n\t���г���Ϊ��%d\n",length);
		
	}

}

int main()
{
	printf("----������%d���ռ�,�ɴ���%d��Ԫ��----\n",QUEUE_SIZE,QUEUE_SIZE-1);
	int a[QUEUE_SIZE] = { NULL };
	Queue *p = (Queue*)malloc(sizeof(Queue));
	p->front = p->rear = 0;

	putchar('\n');
	//��ʼ������
	clrarQueue(a, p->rear, p->front);
	p->front = p->rear = 0;

	
	//���
	p->rear = enterQueue(a, p->rear, p->front);
	printf("\n");

	//���Ӳ���
	p->front = deleteQueue(a, p->rear, p->front);
	

	//�ж϶����Ƿ�Ϊ�գ�����Ϊ�գ�������г���
	judgeVoid(a,p->rear,p->front);

	return 0;
}
