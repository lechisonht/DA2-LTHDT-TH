#pragma once
#include<conio.h>
#include <stdlib.h>
#include <time.h>
class item
{
public:
	int x, y;
	int l;//loai item : 1 x2: 2 x0.5: 3 tuong
	int pl; //vua cham nguoi choi 1 hoac 2
	void reset(int n, int m);
	item(int n,int m );
	~item();
};

