#include <iostream>
using namespace  std;
//------------------��child�ࡿ-----------------------------------
class Child             //1.����С���ѽڵ���
{
public:
	int childNo;         //��ǰС���ı��
	Child* leftchild;    //��¼С����������ھ�
	Child* rightchild;   //��¼С����������ھ�
public:
	Child(int id = 0) 	  //���캯��
	{
		childNo = id;
		leftchild = NULL;
		rightchild = NULL;
	}
};
//-------------------��Circle�ࡿ----------------------------------
class Circle               // ����ԲȦ��Ϸ��
{
public:
	int scale;             //��ǰ-���ڲ�����Ϸ������
	Child children[1000];  //���-������Ϸ��С������
public:
	Circle(int num = 1000) // ��Ĭ��ֵ���캯������ʼ��С���ڵ�
	{
		scale = num;
		for (int i = 0; i < num; i++)
			children[i] = Child(i);//No��ֵ
	};
	//�����ڵ��ѭ����������ȷ��ÿ��С���������ھ�
	void Build()
	{
		for (int i = 0; i < scale; i++)//108
		{
			if (i == 0)
				children[i].leftchild = &children[scale];
			else
				children[i].leftchild = &children[i - 1];
			children[i].rightchild = &children[(i + 1)%scale];
		}
	}
	//��Ϸ���к������ӵ�ǰ�ڵ�˳ʱ��ѭ����ʼ��num����
	void Run(int T)// T==8
	{
		int k;
		cout << "�ӵڼ���С����ʼ��Ϸ����������(k<109)��" << endl;
		cin >> k;
		int count = 0;
		Child* current = &children[k];
		Child* p;//����ָ��
		while (scale > 1)
		{
			count += 1;
			if (count == T)//T==8   С���˳���ǰԲȦ
			{
				scale = scale - 1;
				p = current->rightchild;
				current->leftchild->rightchild = current->rightchild;
				current->rightchild->leftchild = current->leftchild;
				current = p;
				count = 0;
			}
			else  //Count the next������������Ϸ	            		
			{
				current = current->rightchild;
			}
		}
		cout << "The last child id is " << current->childNo << endl;
	}
};
//----------------------------������----------------------------------
int main()
{
	Circle nodes(108); // ԲȦ������108���ڵ����С����
	nodes.Build();
	nodes.Run(8);      // ��ʼѭ����������8������Ϸ��������Ļ�ʤ��
	return 0;
}