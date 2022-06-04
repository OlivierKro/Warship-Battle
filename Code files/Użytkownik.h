#pragma once
#include "Gracz.h"


class Gra;
class PoleGry;

class U퓓tkownik : public Gracz
{
private:
public:
	U퓓tkownik(){}
	U퓓tkownik(Gra* _Gra, int x);
	~U퓓tkownik();

	void wezPoleGry(PoleGry* _PG);
	void StworzStatki();
	void SprawdzZniszczenie();
	void TrafStatek(int x, int y);
	void DrukujInfo();
	int AtakujX();
	int AtakujY();
};