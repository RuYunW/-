#define _CRT_SECURE_NO_WARNINGS

//ѧ����Ķ���
#ifndef _STUDENT //��������
#define _STUDENT
#include<iostream>
#include<string>
using namespace std;
#define SIZE 80
class Student
{
	char *name;
	char ID[19];//���֤
	char number[10];//ѧ��
	char speciality[20];//רҵ
	int age;
	static int count;
public:
	Student();//�޲ι��캯��
	Student(char *na, char *id, char*num, char*spec, int ag);//���ι��캯��
	Student(const Student &per);//�������캯��
	~Student();
	char* GetName()const;//��ȡ����
	char*GetID();
	char *GetNumber();
	char*GetSpec();
	int GetAge()const;
	void Display()const;
	void Input();
	void Insert();
	void Delete();
	static int GetCount();
};
#endif