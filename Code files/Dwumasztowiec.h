#pragma once
#include "Statek.h"


class Dwumasztowiec : public Statek
{
public:
	Dwumasztowiec(int _id);
	Dwumasztowiec(int _id, bool Bot);
	~Dwumasztowiec();

	void ZmienPolozenie();
	void ZmienPolozenie(bool Bot);
	void SprawdzZatopienie();
	void ZatopCzesc(int x, int y);
	void ZatopCalosc();
};

