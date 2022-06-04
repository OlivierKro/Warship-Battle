#pragma once
#include "Gracz.h"


class Gra;
class PoleGry;

class U�ytkownik : public Gracz
{
private:
public:
	U�ytkownik(){}
	U�ytkownik(Gra* _Gra, int x);
	~U�ytkownik();

	void wezPoleGry(PoleGry* _PG);
	void StworzStatki();
	void SprawdzZniszczenie();
	void TrafStatek(int x, int y);
	void DrukujInfo();
	int AtakujX();
	int AtakujY();
};