/*��floyd�㷨��ÿ�Զ��������·*/
#include<stdio.h>
#include<stdlib.h>
#define N 4

//��ֵ����
void assignment(int a[][4],int b[][4])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0;j < N; j++)
		{
			b[i][j] = a[i][j];
		}
	}
}
void print(int a[][4])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

//�����·������,kΪ���ŵ�
void min(int a[][4],int b[][4],int k)
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (a[i][j] > a[i][k-1] + a[k-1][j])
			{
				b[i][j] = a[j][k-1] + a[k-1][j];
			}
		}
	}
}

int main()
{
	int i, j, k;
	int a[N][N] = {0,10,32767,32767,15,0,6,32767,3,1000,0,4,32767,8,2,0};
	printf("���û��·�����32767����ʾ\n");
	printf("��ʼ·��Ϊ��\n");
	print(a);
	putchar('\n');
	int dist1[N][N],dist2[N][N],dist3[N][N],dist4[N][N];
	//1
	assignment(a, dist1);//��N��ֵ
	min(a, dist1, 1);
	printf("���ŵ�һ���ڵ��dist1Ϊ��\n");
	print(dist1);
	putchar('\n');
	//2
	assignment(dist1, dist2);
	min(dist1, dist2, 2);
	printf("���ŵڶ����ڵ��dist2Ϊ��\n");
	print(dist2);
	putchar('\n');
	//3
	assignment(dist2, dist3);
	min(dist2, dist3, 3);
	printf("���ŵ������ڵ��dist3Ϊ��\n");
	print(dist3);
	putchar('\n');
	//4
	assignment(dist3, dist4);
	min(dist3, dist4, 4);
	printf("���ŵ��ĸ��ڵ��dist4Ϊ��\n");
	print(dist4);
	putchar('\n');

	
	return 0;
}