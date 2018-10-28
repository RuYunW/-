#pragma warning(disable:4996)
#include<iostream>
#include<string>
using namespace std;
class Student
{
	int age;
	char *name;
public:
	Student(int m, const char*n)
	{
		age = m;
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	friend void disp(Student&);
	~Student()
	{
		cout << "delete it." << name << endl;
		delete[]name;
	}
};
void disp(Student &p)
{
	cout << "Student's name is " << p.name << ",age is " << p.age << endl;
}
int main()
{
	Student A(18, "wujd");
	Student B(19, "xwyu");
	disp(A);
	disp(B);
	return 0;
}