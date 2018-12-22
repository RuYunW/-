#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Graduate
{
private:
	char name[10];//姓名
	char number[12];//学号
	int score;//入学成绩
	char research_field[10];//研究领域
	char teacher[10];//指导教师
public:
	Graduate();//无参构造函数
	Graduate(const Graduate &per);//拷贝构造函数
	void SetAll();
	char* GetName()
	{ 
		return name; 
	}
	char* GetNumber()
	{
		return number;
	}
	char* GetResearchField()
	{
		return research_field;
	}
	char* GetTeacher()
	{
		return teacher;
	}
	int GetScore()
	{
		return score;
	}
	void SetScore()
	{
		cout << "请输入学生成绩：";
		cin >> score;
	}
	void Print();          //打印函数
	Graduate &operator=(const Graduate & g);//等号的重载函数
	friend char ScoreRank(Graduate g);//友元函数计算入学成绩等级
	friend float AveScore(Graduate * a, int length);//计算多个研究生类的平均分
};