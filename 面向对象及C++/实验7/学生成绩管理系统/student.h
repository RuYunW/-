#define _CRT_SECURE_NO_WARNINGS

//学生类的定义
#ifndef _STUDENT //条件编译
#define _STUDENT
#include<iostream>
#include<string>
using namespace std;
#define SIZE 80
class Student
{
	char *name;
	char ID[19];//身份证
	char number[10];//学号
	char speciality[20];//专业
	int age;
	static int count;
public:
	Student();//无参构造函数
	Student(char *na, char *id, char*num, char*spec, int ag);//带参构造函数
	Student(const Student &per);//拷贝构造函数
	~Student();
	char* GetName()const;//提取姓名
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