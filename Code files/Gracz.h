#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <string>

#include "PoleGry.h"
#include "Jednomasztowiec.h"
#include "Dwumasztowiec.h"
#include "Trójmasztowiec.h"

using namespace std;


class PoleGry;

class Gracz
{
protected:
	string Nazwa;
	PoleGry* Pole;
	Statek** statki;
	bool Zniszczenie = false;
	int IloscStatkow = 6;
public:
	Gracz(){}
	Gracz(const Gracz& G);
	virtual ~Gracz();
	Gracz& operator=(const Gracz& G);

	bool operator==(Gracz& G);
	bool operator!=(Gracz& G);
	bool operator>(Gracz& G);
	bool operator>=(Gracz& G);
	bool operator<(Gracz& G);
	bool operator<=(Gracz& G);

	virtual void wezPoleGry(PoleGry* _PG) = 0;
	virtual void StworzStatki() = 0;
	virtual void SprawdzZniszczenie() = 0;
	virtual void TrafStatek(int x, int y) = 0;
	virtual void DrukujInfo() = 0;
	virtual int AtakujX() = 0;
	virtual int AtakujY() = 0;
	//Akcesory
	bool dajZniszczenie();
	string dajNazwe();
	//Zabezpieczenie
	int Cin();
};

