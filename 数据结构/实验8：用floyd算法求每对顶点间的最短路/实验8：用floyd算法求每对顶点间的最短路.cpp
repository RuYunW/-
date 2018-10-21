/*用floyd算法求每对顶点间的最短路*/
#include<stdio.h>
#include<stdlib.h>
#define N 4

//赋值函数
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

//求最短路径函数,k为开放点
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
	printf("如果没有路用无穷（32767）表示\n");
	printf("初始路径为：\n");
	print(a);
	putchar('\n');
	int dist1[N][N],dist2[N][N],dist3[N][N],dist4[N][N];
	//1
	assignment(a, dist1);//给N赋值
	min(a, dist1, 1);
	printf("开放第一个节点的dist1为：\n");
	print(dist1);
	putchar('\n');
	//2
	assignment(dist1, dist2);
	min(dist1, dist2, 2);
	printf("开放第二个节点的dist2为：\n");
	print(dist2);
	putchar('\n');
	//3
	assignment(dist2, dist3);
	min(dist2, dist3, 3);
	printf("开放第三个节点的dist3为：\n");
	print(dist3);
	putchar('\n');
	//4
	assignment(dist3, dist4);
	min(dist3, dist4, 4);
	printf("开放第四个节点的dist4为：\n");
	print(dist4);
	putchar('\n');

	
	return 0;
}