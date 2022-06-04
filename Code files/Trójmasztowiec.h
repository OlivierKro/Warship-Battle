#pragma once
#include "Statek.h"


class Trójmasztowiec :	public Statek
{
public:
	Trójmasztowiec(int _id);
	Trójmasztowiec(int _id, bool Bot);
	~Trójmasztowiec();

	void ZmienPolozenie();
	void ZmienPolozenie(bool Bot);
	void SprawdzZatopienie();
	void ZatopCzesc(int x, int y);
	void ZatopCalosc();
};

