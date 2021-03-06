#pragma once
#include "Gracz.h"


class Gra;
class PoleGry;

class Użytkownik : public Gracz
{
private:
public:
	Użytkownik(){}
	Użytkownik(Gra* _Gra, int x);
	~Użytkownik();

	void wezPoleGry(PoleGry* _PG);
	void StworzStatki();
	void SprawdzZniszczenie();
	void TrafStatek(int x, int y);
	void DrukujInfo();
	int AtakujX();
	int AtakujY();
};