#include "Bot.h"
#include "Gra.h"
#include "PoleGry.h"


Bot::Bot(Gra* _Gra, int x)
{
	Nazwa = "Bot";
	wezPoleGry((*_Gra).dajPoleGry(x));
}

Bot::~Bot()
{
	cout << "Usuwanie bota ";
}

void Bot::wezPoleGry(PoleGry* _PG)
{
	Pole = _PG;
}

void Bot::StworzStatki()
{
	//Prawid³owa wersja

	statki = new Statek * [IloscStatkow];
	system("cls");
	statki[0] = new Trójmasztowiec(1, true);
	Pole->UstawStatek(statki[0]->dajPolozenieX(), statki[0]->dajPolozenieY(), statki[0], true);
	statki[1] = new Dwumasztowiec(2, true);
	Pole->UstawStatek(statki[1]->dajPolozenieX(), statki[1]->dajPolozenieY(), statki[1], true);
	statki[2] = new Dwumasztowiec(3, true);
	Pole->UstawStatek(statki[2]->dajPolozenieX(), statki[2]->dajPolozenieY(), statki[2], true);
	statki[3] = new Jednomasztowiec(4, true);
	Pole->UstawStatek(statki[3]->dajPolozenieX(), statki[3]->dajPolozenieY(), statki[3], true);
	statki[4] = new Jednomasztowiec(5, true);
	Pole->UstawStatek(statki[4]->dajPolozenieX(), statki[4]->dajPolozenieY(), statki[4], true);
	statki[5] = new Jednomasztowiec(6, true);
	Pole->UstawStatek(statki[5]->dajPolozenieX(), statki[5]->dajPolozenieY(), statki[5], true);
}

void Bot::SprawdzZniszczenie()
{
	int ilosc_zatopionych_statkow = 0;
	for (int n = 0; n < IloscStatkow; n++)
	{
		statki[n]->SprawdzZatopienie();
		if (statki[n]->dajzatopiony() == true)
		{
			ilosc_zatopionych_statkow++;
		}
	}
	if (ilosc_zatopionych_statkow == IloscStatkow)
	{
		Zniszczenie = true;
	}
}

void Bot::TrafStatek(int x, int y)
{
	for (int n = 0; n < IloscStatkow; n++)
	{
		statki[n]->ZatopCzesc(x, y);
	}
}

void Bot::DrukujInfo() 
{
}

int Bot::AtakujX()
{
	int x;
	x = ((rand() % 7) + 1);
	return x;
}

int Bot::AtakujY()
{
	int y;
	y = ((rand() % 7) + 1);
	return y;
}


