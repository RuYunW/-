#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "graduate.h"
using namespace std;

Graduate::Graduate()//�޲ι��캯��
{
	strcpy(name, "00");
	strcpy(number, "00");
	strcpy(research_field, "00");
	strcpy(teacher, "00");
	score = 0;
}
Graduate::Graduate(const Graduate &per) //�������캯��
{

	strcpy(name, per.name);
	strcpy(number, per.number);
	strcpy(research_field, per.research_field);
	strcpy(teacher, per.teacher);
	score = per.score;
}
void Graduate::SetAll()
{
	cout << "������������";
	cin >> name;
	cout << "������ѧ�ţ�";
	cin >> number;
	cout << "�������о�����";
	cin >> research_field;
	cout << "������ָ����ʦ��";
	cin >> teacher;
	cout << "��������ѧ�ɼ���";
	cin >> score;
}
void Graduate::Print()
{
	cout << "��  ��:" << name << endl;
	cout << "ѧ  ��:" << number << endl;
	cout << "��ѧ�ɼ�:" << score << endl;
	cout << "�о�����:" << research_field << endl;
	cout << "ָ����ʦ:" << teacher << endl;
}
Graduate & Graduate::operator=(const Graduate & g)//��=�����غ���
{
	strcpy(name, g.name);
	strcpy(number, g.number);
	strcpy(research_field, g.research_field);
	strcpy(teacher, g.teacher);
	score = g.score;
	return *this;
}
char ScoreRank(Graduate g)//��Ϊ��Ԫ����������ѧ�ɼ��ȼ�
{
	int r;
	char rank;
	r = g.GetScore() / 10;
	switch (r)
	{
	case 10:
	case 9:
		rank = 'A';break;
	case 8:
		rank = 'B';break;
	case 7:
		rank = 'C';break;
	case 6:
		rank = 'D';break;
	default:
		rank = 'E';break;
	}
	return rank;
}
float AveScore(Graduate *a, int length)
{
	float ave = 0, sum = 0;
	for (int i = 0; i < length; i++)
		sum += a[i].GetScore();
	ave = sum / length;
	cout << length << "��ѧ����ƽ���ɼ�Ϊ��" << ave << endl;
	return ave;
}