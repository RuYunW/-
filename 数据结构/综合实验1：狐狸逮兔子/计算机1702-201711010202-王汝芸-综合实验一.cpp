#include<stdio.h>
int main()
{
	int a[10] = { 1,1,1,1,1,1,1,1,1,1 };

	int i, d, t, n;
	printf("���������Ӷ�����<=10��:\n");
	scanf_s("%d", &n);
	printf("����������������:\n");
	scanf_s("%d", &t);

	for (i = 1; i<t; i++)  //i : time
	{
		d = (((i*(i + 1)) / 2) - 1) % n;     //����d=((i*(i+1))/2)%10
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
	if (sum == 0) { printf("�����޴��ɲ�\n"); }
	else
	{
		printf("���Ӳ���Ķ�Ϊ��\n");
		for (i = 0; i < n; i++)
		{
			if (a[i] == 1)printf("%d  ", i + 1);
		}
		putchar('\n');
	}


	return 0;
}
