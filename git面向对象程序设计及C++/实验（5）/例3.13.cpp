//example 3.13
#pragma warning(disable:4996)//安全错误
#include<string>
#include<iostream>
using namespace std;

class Student
{
	char* specialty;

public:
	Student(const char *pSpec = 0);//指向computer的函数
	Student(const Student &r);//深拷贝函数
	~Student();
	void Show();

};

Student::Student(const char *pSpec)
{
	if (pSpec)//computer
	{
		specialty = new char[strlen(pSpec) + 1];//动态分配
		strcpy(specialty, pSpec);//specialty->computer直接copy指针
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
		strcpy(specialty, r.specialty);//copy指针内容
	}
	else specialty = 0;
}
Student::~Student()
{
	if (specialty)
	{
		delete[]specialty;//释放
	}
}
void Student::Show()
{
	cout << "specialty=" << specialty << '\n';
}

int main()
{
	Student zhang("computer");
	Student wang(zhang);//拷贝vh的内容到wh
	zhang.Show();
	wang.Show();
	return 0;
}
