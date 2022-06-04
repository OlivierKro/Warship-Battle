#pragma once
#include "Gra.h"
#include "Gracz.h"

//Wyjątek
Gra::Gra()
{
	int tmpl = 0;
	do
	{
		try
		{
			StworzGre();
			tmpl = 1;
		}
		catch (char x)
		{
			cout << "\nNie wybrano odpowiedniego typu gracza!\n";
		}
	} while (tmpl == 0);
	RozlozStatki();

	Graj();
}

Gra::Gra(const Gra& G)
{
	int n;
	czy_bot = G.czy_bot;
	Gracze = new Gracz * [2];
	Gracze[0] = new Użytkownik;
	if (czy_bot == 1)
	{
		Gracze[1] = new Użytkownik;
	}
	else if (czy_bot == 2)
	{
		Gracze[1] = new Bot;
	}
	PolaGry = new PoleGry[2];
	for (n = 0; n < 2; n++)
	{
		Gracze[n] = G.Gracze[n];
	}
	for (n = 0; n < 2; n++)
	{
		PolaGry[n] = G.PolaGry[n];
	}
}

Gra::~Gra()
{
	for (int n = 0; n < 2; n++)
	{

		delete Gracze[n];
	}
	delete[] Gracze;
	delete[] PolaGry;
}

Gra& Gra::operator=(const Gra& G)
{
	if (&G == this)
	{
		return *this;
	}
	int n;
	for (n = 0; n < 2; n++)
	{
		delete Gracze[n];
	}
	delete[] Gracze;
	delete[] PolaGry;
	czy_bot = G.czy_bot;
	Gracze = new Gracz * [2];
	Gracze[0] = new Użytkownik;
	if (czy_bot == 1)
	{
		Gracze[1] = new Użytkownik;
	}
	else if (czy_bot == 2)
	{
		Gracze[1] = new Bot;
	}
	PolaGry = new PoleGry[2];
	for (n = 0; n < 2; n++)
	{
		Gracze[n] = G.Gracze[n];
	}
	for (n = 0; n < 2; n++)
	{
		PolaGry[n] = G.PolaGry[n];
	}
	return *this;
}


PoleGry* Gra::dajPoleGry(int x)
{
	if (x == 1)
	{
		return &PolaGry[0];
	}
	else if (x == 2)
	{
		return &PolaGry[1];
	}
}
//Wyjątek
void Gra::StworzGre()
{
	cout << "Wybierz przeciwnika:\n1.Uzytkownik\n2.Bot\n";
	czy_bot = Cin();
//	cin >> czy_bot;
	if (czy_bot != 1 && czy_bot != 2)
	{
		throw 'x';
	}
	PolaGry = new PoleGry[2];
	Gracze = new Gracz * [2];
	Gracze[0] = new Użytkownik(this, 1);
	if (czy_bot == 1)
	{
		Gracze[1] = new Użytkownik(this, 2);
	}
	else if (czy_bot == 2)
	{
		Gracze[1] = new Bot(this, 2);
	}
	system("pause");
}

void Gra::RozlozStatki()
{
	Gracze[0]->StworzStatki();
	Gracze[1]->StworzStatki();
}
//Wyjątek
void Gra::Graj()
{
	int xTMPL, yTMPL;
	bool Atak;
	do
	{
		Gracze[0]->DrukujInfo();
		do
		{
			try
			{
				xTMPL = Gracze[0]->AtakujX();
				yTMPL = Gracze[0]->AtakujY();
				atak(yTMPL, xTMPL, Gracze[0], Gracze[1], 1);
				Atak = true;
			}
			catch (char x)
			{
				Atak = false;
				cout << "W to miejsce juz strzelales!\n";
			}
			catch (int wynik)
			{
				Atak = false;
				cout << "Podano złe kordynaty!\n";
			}
		} while (Atak == false);

		Gracze[1]->SprawdzZniszczenie();
		system("Pause");
		system("cls");

		Gracze[1]->DrukujInfo();
		do
		{
			try
			{
				xTMPL = Gracze[1]->AtakujX();
				yTMPL = Gracze[1]->AtakujY();
				atak(yTMPL, xTMPL, Gracze[1], Gracze[0], 2);
				Atak = true;
			}
			catch (char x)
			{
				Atak = false;
				cout << "W to miejsce juz strzelales!\n";
			}
			catch (int wynik)
			{
				Atak = false;
				cout << "Podano złe kordynaty!\n";
			}
		} while (Atak == false);
		Gracze[0]->SprawdzZniszczenie();
		if (czy_bot == 1)
		{
			system("Pause");
		}
		system("cls");

	} while (Gracze[0]->dajZniszczenie() == false && Gracze[1]->dajZniszczenie() == false);
	Wynik();

}
//Zastosowanie operatorów
void Gra::Wynik()
{
//	if (Gracze[0]->dajZniszczenie() == true && Gracze[1]->dajZniszczenie() == false)
	if (*Gracze[0] < *Gracze[1])
	{
		cout << "Zatopiono wszystkie statki gracza: " << Gracze[0]->dajNazwe() << endl;
		cout << "Zwyciezca jest gracz: " << Gracze[1]->dajNazwe() << endl;
	}
//	else if (Gracze[1]->dajZniszczenie() == true && Gracze[0]->dajZniszczenie() == false)
	else if (*Gracze[0] > *Gracze[1])
	{
		cout << "Zatopiono wszystkie statki gracza: " << Gracze[1]->dajNazwe() << endl;
		cout << "Zwyciezca jest gracz: " << Gracze[0]->dajNazwe() << endl;
	}
//	else if (Gracze[0]->dajZniszczenie() == true && Gracze[1]->dajZniszczenie() == true)
	else if (*Gracze[0]==*Gracze[1])
	{
		cout << "Zatopiono wszystkie statki obu graczy w czasie jednej tury" << endl;
		cout << "Nie ma zwyciezcy!" << endl;
	}
	system("Pause");
}

void Gra::atak(int y, int x, Gracz* G1, Gracz* G2, int KtoryGracz)
{
	if (KtoryGracz == 1)
	{
		PolaGry[0].Atakuj(x, y, PolaGry[1].OdbierzAtak(x, y), G1, G2);
	}
	else if (KtoryGracz == 2)
	{
		PolaGry[1].Atakuj(x, y, PolaGry[0].OdbierzAtak(x, y), G1, G2);
	}

}

//Zabezpieczenie
int Gra::Cin()
{
	int x;
	while (1)
	{
		cin >> x;
		if (std::cin.fail() == true)
		{
			cout << "wykryto blad" << std::endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin.sync();
		}
		else
		{
			cin.ignore(256, '\n');
			cin.sync();
			break;
		}
	}
	return x;
}