//example 3.13
#pragma warning(disable:4996)//��ȫ����
#include<string>
#include<iostream>
using namespace std;

class Student
{
	char* specialty;

public:
	Student(const char *pSpec = 0);//ָ��computer�ĺ���
	Student(const Student &r);//�������
	~Student();
	void Show();

};

Student::Student(const char *pSpec)
{
	if (pSpec)//computer
	{
		specialty = new char[strlen(pSpec) + 1];//��̬����
		strcpy(specialty, pSpec);//specialty->computerֱ��copyָ��
	}
	else
	{
		specialty = 0;
	}
}
Student::Student(const Student &r)//->wh
{
	if (r.specialty)
	{
		specialty = new char[strlen(r.specialty) + 1];
		strcpy(specialty, r.specialty);//copyָ������
	}
	else specialty = 0;
}
Student::~Student()
{
	if (specialty)
	{
		delete[]specialty;//�ͷ�
	}
}
void Student::Show()
{
	cout << "specialty=" << specialty << '\n';
}

int main()
{
	Student zhang("computer");
	Student wang(zhang);//����vh�����ݵ�wh
	zhang.Show();
	wang.Show();
	return 0;
}
