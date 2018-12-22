#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "graduate.h"
using namespace std;

int main()
{
	Graduate wang,zhang;
	wang.SetAll();
	zhang = wang;
	wang.Print();
	zhang.Print();
	cout << ScoreRank(wang) << endl;
	Graduate Stu[5];
	int len = sizeof(Stu) / sizeof(Graduate);
	for (int i = 0; i < len; i++)
		Stu[i].SetScore();
	AveScore(Stu,len);
	return 0;
}