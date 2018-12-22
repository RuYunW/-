/*
	1������һ��˳�������n��Ԫ�ز��������
	2���������Ա��е����Ԫ�ز��������
	3�������Ա�ĵ�i��Ԫ��ǰ����һ��������x����
	4��ɾ�����Ա��еĵ�j��Ԫ�أ���
	5�������Ա��е�Ԫ�ذ��������У���
   *6�������Ա��е�Ԫ�ؾ͵�����ֻ������һ���ݴ浥Ԫ������
*/

#include<stdio.h>
#define N 10

//����������
void Quick_sort(int a[], int left, int right)
{
	int i = left, j = right;
	int temp;
	int pivot;//��׼��
	
	pivot = a[(left+right) / 2];  //��׼��λ�����м�

	while (i <= j)
	{
		//�������ҵ����ڵ��ڻ�׼���Ԫ��
		while (a[i] < pivot)
		{
			i++;
		}
		//���ҵ����ҵ�С�ڵ��ڻ�׼���Ԫ��
		while (a[j] > pivot)
		{
			j--;
		}
		//���i<=j���򻥻�
		if (i <= j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	//�����ݹ�
	if (left < j)
	{
		Quick_sort(a, left, j);
	}
	if (i < right)
	{
		Quick_sort(a, i, right);
	}
}
//�����ֵ����
int Max(int a[])
{
	int max, i;
	max = a[0];

	for (i = 0; i < 10; i++)
	{
		if (a[i] >= max)
		{
			max = a[i];
		}
	}
	return max;
}
int main()
{
	int a[N];
	int i;

	//a��ֵ
	printf("������%d����:\n",N);
	for (i = 0; i < N; i++)
	{
		printf("�������%d����:\n", i + 1);
		scanf_s("%d", &a[i]);
	}

	//���a
	printf("--------------------\n");
	printf("\t��%d�����ǣ�",N);
	for (i = 0; i < N; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n--------------------\n");

	int length;
	length = sizeof(a) / sizeof (a[0]);

	//ԭ������
	int t;
	for (i = 0; i < length / 2; i++)
	{
		t = a[i];
		a[i] = a[N-1 - i];
		a[N-1 - i] = t;
	}
	//����������
	printf("\t�������Ϊ��");
	for (i = 0; i < N; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n--------------------\n");

	//�����Ԫ��
		int m;
		m = Max(a);
		printf("\t�������%d��", m);
		printf("\n--------------------\n");

	//��������
	Quick_sort(a, 0, length - 1);
	//���������
	printf("\t�����Ľ���ǣ�\n");
	for (i = 0; i < length; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n--------------------\n");
	
	//ɾ����j��Ԫ��
	int j;
	printf("\tɾ����j��Ԫ�أ�������j��");
	scanf_s("%d", &j);
	for (j; j < N; j++)
	{
		a[j-1] = a[j];
	}
	for (i = 0; i < N-1 ; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n--------------------\n");

	//�ڵ�iԪ��ǰ����x
	printf("\t�ڵ�i��Ԫ��ǰ����������x\n������i��");
	scanf_s("%d", &i);
	printf("������x��");
	
	int x;
	scanf_s("%d", &x);
	printf("\n--------------------\n");
	j = i;
	//˳�����
	for (i=0; i < N-j; i++)
	{
		a[N - 1 - i] = a[N - 2 - i];

	}
	a[j-1] = x;
	printf("\t�������Ϊ��");
	for (i = 0; i < N; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
	return 0;
}

