/*ʵ��4��ǰ���������һ�ö�����*/
/*
1��	�õݹ��㷨���ɸö�������
2��	���ǰ�����򡢺�������ı������У�
3��	����������н�������

2018��4��18��
*/
#include<iostream>
#include<stdlib.h>
#include<string>

#define NULLKET '#'

//�������ڵ�
typedef struct tnode
{
	char data;
	struct tnode *lchild, *rchild;
}bitree, *bitlink;

//��������������
bitlink preCreatTree(bitlink &root)
{
	char ch;
	scanf_s("%c", &ch);

	if (ch == NULLKET)//NULLKEY=#
	{
		root = NULL;
		return(root);//���ؿ�ָ�룬�ص���һ��δ������ĵݹ麯��
	}
	else //�ӽڵ㲻Ϊ�գ��õݹ��㷨�����ڵ�
	{
		root = (bitree*)malloc(sizeof(tnode));  //�����½ڵ�
		root->data = ch;  //Ϊ�ڵ㸳ֵ
		//�ݹ鴴���ڵ�
		preCreatTree(root->lchild);
		preCreatTree(root->rchild);
		return(root);//��㷵���������ڵ�ָ�룬ֱ�����շ��������ڵ�
	}
}

//�����������������
void preorderTraversal(bitlink root)
{
	if (root == NULL)
		return;//���û�ж��ӣ����ؿգ��ص���һ��δ������ĵݹ麯��
	else
	{
		//�����ǰ�ڵ���ֵ
		printf("%c ", root->data);
		//�ݹ����������������
		preorderTraversal(root->lchild);
		preorderTraversal(root->rchild);
	}
}

//�����������������
void inorderTraversal(bitlink &root)
{
	if (root == NULL)
		return;
	else
	{
		inorderTraversal(root->lchild);
		printf("%c ", root->data);
		inorderTraversal(root->rchild);
	}
}

//�����������������
void postorderTraversal(bitlink &root)
{
	if (root == NULL)
		return;
	else
	{
		postorderTraversal(root->lchild);
		postorderTraversal(root->rchild);
		printf("%c ", root->data);
	}
}

//����������ڵ��������
int nodeNumber(bitlink &root)
{
	int n = 0;
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		n = nodeNumber(root->lchild) + nodeNumber(root->rchild) + 1;

	}
	return n;
}

int main()
{
	//ָ����������������ָ��
	bitlink root;

	//����������
	printf("������ǰ�򴴽�����\n");
	root = preCreatTree(root);//�õ�ָ�����������ڵ��ָ��

	//�������������
	printf("�ö���������������Ϊ��\n");
	preorderTraversal(root);
	printf("\n");
	//��ʱroot��Ȼָ�����������ڵ�

	//�������������
	printf("�ö���������������Ϊ��\n");
	inorderTraversal(root);
	printf("\n");
	
	//�������������
	printf("�ö���������������Ϊ��\n");
	postorderTraversal(root);
	printf("\n");

	//����������н�����
	int n = 0;
	n = nodeNumber(root);
	printf("�ö������ڵ����Ϊ%d\n", n);

	return 0;
}

