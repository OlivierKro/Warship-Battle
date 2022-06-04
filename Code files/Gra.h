#pragma once
#include "PoleGry.h"
#include "Gracz.h"
#include "U¿ytkownik.h"
#include "Bot.h"

class Gracz;

class Gra
{
private:
	Gracz** Gracze;
	PoleGry* PolaGry;
	int czy_bot;
public:
	Gra();
	Gra(const Gra& G);
	~Gra();
	Gra& operator=(const Gra& G);

	PoleGry* dajPoleGry(int x);
	void StworzGre();
	void RozlozStatki();
	void Graj();
	void Wynik();
	void atak(int y, int x, Gracz* G1, Gracz* G2, int KtoryGracz);
	//Zabezpieczenie
	int Cin();
};

