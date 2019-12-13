#include "gameManager.h"
//KHOI TAO SAN CHOI TRUYEN` VAO` DO DAI VA` CHIEU RONG
gameManager::gameManager(int w, int h)//W: CHIEU` DAI`---H: CHIEU` RONG.
{
	srand(time(NULL));
	quit = false;//DIEU KIEN DE THOAT GAME
	right1 = 'd';//THIET LAP CAC PHIM DIEU KHIEN
	left1 = 'a';
	score = 0;//BIEN' LUU DIEM SO CUA 2 NGUOI CHOI 
	width = w; height = h;
	ball = new pBall(w / 2, h / 2);//CHO VI TRI QUA BONG O CHINH GIUA SAN CHOI
	player = new pPaddle(w / 2 - 2, h - 2);//GAN' VI TRI CUA  NGUOI` CHOI
	it = new item(w - 6, h - 6);
}
//HAM` HUY
gameManager::~gameManager()
{
	delete ball, player;
}
//HAM TANG DIEM SO'
void gameManager::ScoreUP(pPaddle* player)
{
	score++;
}
//HAM` VE~
void gameManager::Draw()
{
	system("cls");//CLEAR MAN` HINH` CONSOLE
	for (int i = 0; i < width + 2; i++)//IN BIEN TREN
		cout << "\xB2";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			//LAY TOA DO CAC PHAN TU
			int ballx = ball->getX();
			int bally = ball->getY();
			int playerx = player->getX();
			int playery = player->getY();
			//VE CAC PHAN TU THEO VI TRI HIEN TAI CUA NO
			if (j == 0)
				cout << "\xB2";
			if (it->x == j && it->y == i)
			{
				if (it->l == 1)cout << "+";
				if (it->l == 2)cout << "-";
				if (it->l == 3)cout << "H";
			}
			else if (ballx == j && bally == i)
				cout << "O"; //ball
			else if (playerx == j && playery == i)
				cout << "\xDB"; //player1
			else if (playerx + 1 == j && playery == i)
				cout << "\xDB"; //player1
			else if (playerx + 2 == j && playery == i)
				cout << "\xDB"; //player1
			else if (playerx + 3 == j && playery == i)
				cout << "\xDB"; //player1
			///////////////////////////////////////////////
			else
				cout << " ";
			if (j == width - 1)
				cout << "\xB2";
		}
		cout << endl;
	}
	for (int i = 0; i < width + 2; i++)//IN BIEN DUOI'
		cout << "\xB2";
	cout << endl;
	cout << "Score: " << score << endl;//IN DIEM SO'
	cout << "<-: a ->: d ___q De Thoat_____s De SAVE.";
}
//HAM DIEU KHIEN TU BAN PHIM
void gameManager::Input()
{
	ball->move();
	int ballx = ball->getX();
	int bally = ball->getY();
	int player1x = player->getX();
	int player1y = player->getY();
	if (_kbhit())
	{
		char current = _getch();//NHAN GIA TRI TU BAN PHIM
		if (current == right1)
			if (player1x < width - 4)//DIEU KIEN DE CON TRUOT CHAY TRONG SAN CHOI
				player->moveRIGHT();
		if (current == left1)//DIEU KIEN DE CON TRUOT CHAY TRONG SAN CHOI
			if (player1x > 0)
				player->moveLEFT();
		if (ball->getDir() == STOP)//NEU QUA BONG DUNG YEN THI CHO NO DI CHUYEN THEO 1 HUONG NGAU NHIEN
			ball->RandomDir();

		if (current == 'q')//NEU NHAP q THI THOAT GAME
			quit = true;
		if (current == 's')
		{
			quit = true;
			Save();
		}
	}
}
//HAM DI CHUYEN CUA QUA BONG
void gameManager::Logic()
{
	int ballx = ball->getX();
	int bally = ball->getY();
	int playerx = player->getX();
	int playery = player->getY();
	//XET VI TRI CUA QUA BONG NEU O? RIA` SAN CHOI HOAC THANH TRUOT THI DI CHUYEN VOI HUONG' KHAC'
	//NEU VI TRI CUA QUA BONG O RIA` TREN VA` DUOI CUA SAN CHOI THI TANG DIEM CHO PLAYER
	//bottom paddle
	for (int i = 0; i <= 4; i++)
		if (bally == playery - 1)
			if (ballx == playerx + i)
			{
				ball->changeDir(ball->getDir() == DOWNRIGHT ? UPRIGHT :UPLEFT);
				ScoreUP(player);
			}
	//top wall
	if (bally == 0)
		ball->changeDir(ball->getDir() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
	//right wall
	if (ballx == width)
		ball->changeDir(ball->getDir() == UPRIGHT ? UPLEFT : DOWNLEFT);

	//left wall
	if (ballx == 1)
		ball->changeDir(ball->getDir() == UPLEFT ? UPRIGHT : DOWNRIGHT);
	//trung item
	if (ballx == it->x && bally == it->y)
	{
		if (it->l == 3)
			ball->RandomDir();
		if (it->l == 2)
				score *= 0.5;
		if (it->l == 1)
				score *= 2;
		it->reset(width - 6, height - 6);
	}
	if (bally == height + 1)
	{
		ball->changeDir((Dir)0);
		quit = true;
		cout << "\nLuu thanh tich: ";
		string s;
		cin >> s;
		fstream f;
		f.open("thanhtich.txt", ios::app);
		f << s << endl;
		f << "PL: " << score << endl;
		f.close();
	}
}
//HAM CHAY GAME
void gameManager::Run()
{
	while (!quit)//XET BIEN' DIEU KIEN DUNG` GAME
	{
		Draw();
		Input();
		Logic();
	}
}
void gameManager::Save()
{
	string s;
	cout << "\n---SAVE GAME---\nNhap ten: "; cin >> s;
	fstream f;
	f.open(s);
	f << score << endl;
	f << ball->getX() << endl;
	f << ball->getY() << endl;
	f << ball->getDir() << endl;
	f << player->getX() << endl;
	f << player->getY() << endl;
	f << it->x << endl;
	f << it->y << endl;
	f << it->l ;
	f.close();
}
gameManager::gameManager(string s,int w,int h)
{
	srand(time(NULL));
	quit = false;//DIEU KIEN DE THOAT GAME
	right1 = 'd';//THIET LAP CAC PHIM DIEU KHIEN
	left1 = 'a'; 
	width = w; height = h;
	ifstream f; int n, m, k;
	f.open(s);
	while (!f.eof())
	{
		f >> n;
		score = n;
		f >> n;
		f >> m;
		ball = new pBall(n, m);
		f >> k;
		ball->changeDir((Dir)k);
		f >> n;
		f >> m;
		player = new pPaddle(n,m);//GAN' VI TRI CUA 2 NGUOI` CHOI
		f >> n;
		f >> m;
		f >> k;
		it = new item(n,m,k);
	}
	f.close();
}