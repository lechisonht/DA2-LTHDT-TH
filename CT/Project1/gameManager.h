#pragma once
#include"iostream"
#include"time.h"
#include"conio.h"
using namespace std;
#include"pBall.h"
#include"pPaddle.h"
#include"item.h"
#include<fstream>
using namespace std;
class gameManager
{
private:
	int width, height;//WIDTH: CHIEU` DAI`---HEIGHT: DO. CAO
	int score;//DIEM SO CUA NGUOI` CHOI
	char right1, left1;//CAC BIEN LUU GIA TRI DE DIEU KHIEN TU BAN PHIM
	bool quit;//BIEN DIEU KIEN DE THOAT GAME
	pBall* ball;
	pPaddle* player;
	item* it;
public:
	gameManager(string s,int w,int h);
	gameManager(int w, int h);
	~gameManager();
	void ScoreUP(pPaddle* player);
	void Draw();
	void Input();
	void Logic();
	void Run();
	void Save();
};