#include "PoleGry.h"
#include "Gracz.h"


PoleGry::PoleGry()
{
	Wype³nijPole();
}

PoleGry::~PoleGry()
{
	cout << "Usuwanie pola gry\n";
}


void PoleGry::Wype³nijPole()
{
	MojePole[0][0] = ' ';
	PolePrzeciwnika[0][0] = ' ';
	MojePole[0][1] = '1';
	PolePrzeciwnika[0][1] = '1';
	MojePole[0][2] = '2';
	PolePrzeciwnika[0][2] = '2';
	MojePole[0][3] = '3';
	PolePrzeciwnika[0][3] = '3';
	MojePole[0][4] = '4';
	PolePrzeciwnika[0][4] = '4';
	MojePole[0][5] = '5';
	PolePrzeciwnika[0][5] = '5';
	MojePole[0][6] = '6';
	PolePrzeciwnika[0][6] = '6';
	MojePole[0][7] = '7';
	PolePrzeciwnika[0][7] = '7';

	MojePole[1][0] = '1';
	PolePrzeciwnika[1][0] = '1';
	MojePole[2][0] = '2';
	PolePrzeciwnika[2][0] = '2';
	MojePole[3][0] = '3';
	PolePrzeciwnika[3][0] = '3';
	MojePole[4][0] = '4';
	PolePrzeciwnika[4][0] = '4';
	MojePole[5][0] = '5';
	PolePrzeciwnika[5][0] = '5';
	MojePole[6][0] = '6';
	PolePrzeciwnika[6][0] = '6';
	MojePole[7][0] = '7';
	PolePrzeciwnika[7][0] = '7';

	for (int i = 1; i <= 7; i++)
	{
		for (int j = 1; j <= 7; j++)
		{
			MojePole[i][j] = '0';
			PolePrzeciwnika[i][j] = '0';
		}
	}
	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= 7; j++)
		{
			MojeStatki[i][j] = false;
			StatkiPrzeciwnika[i][j] = false;
		}
	}
}

void PoleGry::DrukujMojePole()
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= 7; j++)
		{
			if (MojeStatki[i][j] == true)
			{
				if (MojePole[i][j] == 'X')
				{
					SetConsoleTextAttribute(hOut, BACKGROUND_RED);
					cout << MojePole[i][j];
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
					cout << MojePole[i][j] << ' ';
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				}
			}
			else if (MojeStatki[i][j] == false)
			{
				if (MojePole[i][j] == 'X')
				{
					cout << MojePole[i][j] << ' ';
				}
				else
				{
					cout << MojePole[i][j] << ' ';
				}
			}
		}
		cout << endl;
	}
	cout << endl;
}

void PoleGry::DrukujPrzeciwnikaPole()
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl;
	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= 7; j++)
		{
			if (StatkiPrzeciwnika[i][j] == true)
			{
				if (PolePrzeciwnika[i][j] == 'X')
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << PolePrzeciwnika[i][j] << ' ';
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				}
			}
			else if (StatkiPrzeciwnika[i][j] == false)
			{
				if (PolePrzeciwnika[i][j] == 'X')
				{
					cout << PolePrzeciwnika[i][j] << ' ';
				}
				else
				{
					cout << PolePrzeciwnika[i][j] << ' ';
				}
			}
		}
		cout << endl;
	}
	cout << endl;
}

void PoleGry::UstawStatek(vector <int> x, vector <int> y, Statek* _Statek, bool Bot)
{
	for (int n = 0; n < x.size(); n++)
	{
		if (MojeStatki[y[n]][x[n]] == true || MojeStatki[y[n] - 1][x[n] - 1] == true || MojeStatki[y[n]][x[n] - 1] == true ||
			MojeStatki[y[n] + 1][x[n] - 1] == true || MojeStatki[y[n] - 1][x[n]] == true ||
			MojeStatki[y[n] + 1][x[n]] == true || MojeStatki[y[n] - 1][x[n] + 1] == true ||
			MojeStatki[y[n]][x[n] + 1] == true || MojeStatki[y[n] + 1][x[n] + 1] == true)
		{
			do
			{
				if (Bot == true)
				{
  					_Statek->ZmienPolozenie(Bot);
				}
				else
				{
					_Statek->ZmienPolozenie();
				}
				x = _Statek->dajPolozenieX();
				y = _Statek->dajPolozenieY();
			} while (MojeStatki[y[n]][x[n]] == true || MojeStatki[y[n] - 1][x[n] - 1] == true || MojeStatki[y[n]][x[n] - 1] == true ||
					MojeStatki[y[n] + 1][x[n] - 1] == true || MojeStatki[y[n] - 1][x[n]] == true ||
					MojeStatki[y[n] + 1][x[n]] == true || MojeStatki[y[n] - 1][x[n] + 1] == true ||
					MojeStatki[y[n]][x[n] + 1] == true || MojeStatki[y[n] + 1][x[n] + 1] == true);
		}
	}
	for (int n = 0; n < x.size(); n++)
	{
		MojeStatki[y[n]][x[n]] = true;
	}
}

void PoleGry::Atakuj(int x, int y, bool trafienie, Gracz* G1, Gracz* G2)
{
	if (x < 1 || x > 7 || y < 1 || y > 7)
	{
		throw 1;
	}
	if (PolePrzeciwnika[y][x] == 'X')
	{
		throw 'x';
	}
	PolePrzeciwnika[y][x] = 'X';
	if (trafienie == true)
	{
		G2->TrafStatek(x, y);
		StatkiPrzeciwnika[y][x] = true;
	}
	else if (trafienie == false)
	{
		StatkiPrzeciwnika[y][x] = false;
	}
}

bool PoleGry::OdbierzAtak(int x, int y)
{
	if ((x > 0 && x < 8) && (y > 0 && y < 8))
	{
		MojePole[y][x] = 'X';
	}
	if (MojeStatki[y][x] == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
