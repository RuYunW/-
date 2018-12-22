#include <iostream>
#include "vectors.h"
using namespace std;

Vectors::Vectors()
{
	x_axis = 0;
	y_axis = 0;
}
Vectors::Vectors(float x, float y)
{
	x_axis = x;
	y_axis = y;
}
void Vectors::Print()
{
	cout << "x_axis= " << x_axis << "    " << endl;
	cout << "y_axis= " << y_axis << endl;
}
Vectors Vectors::operator + (Vectors a)//成员函数实现重载运算符+
{
	Vectors t;
	t.x_axis = x_axis + a.x_axis;
	t.y_axis = y_axis + a.y_axis;
	return t;
}

Vectors operator - (const Vectors &a, const Vectors &b)//友元函数实现重载运算符-
{
	Vectors t;
	t.x_axis = a.x_axis - b.x_axis;
	t.y_axis = a.y_axis - b.y_axis;
	return t;
}
