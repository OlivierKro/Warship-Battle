#pragma once
#include "Statek.h"


class Tr�jmasztowiec :	public Statek
{
public:
	Tr�jmasztowiec(int _id);
	Tr�jmasztowiec(int _id, bool Bot);
	~Tr�jmasztowiec();

	void ZmienPolozenie();
	void ZmienPolozenie(bool Bot);
	void SprawdzZatopienie();
	void ZatopCzesc(int x, int y);
	void ZatopCalosc();
};

