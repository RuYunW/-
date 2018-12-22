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
	Vectors operator + (Vectors a);//成员函数实现重载运算符+
	friend Vectors operator - (const Vectors &a, const Vectors &b);//友元函数实现重载运算符-
};
