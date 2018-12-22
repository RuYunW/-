#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "graduate.h"
using namespace std;

Graduate::Graduate()//无参构造函数
{
	strcpy(name, "00");
	strcpy(number, "00");
	strcpy(research_field, "00");
	strcpy(teacher, "00");
	score = 0;
}
Graduate::Graduate(const Graduate &per) //拷贝构造函数
{

	strcpy(name, per.name);
	strcpy(number, per.number);
	strcpy(research_field, per.research_field);
	strcpy(teacher, per.teacher);
	score = per.score;
}
void Graduate::SetAll()
{
	cout << "请输入姓名：";
	cin >> name;
	cout << "请输入学号：";
	cin >> number;
	cout << "请输入研究领域：";
	cin >> research_field;
	cout << "请输入指导教师：";
	cin >> teacher;
	cout << "请输入入学成绩：";
	cin >> score;
}
void Graduate::Print()
{
	cout << "姓  名:" << name << endl;
	cout << "学  号:" << number << endl;
	cout << "入学成绩:" << score << endl;
	cout << "研究领域:" << research_field << endl;
	cout << "指导教师:" << teacher << endl;
}
Graduate & Graduate::operator=(const Graduate & g)//对=的重载函数
{
	strcpy(name, g.name);
	strcpy(number, g.number);
	strcpy(research_field, g.research_field);
	strcpy(teacher, g.teacher);
	score = g.score;
	return *this;
}
char ScoreRank(Graduate g)//作为友元函数计算入学成绩等级
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
	cout << length << "个学生的平均成绩为：" << ave << endl;
	return ave;
}