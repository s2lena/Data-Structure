#include "Recursion.h"

int SumOfSquares(int n)
{
	if (n <= 1)
		return n;
	return n * n + SumOfSquares(n - 1);
}

int GCD(int a, int b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	if (a == b)
		return a;
	if (a > b)
		return GCD(a - b, b);
	return GCD(a, b - a);
}

int FIB(int n)
{
	if (n <= 1)
		return n;
	return FIB(n - 1) + FIB(n - 2);
}
