#pragma once
#include "Gra.h"
#include "PoleGry.h"


Gracz::Gracz(const Gracz& G)
{
	int n;
	Nazwa = G.Nazwa;
	Zniszczenie = G.Zniszczenie;
	Pole = G.Pole;
	statki = new Statek * [IloscStatkow];
	statki[0] = new Trójmasztowiec(1);
	statki[1] = new Dwumasztowiec(2);
	statki[2] = new Dwumasztowiec(3);;
	statki[3] = new Jednomasztowiec(4);
	statki[4] = new Jednomasztowiec(5);
	statki[5] = new Jednomasztowiec(6);
	for (n = 0; n < IloscStatkow; n++)
	{
		statki[0] = G.statki[0];
	}
}

Gracz::~Gracz()
{
	cout << "Usuwanie gracza " << Nazwa;
	cout << endl;
	for (int n = 0; n < IloscStatkow; n++)
	{
		delete statki[n];
	}
	delete[] statki;
	Nazwa.clear();
}

Gracz& Gracz::operator=(const Gracz& G)
{
	if (&G == this)
	{
		return *this;
	}
	int n;
	for (n = 0; n < 1; n++)
	{
		delete statki[n];
	}
	delete[] statki;
	Nazwa = G.Nazwa;
	Zniszczenie = G.Zniszczenie;
	Pole = G.Pole;
	statki = new Statek * [IloscStatkow];
	statki[0] = new Trójmasztowiec(1);
	statki[1] = new Dwumasztowiec(2);
	statki[2] = new Dwumasztowiec(3);;
	statki[3] = new Jednomasztowiec(4);
	statki[4] = new Jednomasztowiec(5);
	statki[5] = new Jednomasztowiec(6);
	for (n = 0; n < IloscStatkow; n++)
	{
		statki[n] = G.statki[n];
	}
	return *this;
}


bool Gracz::operator==(Gracz& G)
{
	if (G.Zniszczenie == Zniszczenie)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Gracz::operator!=(Gracz& G)
{
	if (G.Zniszczenie != Zniszczenie)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Gracz::operator>(Gracz& G)
{
	if (Zniszczenie == false && G.Zniszczenie == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Gracz::operator>=(Gracz& G)
{
	if (Zniszczenie == false)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Gracz::operator<(Gracz& G)
{
	if (Zniszczenie == true && G.Zniszczenie == false)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Gracz::operator<=(Gracz& G)
{
	if (Zniszczenie == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//Akcesory
bool Gracz::dajZniszczenie()
{
	return Zniszczenie;
}

string Gracz::dajNazwe()
{
	return Nazwa;
}

//Zabezpieczenie
int Gracz::Cin()
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