#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <string>

#include "Statek.h"

using namespace std;

class Gracz;

class PoleGry
{
private:
	//Pola wy�wietlane
	char MojePole[8][8];
	char PolePrzeciwnika[8][8];
	//Tablice trafie�
	bool MojeStatki[8][8];
	bool StatkiPrzeciwnika[8][8];
public:
	PoleGry();
	~PoleGry();

	void Wype�nijPole();
	void DrukujMojePole();
	void DrukujPrzeciwnikaPole();
	void UstawStatek(vector <int> x, vector <int> y, Statek* _Statek, bool Bot = false);
	void Atakuj(int x, int y, bool trafienie, Gracz* G1, Gracz* G2);
	bool OdbierzAtak(int x, int y);
};