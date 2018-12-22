/*������������*/
/*
1���Ӽ�������n, �Լ�n���ַ��ĸ��ʡ�
2����˳��洢
*/
#include<stdio.h>
#include<stdlib.h>
#define N 8

typedef struct HuffmanTreeNode
{
	int power;
	int parent;
	int Lchild;
	int Rchild;
}HuffTreeNode;

void minPower(HuffmanTreeNode * a)
{
	int min1 = 100, min2 =100;
	int i, j, k;
	int mini,minj;
	int count = N;//��ǰ�ܽڵ���
	
	for (k = 0; k < count; k++)
	{
		//Ѱ����Сֵ�ʹ�Сֵ
		for (i = 0; i < count; i++)//����Сֵ
		{
			if ((!a[i].parent) && (a[i].power <= min1))
			{
				min1 = a[i].power;
				mini = i;
			}
		}
		
		for (j = 0; j < count; j++)//�Ҵ�Сֵ
		{
			if ((!a[j].parent) && (a[j].power <= min2) && (a[j].power != min1))
			{
				min2 = a[j].power;
				minj = j;
			}
		}
		//Ҷ�ӽ�㸳ֵ����
		a[mini].parent = count+1;
		a[minj].parent = count+1;
		//�½ڵ㸳ֵpower�Ͷ���
		a[count].power = min1 + min2;
		a[count].Lchild = mini + 1;
		a[count].Rchild = minj + 1;
		count++;
		min1 = 100;min2 = 100;
		if (count == 2 * N - 1)
		{
			break;
		}
	}
	for (i = 0; i < 2 * N - 1; i++)//��ӡ���
	{
		printf("��%d���ڵ��Ȩ�ǣ�%d��Parent = %d��Lchild = %d��Rchild = %d\n", i + 1, a[i].power, a[i].parent, a[i].Lchild, a[i].Rchild);
	}
}
int main()
{
	printf("\n----�ó������ڴ���%d��Ҷ�ӽڵ�Ĺ�������----\n\n", N);

	HuffmanTreeNode a[2 * N-1];
	//��ʼ��
	for (int i = 0; i < 2 * N - 1; i++)
	{
		a[i].parent = a[i].power = a[i].Lchild = a[i].Rchild = 0;
	}
	printf("������%d��Ҷ�ӽ���Ȩֵ��\n",N);
	//¼������
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &a[i].power);
	}
	minPower(a);
	return 0;
}