#include<stdio.h>
#define N 4

int main()
{
	printf("-----�ú������ڽ��%dԪһ�κ���,������������define���޸�-----\n", N);
	float a[N][N] , b[N] ;//�޽�

	//�������ݣ�
	//float a[N][N] = { 2,1,8,3,2,-3,0,7,3,-2,5,8,1,0,3,2 }, b[N] = { 7,-5,0,0 };//�޽�
	//float a[N][N] = { 1,-1,3,-4,3,-3,5,-4,2,-2,3,-2,3,-3,4,-2 }, b[N] = { 3,1,0,-1 };//�����
	//float a[N][N] = { 1,1,1,1,2,-1,4,1,1,3,-2,-1,1,1,2,-4 }, b[N] = { 10,16,-3,-7 };//Ψһ��
	int i, j, k;
	
	/*for (i = 0; i < N; i++)//��ȡϵ��a
	{
		for (j = 0; j < N; j++)
		{
			printf("������a%d%d��", i + 1, j + 1);
			scanf_s("%f", &a[i][j]);
		}
	}
	for (i = 0; i < N; i++)//��ȡb
	{
		printf("������b%d��", i + 1);
		scanf_s("%f", &b[i]);
	}
	*/
	printf("\n����ԭʼ�������£�\n");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%.1f    ", a[i][j]);
		}
		printf("%.1f", b[i]);
		printf("\n");
	}


	float n;//n�����ĸ
	
	for (i = 0; i < N - 1; i++)//N-1������ ѭ��N-1��
	{
		for (j = 1 + i; j < N; j++)//j = ��
		{
			if (a[i][i])//a[i][i] != 0
			{
				n = -(a[j][i] / a[i][i]);//����
				b[j] += n * b[i];
				for (k = i; k < N; k++)//k = ��
				{
					a[j][k] += n * a[i][k];
				}
			}
			else
			{
				continue;//��֪����ô�죬���Թ�
			}
		}
	}

	
	printf("\n���̽��Ϊ��\n");

	int r = N;//���̵���
	float sum = 0,flag = 1;
	for (i = 0; i < N; i++)//��
	{
		sum = 0;
		for (j = 0; j < N; j++)//��
		{
			sum += a[i][j];//��������Ƿ������
		}
		if (sum == 0)
		{
			r--;
		}
		if (sum == 0 && b[i] != 0)//if sum = 0
		{
			flag = 0;
			printf("�����޽�\n\n");
		}
	}

	if (flag)//�����н�
	{
		if (r == N)//��Ψһ��
		{
			printf("��Ψһ��\n\n");
			for (i = 0; i < N - 1; i++)
			{
				for (j = 0; j < N - i-1; j++)
				{
					n = -(a[j][N-i-1] / a[N-i-1][N-i-1]);
					a[j][N - i - 1] = a[j][N - i - 1] + n * a[N - i - 1][N - i - 1];
					b[j] = b[j] + n * b[N-i-1];
				}

			}
			for (i = 0; i < N; i++)
			{
				printf("x%d = %.2f\n", i + 1, b[i]/a[i][i]);
			}
			putchar('\n');
		}
		else//�������
		{
			printf("������⣬���Ҳ����\n");
		}
	}
	printf("���̱任���������£�\n");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%.1f    ", a[i][j]);
		}
		printf("%.1f", b[i]);
		printf("\n");
	}
	return 0;
}
