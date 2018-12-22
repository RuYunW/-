/*折半查找
给定一组数序列，输入key, 用折半查找算法查找，并输出查找结果*/
#include<stdio.h>
#include<stdlib.h>
#define N 10

//打印结果函数
void print(int result)
{
	if (result) printf("\n查找的数字是第%d个\n\n", result);
	else printf("查找失败\n\n");
}

//查找函数
int search(int *a, int key)
{
	int mid, low = 1, high = N;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == a[mid - 1]) return mid;//找到结果，返回结果
		else if (key < a[mid - 1]) high = mid - 1;
		else low = mid + 1;
	}
	return 0;
}
void scan(int *a)
{
	printf("请输入%d个数字作为数据库\n\n", N);
	for (int i = 0; i < N; i++)
	{
		printf("请输入第%d个数：",i+1);
		scanf_s("%d", &a[i]);
	}
	printf("\n\n");
}
int main()
{
	int key;
	int a[N];
	scan(a);
	printf("请输入关键字key的值：");
	scanf_s("%d", &key);
	
	print(search(a, key));//打印查找结果,如果rearch返回为序号，则打印序号，返回0，则查找失败
	return 0;
}