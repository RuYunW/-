#include<stdio.h>
int main()
{
	//获取阶数
	int n;
	printf("☆该程序用来实现二阶或三阶行列式的计算☆\n");
	printf("请输入行列式阶数（2或3）：\n");
	scanf_s("%d", &n);

	
	//二阶行列式
	if (n == 2)
	{
		//获取行列式
		int a[2][2];
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				printf("请输入第%d行第%d个元素:\n", i + 1, j + 1);
				scanf_s("%d", &a[i][j]);
			}
		}

		int result;
		result = a[0][0] * a[1][1] - a[0][1] * a[1][0];
		printf("该二阶行列式结果为：%d\n", result);
	}

	//三阶行列式
	if (n == 3)
	{
		//获取三阶行列式
		int a[3][3];
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				printf("请输入第%d行第%d个元素:\n", i + 1, j + 1);
				scanf_s("%d", &a[i][j]);
			}
		}
		
		int result;
		result = a[0][0]*a[1][1]*a[2][2] + a[0][1]*a[1][2]*a[2][0] + a[0][2]*a[1][0]*a[2][1] - a[0][2]*a[1][1]*a[2][0] - a[0][0]*a[1][2]*a[2][1] - a[0][1]*a[1][0]*a[2][2];
		printf("该三阶行列式结果为：%d\n", result);
	}
	return 0;
}