#include<stdio.h>
int main()
{
	//��ȡ����
	int n;
	printf("��ó�������ʵ�ֶ��׻���������ʽ�ļ����\n");
	printf("����������ʽ������2��3����\n");
	scanf_s("%d", &n);

	
	//��������ʽ
	if (n == 2)
	{
		//��ȡ����ʽ
		int a[2][2];
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				printf("�������%d�е�%d��Ԫ��:\n", i + 1, j + 1);
				scanf_s("%d", &a[i][j]);
			}
		}

		int result;
		result = a[0][0] * a[1][1] - a[0][1] * a[1][0];
		printf("�ö�������ʽ���Ϊ��%d\n", result);
	}

	//��������ʽ
	if (n == 3)
	{
		//��ȡ��������ʽ
		int a[3][3];
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				printf("�������%d�е�%d��Ԫ��:\n", i + 1, j + 1);
				scanf_s("%d", &a[i][j]);
			}
		}
		
		int result;
		result = a[0][0]*a[1][1]*a[2][2] + a[0][1]*a[1][2]*a[2][0] + a[0][2]*a[1][0]*a[2][1] - a[0][2]*a[1][1]*a[2][0] - a[0][0]*a[1][2]*a[2][1] - a[0][1]*a[1][0]*a[2][2];
		printf("����������ʽ���Ϊ��%d\n", result);
	}
	return 0;
}