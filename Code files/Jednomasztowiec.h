#pragma once
#include "Statek.h"


class Jednomasztowiec :	public Statek
{
public:
	Jednomasztowiec() {}
	Jednomasztowiec(int _id);
	Jednomasztowiec(int _id, bool Bot);
	~Jednomasztowiec();

	void ZmienPolozenie();
	void ZmienPolozenie(bool Bot);
	void SprawdzZatopienie();
	void ZatopCzesc(int x, int y);
	void ZatopCalosc();
};

