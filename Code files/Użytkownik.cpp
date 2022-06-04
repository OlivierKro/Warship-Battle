#pragma once
#include "U¿ytkownik.h"
#include "Gra.h"
#include "PoleGry.h"

//U¿ycie oraz modyfikacja string
U¿ytkownik::U¿ytkownik(Gra* _Gra, int x)
{
	cout << "Nazwa gracza nie mo¿e przekraczaæ 20 znaków. Reszta automatycznie jest usuwana!\n";
	cout << "Podaj nazwe gracza: ";
	cin >> Nazwa;
	if (Nazwa.length() > 20)
	{
		for (int i = Nazwa.length() - 20; i > 0; i--)
		{
			Nazwa.pop_back();
		}
		cout << "Twoja nazwa uleg³a zmianie!\n";
		cout << "Twoja nazwa teraz to: " << Nazwa << endl;
	}
	wezPoleGry((*_Gra).dajPoleGry(x));
}

U¿ytkownik::~U¿ytkownik()
{
	cout << "Usuwanie gracza ";
}


void U¿ytkownik::wezPoleGry(PoleGry* _PG)
{
	Pole = _PG;
}

void U¿ytkownik::StworzStatki()
{
	statki = new Statek*[IloscStatkow];
	system("cls");
	cout << "Statki rozk³ada gracz: " << Nazwa << endl << endl;
	Pole->DrukujMojePole();
	statki[0] = new Trójmasztowiec(1);
	Pole->UstawStatek(statki[0]->dajPolozenieX(), statki[0]->dajPolozenieY(), statki[0]);
	system("cls");
	cout << "Statki rozk³ada gracz: " << Nazwa << endl << endl;
	Pole->DrukujMojePole();
	statki[1] = new Dwumasztowiec(2);
	Pole->UstawStatek(statki[1]->dajPolozenieX(), statki[1]->dajPolozenieY(), statki[1]);
	system("cls");
	cout << "Statki rozk³ada gracz: " << Nazwa << endl << endl;
	Pole->DrukujMojePole();
	statki[2] = new Dwumasztowiec(3);
	Pole->UstawStatek(statki[2]->dajPolozenieX(), statki[2]->dajPolozenieY(), statki[2]);
	system("cls");
	cout << "Statki rozk³ada gracz: " << Nazwa << endl << endl;
	Pole->DrukujMojePole();
	statki[3] = new Jednomasztowiec(4);
	Pole->UstawStatek(statki[3]->dajPolozenieX(), statki[3]->dajPolozenieY(), statki[3]);
	system("cls");
	cout << "Statki rozk³ada gracz: " << Nazwa << endl << endl;
	Pole->DrukujMojePole();
	statki[4] = new Jednomasztowiec(5);
	Pole->UstawStatek(statki[4]->dajPolozenieX(), statki[4]->dajPolozenieY(), statki[4]);
	system("cls");
	cout << "Statki rozk³ada gracz: " << Nazwa << endl << endl;
	Pole->DrukujMojePole();
	statki[5] = new Jednomasztowiec(6);
	Pole->UstawStatek(statki[5]->dajPolozenieX(), statki[5]->dajPolozenieY(), statki[5]);
	system("cls");
	cout << "Gracz " << Nazwa << " roz³o¿y³ wszystkie statki" << endl;
	Pole->DrukujMojePole();
	system("pause");
	system("cls");
}

void U¿ytkownik::SprawdzZniszczenie()
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

void U¿ytkownik::TrafStatek(int x, int y)
{
	for (int n = 0; n < IloscStatkow; n++)
	{
		statki[n]->ZatopCzesc(x, y);
	}
}

void U¿ytkownik::DrukujInfo()
{
	cout << "Ruch gracza: " << Nazwa << endl << endl;
	cout << "Twoje pole\n-------------------------\n";
	Pole->DrukujMojePole();
	cout << "Pole przeciwnika\n-------------------------";
	Pole->DrukujPrzeciwnikaPole();
}

int U¿ytkownik::AtakujX()
{
	int x;
	cout << "Podaj miejsce ataku\n";
	cout << "Kolumna: ";
	x = Cin();
	return x;
}

int U¿ytkownik::AtakujY()
{
	int y;
	cout << "Wiersz: ";
	y = Cin();
	return y;
}
