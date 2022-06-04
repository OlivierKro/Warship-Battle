#pragma once
#include "Statek.h"


Statek::Statek(const Statek& S)
{
	int n;
	id = S.id;
	dlugosc = S.dlugosc;
	zatopiony = S.zatopiony;
	for (n = 0; n < S.trafienie.size(); n++)
	{
		trafienie.push_back(S.trafienie[n]);
	}
	for (n = 0; n < S.PolozenieX.size(); n++)
	{
		trafienie.push_back(S.PolozenieX[n]);
	}
	for (n = 0; n < S.PolozenieY.size(); n++)
	{
		trafienie.push_back(S.PolozenieY[n]);
	}
}

Statek::~Statek()
{
	cout << "Usuwanie Statku\n";
	trafienie.clear();
	PolozenieX.clear();
	PolozenieY.clear();
}

Statek& Statek::operator=(const Statek& S)
{
	if (&S == this)
	{
		return *this;
	}
	trafienie.clear();
	PolozenieX.clear();
	PolozenieY.clear();
	id = S.id;
	dlugosc = S.dlugosc;
	zatopiony = S.zatopiony;
	int n;
	for (n = 0; n < S.trafienie.size(); n++)
	{
		trafienie.push_back(S.trafienie[n]);
	}
	for (n = 0; n < S.PolozenieX.size(); n++)
	{
		trafienie.push_back(S.PolozenieX[n]);
	}
	for (n = 0; n < S.PolozenieY.size(); n++)
	{
		trafienie.push_back(S.PolozenieY[n]);
	}
	return *this;
}


//Akcesory
vector <int> Statek::dajPolozenieX()
{
	return PolozenieX;
}

vector <int> Statek::dajPolozenieY()
{
	return PolozenieY;
}

bool Statek::dajzatopiony()
{
	return zatopiony;
}

//Zabezpieczenia
int Statek::Cin()
{
	int x;
	while (1)
	{
		cin >> x;
		if (std::cin.fail() == true)
		{
			cout << "wykryto blad" << std::endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin.sync();
		}
		else
		{
			cin.ignore(256, '\n');
			cin.sync();
			break;
		}
	}
	return x;
}
