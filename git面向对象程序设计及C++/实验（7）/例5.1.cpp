//exm 5.1
#include<iostream>
using namespace std;
class A
{
public:
	A()
	{
		cout << "����A�Ķ���" << endl;
	}
	~A()
	{
		cout << "����A�Ķ���" << endl;
	}
};
class B
{
public:
	B()
	{
		cout << "����B�Ķ���" << endl;
	}
	~B()
	{
		cout << "����B�Ķ���" << endl;
	}
protected:
	A a;
};

int main()
{
	B obj;
	return 0;
}
