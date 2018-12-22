#include<stdio.h>
int main()
{
	int a[10] = { 1,1,1,1,1,1,1,1,1,1 };

	int i, d, t, n;
	printf("请输入兔子洞数（<=10）:\n");
	scanf_s("%d", &n);
	printf("请输入狐狸进出次数:\n");
	scanf_s("%d", &t);

	for (i = 1; i<t; i++)  //i : time
	{
		d = (((i*(i + 1)) / 2) - 1) % n;     //洞数d=((i*(i+1))/2)%10
		if (a[d] == 0)
		{
			continue;
		}
		a[d] = 0;
	}
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		sum = sum + a[i];
	}
	if (sum == 0) { printf("兔子无处可藏\n"); }
	else
	{
		printf("兔子藏身的洞为：\n");
		for (i = 0; i < n; i++)
		{
			if (a[i] == 1)printf("%d  ", i + 1);
		}
		putchar('\n');
	}


	return 0;
}
