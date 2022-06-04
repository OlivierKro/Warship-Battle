#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <string>


using namespace std;


class Statek
{
protected:

	int id;
	int dlugosc;
	vector <bool> trafienie;
	vector <int> PolozenieX;
	vector <int> PolozenieY;
	bool zatopiony = false;
public:
	Statek(){}
	Statek(const Statek& S);
	virtual ~Statek();
	Statek& operator=(const Statek& S);

	virtual void ZmienPolozenie()=0;
	virtual void ZmienPolozenie(bool Bot) = 0;
	virtual void SprawdzZatopienie()=0;
	virtual void ZatopCzesc(int x, int y) = 0;
	virtual void ZatopCalosc() = 0;
	//Akcesory
	vector <int> dajPolozenieX();
	vector <int> dajPolozenieY();
	bool dajzatopiony();
	//Zabezpieczenie
	int Cin();
};

