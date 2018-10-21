/*创建哈夫曼树*/
/*
1、从键盘输入n, 以及n个字符的概率。
2、用顺序存储
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
	int count = N;//当前总节点数
	
	for (k = 0; k < count; k++)
	{
		//寻找最小值和次小值
		for (i = 0; i < count; i++)//找最小值
		{
			if ((!a[i].parent) && (a[i].power <= min1))
			{
				min1 = a[i].power;
				mini = i;
			}
		}
		
		for (j = 0; j < count; j++)//找次小值
		{
			if ((!a[j].parent) && (a[j].power <= min2) && (a[j].power != min1))
			{
				min2 = a[j].power;
				minj = j;
			}
		}
		//叶子结点赋值父亲
		a[mini].parent = count+1;
		a[minj].parent = count+1;
		//新节点赋值power和儿子
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
	for (i = 0; i < 2 * N - 1; i++)//打印结果
	{
		printf("第%d个节点的权是：%d，Parent = %d，Lchild = %d，Rchild = %d\n", i + 1, a[i].power, a[i].parent, a[i].Lchild, a[i].Rchild);
	}
}
int main()
{
	printf("\n----该程序用于创建%d个叶子节点的哈夫曼树----\n\n", N);

	HuffmanTreeNode a[2 * N-1];
	//初始化
	for (int i = 0; i < 2 * N - 1; i++)
	{
		a[i].parent = a[i].power = a[i].Lchild = a[i].Rchild = 0;
	}
	printf("请输入%d个叶子结点的权值：\n",N);
	//录入数据
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &a[i].power);
	}
	minPower(a);
	return 0;
}