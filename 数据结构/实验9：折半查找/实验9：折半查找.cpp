/*�۰����
����һ�������У�����key, ���۰�����㷨���ң���������ҽ��*/
#include<stdio.h>
#include<stdlib.h>
#define N 10

//��ӡ�������
void print(int result)
{
	if (result) printf("\n���ҵ������ǵ�%d��\n\n", result);
	else printf("����ʧ��\n\n");
}

//���Һ���
int search(int *a, int key)
{
	int mid, low = 1, high = N;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == a[mid - 1]) return mid;//�ҵ���������ؽ��
		else if (key < a[mid - 1]) high = mid - 1;
		else low = mid + 1;
	}
	return 0;
}
void scan(int *a)
{
	printf("������%d��������Ϊ���ݿ�\n\n", N);
	for (int i = 0; i < N; i++)
	{
		printf("�������%d������",i+1);
		scanf_s("%d", &a[i]);
	}
	printf("\n\n");
}
int main()
{
	int key;
	int a[N];
	scan(a);
	printf("������ؼ���key��ֵ��");
	scanf_s("%d", &key);
	
	print(search(a, key));//��ӡ���ҽ��,���rearch����Ϊ��ţ����ӡ��ţ�����0�������ʧ��
	return 0;
}