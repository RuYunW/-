#include<stdio.h>
#define N 4

int main()
{
	printf("-----该函数用于解决%d元一次函数,函数阶数可在define中修改-----\n", N);
	float a[N][N] , b[N] ;//无解

	//测试数据：
	//float a[N][N] = { 2,1,8,3,2,-3,0,7,3,-2,5,8,1,0,3,2 }, b[N] = { 7,-5,0,0 };//无解
	//float a[N][N] = { 1,-1,3,-4,3,-3,5,-4,2,-2,3,-2,3,-3,4,-2 }, b[N] = { 3,1,0,-1 };//无穷解
	//float a[N][N] = { 1,1,1,1,2,-1,4,1,1,3,-2,-1,1,1,2,-4 }, b[N] = { 10,16,-3,-7 };//唯一解
	int i, j, k;
	
	/*for (i = 0; i < N; i++)//获取系数a
	{
		for (j = 0; j < N; j++)
		{
			printf("请输入a%d%d：", i + 1, j + 1);
			scanf_s("%f", &a[i][j]);
		}
	}
	for (i = 0; i < N; i++)//获取b
	{
		printf("请输入b%d：", i + 1);
		scanf_s("%f", &b[i]);
	}
	*/
	printf("\n方程原始数据如下：\n");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%.1f    ", a[i][j]);
		}
		printf("%.1f", b[i]);
		printf("\n");
	}


	float n;//n储存分母
	
	for (i = 0; i < N - 1; i++)//N-1级阶梯 循环N-1次
	{
		for (j = 1 + i; j < N; j++)//j = 行
		{
			if (a[i][i])//a[i][i] != 0
			{
				n = -(a[j][i] / a[i][i]);//分数
				b[j] += n * b[i];
				for (k = i; k < N; k++)//k = 列
				{
					a[j][k] += n * a[i][k];
				}
			}
			else
			{
				continue;//不知道怎么办，先略过
			}
		}
	}

	
	printf("\n方程结果为：\n");

	int r = N;//方程的秩
	float sum = 0,flag = 1;
	for (i = 0; i < N; i++)//行
	{
		sum = 0;
		for (j = 0; j < N; j++)//列
		{
			sum += a[i][j];//计算各行是否非零行
		}
		if (sum == 0)
		{
			r--;
		}
		if (sum == 0 && b[i] != 0)//if sum = 0
		{
			flag = 0;
			printf("方程无解\n\n");
		}
	}

	if (flag)//方程有解
	{
		if (r == N)//有唯一解
		{
			printf("有唯一解\n\n");
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
		else//有无穷解
		{
			printf("有无穷解，但我不会解\n");
		}
	}
	printf("方程变换后数据如下：\n");
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
