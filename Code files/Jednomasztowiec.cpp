#include "Jednomasztowiec.h"

//Wyj¹tek
Jednomasztowiec::Jednomasztowiec(int _id)
{
	bool OdpowiednieKordynaty = false;
	id = _id;
	dlugosc = 1;
	for (int n = 0; n < dlugosc; n++)
	{
		PolozenieX.push_back(0);
		PolozenieY.push_back(0);
	}
	do
	{
		try
		{
			cout << "Podaj polozenie jednomasztowca\n";
			cout << "Kolumna: ";
			PolozenieX[0] = Cin();
//			cin >> PolozenieX[0];
			cout << "Wiersz: ";
			PolozenieY[0] = Cin();
//			cin >> PolozenieY[0];
			trafienie.push_back(false);
			if ((PolozenieX[0] < 1 || PolozenieX[0] > 7) || (PolozenieY[0] < 1 || PolozenieY[0] > 7))
			{
				throw 'x';
			}
			OdpowiednieKordynaty = true;
		}
		catch (char x)
		{
			cout << "Podano z³¹ wartoœæ po³o¿enia jednomasztowca\n";
		}
	} while (OdpowiednieKordynaty == false);
}

Jednomasztowiec::Jednomasztowiec(int _id, bool Bot)
{
	id = _id;
	dlugosc = 1;
	for (int n = 0; n < dlugosc; n++)
	{
		PolozenieX.push_back(0);
		PolozenieY.push_back(0);
	}
	PolozenieX[0] = (rand() % 7)  + 1;
	PolozenieY[0] = (rand() % 7)  + 1;
	trafienie.push_back(false);
}

Jednomasztowiec::~Jednomasztowiec()
{
	cout << "Usuniêto Jednomasztowiec! \n";
}

//Wyj¹tek
void Jednomasztowiec::ZmienPolozenie()
{
	bool OdpowiednieKordynaty = false;
	cout << "Podane wspolrzedne s¹ ju¿ zajête!\n";
	do
	{
		try
		{
			cout << "Podaj polozenie jednomasztowca\n";
			cout << "Kolumna: ";
			PolozenieX[0] = Cin();
//			cin >> PolozenieX[0];
			cout << "Wiersz: ";
			PolozenieY[0] = Cin();
//			cin >> PolozenieY[0];
			if ((PolozenieX[0] < 1 || PolozenieX[0] > 7) || (PolozenieY[0] < 1 || PolozenieY[0] > 7))
			{
				throw 'x';
			}
			OdpowiednieKordynaty = true;
		}
		catch (char x)
		{
			cout << "Podano z³¹ wartoœæ po³o¿enia jednomasztowca\n";
		}
	} while (OdpowiednieKordynaty == false);
}

void Jednomasztowiec::ZmienPolozenie(bool Bot)
{
	PolozenieX[0] = ((rand() % 7) + 1);
	PolozenieY[0] = ((rand() % 7) + 1);
}

void Jednomasztowiec::SprawdzZatopienie()
{
	if (trafienie[0] == true)
	{
		zatopiony = true;
	}
	else
	{
		zatopiony = false;
	}
}

void Jednomasztowiec::ZatopCzesc(int x, int y)
{
	if (x == PolozenieX[0] && y == PolozenieY[0])
	{
		trafienie[0] = true;
		ZatopCalosc();
	}
}

void Jednomasztowiec::ZatopCalosc()
{
	if (trafienie[0] == true)
	{
		cout << endl;
		cout << "---------------------------\n";
		cout << "Zatopiono jednomasztowiec!\n";
		cout << "---------------------------\n";
		zatopiony = true;
	}
}


