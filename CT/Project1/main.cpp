#include"pBall.h"
#include"pPaddle.h"
#include"gameManager.h"
int main()
{
	int i;
	cout << "GAME BONG BAN.\n1. NewGame.\n2. Load.\n"; cin >> i;
	if(i==1)
	{
		system("cls");
		gameManager Game(24, 25);
		Game.Run();
		return 0; 
	}
	else
	{
		string s;
		cout << "Nhap ten: "; cin >> s;
		system("cls");
		gameManager Game(s, 24, 25);
		Game.Run();
		return 0;
	}
}