#include <iostream>
using namespace std;

class Vectors
{
	float x_axis;
	float y_axis;
public:
	Vectors();
	Vectors(float x, float y);
	void Print();
	Vectors operator + (Vectors a);//��Ա����ʵ�����������+
	friend Vectors operator - (const Vectors &a, const Vectors &b);//��Ԫ����ʵ�����������-
};
