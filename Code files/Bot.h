#pragma once
#include "Gracz.h"
#include <stdlib.h>


class Gra;
class PoleGry;

class Bot : public Gracz
{
private:
public:
	Bot() {}
	Bot(Gra* _Gra, int x);
	~Bot();

	void wezPoleGry(PoleGry* _PG);
	void StworzStatki();
	void SprawdzZniszczenie();
	void TrafStatek(int x, int y);
	void DrukujInfo();
	int AtakujX();
	int AtakujY();
};