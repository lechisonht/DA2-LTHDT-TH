#include "item.h"
void item::reset(int n, int m) {
	x = rand() % n + 2;
	y = rand() % m + 4;
	l = rand() % 3 + 1;
}
item::item(int n,int m)
{
	x = rand() % n + 2;
	y = rand() % m + 4;
	l = rand() % 3 + 1;
}
item::item(int n, int m, int k)
{
	x = n;
	y = m;
	l = k;
}
item::~item()
{
}