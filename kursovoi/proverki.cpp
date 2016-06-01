#include <cstdio>
#include "proverki.h"

//процедура проверки хода
bool provk(int a, int b, int c, int d)
{
	if ((a + b) % 2 == 1)
		if (c - d == 1)
		{
			return true;
		}
	return false;
}

//разложение в основную клоду
bool provka(int a, int b, int c, int d)
{
	if (a == b)
		if (d - c == 1)
		{
			return true;
		}
	return false;
}

//c1
int pust(int a)
{
	if (a == 0)
		return a;
}