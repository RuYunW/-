#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Graduate
{
private:
	char name[10];//����
	char number[12];//ѧ��
	int score;//��ѧ�ɼ�
	char research_field[10];//�о�����
	char teacher[10];//ָ����ʦ
public:
	Graduate();//�޲ι��캯��
	Graduate(const Graduate &per);//�������캯��
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
		cout << "������ѧ���ɼ���";
		cin >> score;
	}
	void Print();          //��ӡ����
	Graduate &operator=(const Graduate & g);//�Ⱥŵ����غ���
	friend char ScoreRank(Graduate g);//��Ԫ����������ѧ�ɼ��ȼ�
	friend float AveScore(Graduate * a, int length);//�������о������ƽ����
};