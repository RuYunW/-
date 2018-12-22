#include "vectors.h"

int main()
{
	Vectors A(1, 3), B(4, 2);
	Vectors C, D;
	C = A + B;
	C.Print();
	D = B - A;
	D.Print();
	return 0;
}