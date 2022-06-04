#include "Dwumasztowiec.h"

//Wyj¹tek
Dwumasztowiec::Dwumasztowiec(int _id)
{
	bool OdpowiednieKordynaty = false;
	bool tmpl=false;
	id = _id;
	dlugosc = 2;
	for (int n = 0; n < dlugosc; n++)
	{
		PolozenieX.push_back(0);
		PolozenieY.push_back(0);
	}
	do
	{
		try
		{
			cout << "Podaj poczatek dwumasztowca\n";
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
			cout << "Podano z³¹ wartoœæ pocz¹tku dwumasztowca\n";
		}
	} while (OdpowiednieKordynaty == false);
	OdpowiednieKordynaty = false;
	do
	{
		try
		{
			cout << "Podaj koniec dwumasztowca\n";
			cout << "Kolumna: ";
			PolozenieX[1] = Cin();
//			cin >> PolozenieX[1];
			cout << "Wiersz: ";
			PolozenieY[1] = Cin();
//			cin >> PolozenieY[1];
			if ((PolozenieX[1] < 1 || PolozenieX[1] > 7) || (PolozenieY[1] < 1 || PolozenieY[1] > 7))
			{
				throw 'x';
			}
			OdpowiednieKordynaty = true;
		}
		catch (char x)
		{
			cout << "Podano z³¹ wartoœæ koñca dwumasztowca\n";
		}
	} while (OdpowiednieKordynaty == false);
	// Test zgodnoœci pocz¹tku i koñca dwumasztowca
	do
	{
		// Test koñca dwumasztowca gdy wspó³¿êdna X jest taka sama
		if (PolozenieX[1] == PolozenieX[0])
		{
			if (PolozenieY[1] == (PolozenieY[0] + 1) || PolozenieY[1] == (PolozenieY[0] - 1))
			{
				tmpl = true;
			}
			else
			{
				cout << "Podano zla wartosc konca statku!\n";
				cout << "Podaj koniec dwumasztowca\n";
				cout << "Kolumna: ";
				PolozenieX[1] = Cin();
//				cin >> PolozenieX[1];
				cout << "Wiersz: ";
				PolozenieY[1] = Cin();
//				cin >> PolozenieY[1];
			}
		}
		// Test koñca dwumasztowca gdy wspó³¿êdna Y jest taka sama
		else if (PolozenieY[1] == PolozenieY[0])
		{
			if (PolozenieX[1] == (PolozenieX[0] + 1) || PolozenieX[1] == (PolozenieX[0] - 1))
			{
				tmpl = true;
			}
			else
			{
				cout << "Podano zla wartosc konca statku!\n";
				cout << "Podaj koniec dwumasztowca\n";
				cout << "Kolumna: ";
				PolozenieX[1] = Cin();
//				cin >> PolozenieX[1];
				cout << "Wiersz: ";
				PolozenieY[1] = Cin();
//				cin >> PolozenieY[1];
			}
		}
		else
		{
			cout << "Podano zla wartosc konca statku!\n";
			cout << "Podaj koniec dwumasztowca\n";
			cout << "Kolumna: ";
			PolozenieX[1] = Cin();
//			cin >> PolozenieX[1];
			cout << "Wiersz: ";
			PolozenieY[1] = Cin();
//			cin >> PolozenieY[1];
		}

		if (PolozenieX[1] < 1 || PolozenieY[1] < 1 || PolozenieX[1] > 7 && PolozenieY[1] > 7)
		{
			tmpl = false;
			cout << "Podano zla wartosc konca statku!\n";
			cout << "Podaj koniec dwumasztowca\n";
			cout << "Kolumna: ";
			PolozenieX[1] = Cin();
			//			cin >> PolozenieX[2];
			cout << "Wiersz: ";
			PolozenieY[1] = Cin();
			//			cin >> PolozenieY[2];
		}
	} while (tmpl == false);
	for (int i = 0; i < dlugosc; i++)
	{
		trafienie.push_back(false);
	}
}

Dwumasztowiec::Dwumasztowiec(int _id, bool Bot)
{
	bool tmpl = false;
	int TMPL;
	id = _id;
	dlugosc = 2;
	for (int n = 0; n < dlugosc; n++)
	{
		PolozenieX.push_back(0);
		PolozenieY.push_back(0);
	}
	PolozenieX[0] = ((rand() % 7) + 1);
	PolozenieY[0] = ((rand() % 7) + 1);
	//Ograniczenia ze wzglêdu na miejsce roz³o¿enia dwumasztowca
	if (PolozenieX[0] != 1 && PolozenieX[0] !=7 && PolozenieY[0] != 1 && PolozenieY[0] != 7)
	{
		TMPL = ((rand() % 4) + 1);
		if (TMPL == 1)
		{
			PolozenieX[1] = PolozenieX[0] - 1;
			PolozenieY[1] = PolozenieY[0];
		}
		else if (TMPL == 2 || TMPL == 4)
		{
			PolozenieX[1] = PolozenieX[0];
			if (TMPL == 2)
			{
				PolozenieY[1] = PolozenieY[0] - 1;
			}
			else if (TMPL == 4)
			{
				PolozenieY[1] = PolozenieY[0] + 1;
			}
		}
		else if (TMPL == 3)
		{
			PolozenieX[1] = PolozenieX[0] + 1;
			PolozenieY[1] = PolozenieY[0];
		}
	}
	else if (PolozenieX[0] == 1 && PolozenieY[0] == 1)
	{
		TMPL = ((rand() % 2) + 1);
		if (TMPL == 1)
		{
			PolozenieX[1] = PolozenieX[0];
			PolozenieY[1] = PolozenieY[0]+1;
		}
		else if (TMPL == 2)
		{
			PolozenieX[1] = PolozenieX[0]+1;
			PolozenieY[1] = PolozenieY[0];
		}
	}
	else if (PolozenieX[0] == 7 && PolozenieY[0] == 1)
	{
		TMPL = ((rand() % 2) + 1);
		if (TMPL == 1)
		{
			PolozenieX[1] = PolozenieX[0];
			PolozenieY[1] = PolozenieY[0] + 1;
		}
		else if (TMPL == 2)
		{
			PolozenieX[1] = PolozenieX[0]-1;
			PolozenieY[1] = PolozenieY[0];
		}
	}
	else if (PolozenieX[0] == 7 && PolozenieY[0] == 7)
	{
		TMPL = ((rand() % 2) + 1);
		if (TMPL == 1)
		{
			PolozenieX[1] = PolozenieX[0];
			PolozenieY[1] = PolozenieY[0] - 1;
		}
		else if (TMPL == 2)
		{
			PolozenieX[1] = PolozenieX[0] - 1;
			PolozenieY[1] = PolozenieY[0];
		}
	}
	else if (PolozenieX[0] == 1 && PolozenieY[0] == 7)
	{
		TMPL = ((rand() % 2) + 1);
		if (TMPL == 1)
		{
			PolozenieX[1] = PolozenieX[0];
			PolozenieY[1] = PolozenieY[0] - 1;
		}
		else if (TMPL == 2)
		{
			PolozenieX[1] = PolozenieX[0] + 1;
			PolozenieY[1] = PolozenieY[0];
		}
	}
	else if (PolozenieX[0] == 1 && (PolozenieY[0] == 2 || PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5 || PolozenieY[0] == 6))
	{
		TMPL = ((rand() % 3) + 1);
		if (TMPL == 1)
		{
			PolozenieX[1] = PolozenieX[0];
			PolozenieY[1] = PolozenieY[0] - 1;
		}
		else if (TMPL == 2)
		{
			PolozenieX[1] = PolozenieX[0]+1;
			PolozenieY[1] = PolozenieY[0];
		}
		else if (TMPL == 3)
		{
			PolozenieX[1] = PolozenieX[0];
			PolozenieY[1] = PolozenieY[0]+1;
		}
	}
	else if (PolozenieX[0] == 7 && (PolozenieY[0] == 2 || PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5 || PolozenieY[0] == 6))
	{
		TMPL = ((rand() % 3) + 1);
		if (TMPL == 1)
		{
			PolozenieX[1] = PolozenieX[0];
			PolozenieY[1] = PolozenieY[0] - 1;
		}
		else if (TMPL == 2)
		{
			PolozenieX[1] = PolozenieX[0] - 1;
			PolozenieY[1] = PolozenieY[0];
		}
		else if (TMPL == 3)
		{
			PolozenieX[1] = PolozenieX[0];
			PolozenieY[1] = PolozenieY[0] + 1;
		}
	}
	else if (PolozenieY[0] == 7 && (PolozenieX[0] == 2 || PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5 || PolozenieX[0] == 6))
	{
		TMPL = ((rand() % 3) + 1);
		if (TMPL == 1)
		{
			PolozenieX[1] = PolozenieX[0]-1;
			PolozenieY[1] = PolozenieY[0];
		}
		else if (TMPL == 2)
		{
			PolozenieX[1] = PolozenieX[0]+1;
			PolozenieY[1] = PolozenieY[0];
		}
		else if (TMPL == 3)
		{
			PolozenieX[1] = PolozenieX[0];
			PolozenieY[1] = PolozenieY[0]-1;
		}
	}
	else if (PolozenieY[0] == 1 && (PolozenieX[0] == 2 || PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5 || PolozenieX[0] == 6))
	{
		TMPL = ((rand() % 3) + 1);
		if (TMPL == 1)
		{
			PolozenieX[1] = PolozenieX[0] - 1;
			PolozenieY[1] = PolozenieY[0];
		}
		else if (TMPL == 2)
		{
			PolozenieX[1] = PolozenieX[0] + 1;
			PolozenieY[1] = PolozenieY[0];
		}
		else if (TMPL == 3)
		{
			PolozenieX[1] = PolozenieX[0];
			PolozenieY[1] = PolozenieY[0] + 1;
		}
	}
	
	do
	{
		//Test odpowiednio dobranego pocz¹tku i koñca dwumasztowce dla tej samej wartoœci X
		if (PolozenieX[1] == PolozenieX[0])
		{
			if (PolozenieY[1] == (PolozenieY[0] + 1) || PolozenieY[1] == (PolozenieY[0] - 1))
			{
				tmpl = true;
			}
			else
			{
				//Ograniczenia ze wzglêdu na miejsce roz³o¿enia dwumasztowca
				if (PolozenieX[0] != 1 && PolozenieX[0] != 7 && PolozenieY[0] != 1 && PolozenieY[0] != 7)
				{
					TMPL = ((rand() % 4) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0] - 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 2 || TMPL == 4)
					{
						PolozenieX[1] = PolozenieX[0];
						if (TMPL == 2)
						{
							PolozenieY[1] = PolozenieY[0] - 1;
						}
						else if (TMPL == 4)
						{
							PolozenieY[1] = PolozenieY[0] + 1;
						}
					}
					else if (TMPL == 3)
					{
						PolozenieX[1] = PolozenieX[0] + 1;
						PolozenieY[1] = PolozenieY[0];
					}
				}
				else if (PolozenieX[0] == 1 && PolozenieY[0] == 1)
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] + 1;
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] + 1;
						PolozenieY[1] = PolozenieY[0];
					}
				}
				else if (PolozenieX[0] == 7 && PolozenieY[0] == 1)
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] + 1;
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] - 1;
						PolozenieY[1] = PolozenieY[0];
					}
				}
				else if (PolozenieX[0] == 7 && PolozenieY[0] == 7)
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] - 1;
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] - 1;
						PolozenieY[1] = PolozenieY[0];
					}
				}
				else if (PolozenieX[0] == 1 && PolozenieY[0] == 7)
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] - 1;
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] + 1;
						PolozenieY[1] = PolozenieY[0];
					}
				}
				else if (PolozenieX[0] == 1 && (PolozenieY[0] == 2 || PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5 || PolozenieY[0] == 6))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] - 1;
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] + 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] + 1;
					}
				}
				else if (PolozenieX[0] == 7 && (PolozenieY[0] == 2 || PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5 || PolozenieY[0] == 6))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] - 1;
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] - 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] + 1;
					}
				}
				else if (PolozenieY[0] == 7 && (PolozenieX[0] == 2 || PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5 || PolozenieX[0] == 6))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0] - 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] + 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] - 1;
					}
				}
				else if (PolozenieY[0] == 1 && (PolozenieX[0] == 2 || PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5 || PolozenieX[0] == 6))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0] - 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] + 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] + 1;
					}
				}
			}
		}
		else if (PolozenieY[1] == PolozenieY[0])
		{
		//Test odpowiednio dobranego pocz¹tku i koñca dwumasztowce dla tej samej wartoœci Y
			if (PolozenieX[1] == (PolozenieX[0] + 1) || PolozenieX[1] == (PolozenieX[0] - 1))
			{
				tmpl = true;
			}
			else
			{
				//Ograniczenia ze wzglêdu na miejsce roz³o¿enia dwumasztowca
				if (PolozenieX[0] != 1 && PolozenieX[0] != 7 && PolozenieY[0] != 1 && PolozenieY[0] != 7)
				{
					TMPL = ((rand() % 4) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0] - 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 2 || TMPL == 4)
					{
						PolozenieX[1] = PolozenieX[0];
						if (TMPL == 2)
						{
							PolozenieY[1] = PolozenieY[0] - 1;
						}
						else if (TMPL == 4)
						{
							PolozenieY[1] = PolozenieY[0] + 1;
						}
					}
					else if (TMPL == 3)
					{
						PolozenieX[1] = PolozenieX[0] + 1;
						PolozenieY[1] = PolozenieY[0];
					}
				}
				else if (PolozenieX[0] == 1 && PolozenieY[0] == 1)
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] + 1;
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] + 1;
						PolozenieY[1] = PolozenieY[0];
					}
				}
				else if (PolozenieX[0] == 7 && PolozenieY[0] == 1)
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] + 1;
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] - 1;
						PolozenieY[1] = PolozenieY[0];
					}
				}
				else if (PolozenieX[0] == 7 && PolozenieY[0] == 7)
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] - 1;
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] - 1;
						PolozenieY[1] = PolozenieY[0];
					}
				}
				else if (PolozenieX[0] == 1 && PolozenieY[0] == 7)
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] - 1;
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] + 1;
						PolozenieY[1] = PolozenieY[0];
					}
				}
				else if (PolozenieX[0] == 1 && (PolozenieY[0] == 2 || PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5 || PolozenieY[0] == 6))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] - 1;
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] + 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] + 1;
					}
				}
				else if (PolozenieX[0] == 7 && (PolozenieY[0] == 2 || PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5 || PolozenieY[0] == 6))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] - 1;
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] - 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] + 1;
					}
				}
				else if (PolozenieY[0] == 7 && (PolozenieX[0] == 2 || PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5 || PolozenieX[0] == 6))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0] - 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] + 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] - 1;
					}
				}
				else if (PolozenieY[0] == 1 && (PolozenieX[0] == 2 || PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5 || PolozenieX[0] == 6))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0] - 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] + 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] + 1;
					}
				}
			}
		}
	} while (tmpl == false);
	for (int i = 0; i < dlugosc; i++)
	{
		trafienie.push_back(false);
	}
}

Dwumasztowiec::~Dwumasztowiec()
{
	cout << "Usuniêto Dwumasztowiec! \n";
}

//Wyj¹tek
void Dwumasztowiec::ZmienPolozenie()
{
	bool OdpowiednieKordynaty = false;
	bool tmpl = false;
	cout << "Podano bledne wspolrzedne!\n";
	do
	{
		try
		{
			cout << "Podaj poczatek dwumasztowca\n";
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
			cout << "Podano z³¹ wartoœæ pocz¹tku dwumasztowca\n";
		}
	} while (OdpowiednieKordynaty == false);
	OdpowiednieKordynaty = false;
	do
	{
		try
		{
			cout << "Podaj koniec dwumasztowca\n";
			cout << "Kolumna: ";
			PolozenieX[1] = Cin();
//			cin >> PolozenieX[1];
			cout << "Wiersz: ";
			PolozenieY[1] = Cin();
//			cin >> PolozenieY[1];
			if ((PolozenieX[1] < 1 || PolozenieX[1] > 7) || (PolozenieY[1] < 1 || PolozenieY[1] > 7))
			{
				throw 'x';
			}
			OdpowiednieKordynaty = true;
		}
		catch (char x)
		{
			cout << "Podano z³¹ wartoœæ koñca dwumasztowca\n";
		}
	} while (OdpowiednieKordynaty == false);
	do
	{
		if (PolozenieX[1] == PolozenieX[0])
		{
			if (PolozenieY[1] == (PolozenieY[0] + 1) || PolozenieY[1] == (PolozenieY[0] - 1))
			{
				tmpl = true;
			}
			else
			{
				cout << "Podano zla wartosc konca statku!\n";
				cout << "Podaj koniec dwumasztowca\n";
				cout << "Kolumna: ";
				PolozenieX[1] = Cin();
//				cin >> PolozenieX[1];
				cout << "Wiersz: ";
				PolozenieY[1] = Cin();
//				cin >> PolozenieY[1];
			}
		}
		else if (PolozenieY[1] == PolozenieY[0])
		{
			if (PolozenieX[1] == (PolozenieX[0] + 1) || PolozenieX[1] == (PolozenieX[0] - 1))
			{
				tmpl = true;
			}
			else
			{
				cout << "Podano zla wartosc konca statku!\n";
				cout << "Podaj koniec dwumasztowca\n";
				cout << "Kolumna: ";
				PolozenieX[1] = Cin();
//				cin >> PolozenieX[1];
				cout << "Wiersz: ";
				PolozenieY[1] = Cin();
//				cin >> PolozenieY[1];
			}
		}
		else
		{
			cout << "Podano zla wartosc konca statku!\n";
			cout << "Podaj koniec dwumasztowca\n";
			cout << "Kolumna: ";
			PolozenieX[1] = Cin();
//			cin >> PolozenieX[1];
			cout << "Wiersz: ";
			PolozenieY[1] = Cin();
//			cin >> PolozenieY[1];
		}

		if (PolozenieX[1] < 1 || PolozenieY[1] < 1 || PolozenieX[1] > 7 && PolozenieY[1] > 7)
		{
			tmpl = false;
			cout << "Podano zla wartosc konca statku!\n";
			cout << "Podaj koniec dwumasztowca\n";
			cout << "Kolumna: ";
			PolozenieX[1] = Cin();
			//			cin >> PolozenieX[2];
			cout << "Wiersz: ";
			PolozenieY[1] = Cin();
			//			cin >> PolozenieY[2];
		}
	} while (tmpl == false);
}

void Dwumasztowiec::ZmienPolozenie(bool Bot)
{
	bool tmpl = false;
	int TMPL;
	PolozenieX[0] = ((rand() % 7) + 1);
	PolozenieY[0] = ((rand() % 7) + 1);
	TMPL = ((rand() % 4) + 1);
	if (PolozenieX[0] != 1 && PolozenieX[0] != 7 && PolozenieY[0] != 1 && PolozenieY[0] != 7)
	{
		TMPL = ((rand() % 4) + 1);
		if (TMPL == 1)
		{
			PolozenieX[1] = PolozenieX[0] - 1;
			PolozenieY[1] = PolozenieY[0];
		}
		else if (TMPL == 2 || TMPL == 4)
		{
			PolozenieX[1] = PolozenieX[0];
			if (TMPL == 2)
			{
				PolozenieY[1] = PolozenieY[0] - 1;
			}
			else if (TMPL == 4)
			{
				PolozenieY[1] = PolozenieY[0] + 1;
			}
		}
		else if (TMPL == 3)
		{
			PolozenieX[1] = PolozenieX[0] + 1;
			PolozenieY[1] = PolozenieY[0];
		}
	}
	else if (PolozenieX[0] == 1 && PolozenieY[0] == 1)
	{
		TMPL = ((rand() % 2) + 1);
		if (TMPL == 1)
		{
			PolozenieX[1] = PolozenieX[0];
			PolozenieY[1] = PolozenieY[0] + 1;
		}
		else if (TMPL == 2)
		{
			PolozenieX[1] = PolozenieX[0] + 1;
			PolozenieY[1] = PolozenieY[0];
		}
	}
	else if (PolozenieX[0] == 7 && PolozenieY[0] == 1)
	{
		TMPL = ((rand() % 2) + 1);
		if (TMPL == 1)
		{
			PolozenieX[1] = PolozenieX[0];
			PolozenieY[1] = PolozenieY[0] + 1;
		}
		else if (TMPL == 2)
		{
			PolozenieX[1] = PolozenieX[0] - 1;
			PolozenieY[1] = PolozenieY[0];
		}
	}
	else if (PolozenieX[0] == 7 && PolozenieY[0] == 7)
	{
		TMPL = ((rand() % 2) + 1);
		if (TMPL == 1)
		{
			PolozenieX[1] = PolozenieX[0];
			PolozenieY[1] = PolozenieY[0] - 1;
		}
		else if (TMPL == 2)
		{
			PolozenieX[1] = PolozenieX[0] - 1;
			PolozenieY[1] = PolozenieY[0];
		}
	}
	else if (PolozenieX[0] == 1 && PolozenieY[0] == 7)
	{
		TMPL = ((rand() % 2) + 1);
		if (TMPL == 1)
		{
			PolozenieX[1] = PolozenieX[0];
			PolozenieY[1] = PolozenieY[0] - 1;
		}
		else if (TMPL == 2)
		{
			PolozenieX[1] = PolozenieX[0] + 1;
			PolozenieY[1] = PolozenieY[0];
		}
	}
	else if (PolozenieX[0] == 1 && (PolozenieY[0] == 2 || PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5 || PolozenieY[0] == 6))
	{
		TMPL = ((rand() % 3) + 1);
		if (TMPL == 1)
		{
			PolozenieX[1] = PolozenieX[0];
			PolozenieY[1] = PolozenieY[0] - 1;
		}
		else if (TMPL == 2)
		{
			PolozenieX[1] = PolozenieX[0] + 1;
			PolozenieY[1] = PolozenieY[0];
		}
		else if (TMPL == 3)
		{
			PolozenieX[1] = PolozenieX[0];
			PolozenieY[1] = PolozenieY[0] + 1;
		}
	}
	else if (PolozenieX[0] == 7 && (PolozenieY[0] == 2 || PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5 || PolozenieY[0] == 6))
	{
		TMPL = ((rand() % 3) + 1);
		if (TMPL == 1)
		{
			PolozenieX[1] = PolozenieX[0];
			PolozenieY[1] = PolozenieY[0] - 1;
		}
		else if (TMPL == 2)
		{
			PolozenieX[1] = PolozenieX[0] - 1;
			PolozenieY[1] = PolozenieY[0];
		}
		else if (TMPL == 3)
		{
			PolozenieX[1] = PolozenieX[0];
			PolozenieY[1] = PolozenieY[0] + 1;
		}
	}
	else if (PolozenieY[0] == 7 && (PolozenieX[0] == 2 || PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5 || PolozenieX[0] == 6))
	{
		TMPL = ((rand() % 3) + 1);
		if (TMPL == 1)
		{
			PolozenieX[1] = PolozenieX[0] - 1;
			PolozenieY[1] = PolozenieY[0];
		}
		else if (TMPL == 2)
		{
			PolozenieX[1] = PolozenieX[0] + 1;
			PolozenieY[1] = PolozenieY[0];
		}
		else if (TMPL == 3)
		{
			PolozenieX[1] = PolozenieX[0];
			PolozenieY[1] = PolozenieY[0] - 1;
		}
	}
	else if (PolozenieY[0] == 1 && (PolozenieX[0] == 2 || PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5 || PolozenieX[0] == 6))
	{
		TMPL = ((rand() % 3) + 1);
		if (TMPL == 1)
		{
			PolozenieX[1] = PolozenieX[0] - 1;
			PolozenieY[1] = PolozenieY[0];
		}
		else if (TMPL == 2)
		{
			PolozenieX[1] = PolozenieX[0] + 1;
			PolozenieY[1] = PolozenieY[0];
		}
		else if (TMPL == 3)
		{
			PolozenieX[1] = PolozenieX[0];
			PolozenieY[1] = PolozenieY[0] + 1;
		}
	}
	do
	{
		if (PolozenieX[1] == PolozenieX[0])
		{
			if (PolozenieY[1] == (PolozenieY[0] + 1) || PolozenieY[1] == (PolozenieY[0] - 1))
			{
				tmpl = true;
			}
			else
			{
				if (PolozenieX[0] != 1 && PolozenieX[0] != 7 && PolozenieY[0] != 1 && PolozenieY[0] != 7)
				{
					TMPL = ((rand() % 4) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0] - 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 2 || TMPL == 4)
					{
						PolozenieX[1] = PolozenieX[0];
						if (TMPL == 2)
						{
							PolozenieY[1] = PolozenieY[0] - 1;
						}
						else if (TMPL == 4)
						{
							PolozenieY[1] = PolozenieY[0] + 1;
						}
					}
					else if (TMPL == 3)
					{
						PolozenieX[1] = PolozenieX[0] + 1;
						PolozenieY[1] = PolozenieY[0];
					}
				}
				else if (PolozenieX[0] == 1 && PolozenieY[0] == 1)
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] + 1;
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] + 1;
						PolozenieY[1] = PolozenieY[0];
					}
				}
				else if (PolozenieX[0] == 7 && PolozenieY[0] == 1)
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] + 1;
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] - 1;
						PolozenieY[1] = PolozenieY[0];
					}
				}
				else if (PolozenieX[0] == 7 && PolozenieY[0] == 7)
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] - 1;
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] - 1;
						PolozenieY[1] = PolozenieY[0];
					}
				}
				else if (PolozenieX[0] == 1 && PolozenieY[0] == 7)
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] - 1;
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] + 1;
						PolozenieY[1] = PolozenieY[0];
					}
				}
				else if (PolozenieX[0] == 1 && (PolozenieY[0] == 2 || PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5 || PolozenieY[0] == 6))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] - 1;
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] + 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] + 1;
					}
				}
				else if (PolozenieX[0] == 7 && (PolozenieY[0] == 2 || PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5 || PolozenieY[0] == 6))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] - 1;
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] - 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] + 1;
					}
				}
				else if (PolozenieY[0] == 7 && (PolozenieX[0] == 2 || PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5 || PolozenieX[0] == 6))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0] - 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] + 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] - 1;
					}
				}
				else if (PolozenieY[0] == 1 && (PolozenieX[0] == 2 || PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5 || PolozenieX[0] == 6))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0] - 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] + 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] + 1;
					}
				}
			}
		}
		else if (PolozenieY[1] == PolozenieY[0])
		{
			if (PolozenieX[1] == (PolozenieX[0] + 1) || PolozenieX[1] == (PolozenieX[0] - 1))
			{
				tmpl = true;
			}
			else
			{
				if (PolozenieX[0] != 1 && PolozenieX[0] != 7 && PolozenieY[0] != 1 && PolozenieY[0] != 7)
				{
					TMPL = ((rand() % 4) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0] - 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 2 || TMPL == 4)
					{
						PolozenieX[1] = PolozenieX[0];
						if (TMPL == 2)
						{
							PolozenieY[1] = PolozenieY[0] - 1;
						}
						else if (TMPL == 4)
						{
							PolozenieY[1] = PolozenieY[0] + 1;
						}
					}
					else if (TMPL == 3)
					{
						PolozenieX[1] = PolozenieX[0] + 1;
						PolozenieY[1] = PolozenieY[0];
					}
				}
				else if (PolozenieX[0] == 1 && PolozenieY[0] == 1)
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] + 1;
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] + 1;
						PolozenieY[1] = PolozenieY[0];
					}
				}
				else if (PolozenieX[0] == 7 && PolozenieY[0] == 1)
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] + 1;
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] - 1;
						PolozenieY[1] = PolozenieY[0];
					}
				}
				else if (PolozenieX[0] == 7 && PolozenieY[0] == 7)
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] - 1;
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] - 1;
						PolozenieY[1] = PolozenieY[0];
					}
				}
				else if (PolozenieX[0] == 1 && PolozenieY[0] == 7)
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] - 1;
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] + 1;
						PolozenieY[1] = PolozenieY[0];
					}
				}
				else if (PolozenieX[0] == 1 && (PolozenieY[0] == 2 || PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5 || PolozenieY[0] == 6))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] - 1;
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] + 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] + 1;
					}
				}
				else if (PolozenieX[0] == 7 && (PolozenieY[0] == 2 || PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5 || PolozenieY[0] == 6))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] - 1;
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] - 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] + 1;
					}
				}
				else if (PolozenieY[0] == 7 && (PolozenieX[0] == 2 || PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5 || PolozenieX[0] == 6))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0] - 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] + 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] - 1;
					}
				}
				else if (PolozenieY[0] == 1 && (PolozenieX[0] == 2 || PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5 || PolozenieX[0] == 6))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[1] = PolozenieX[0] - 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 2)
					{
						PolozenieX[1] = PolozenieX[0] + 1;
						PolozenieY[1] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[1] = PolozenieX[0];
						PolozenieY[1] = PolozenieY[0] + 1;
					}
				}
			}
		}
		else
		{
			if (PolozenieX[0] != 1 && PolozenieX[0] != 7 && PolozenieY[0] != 1 && PolozenieY[0] != 7)
			{
				TMPL = ((rand() % 4) + 1);
				if (TMPL == 1)
				{
					PolozenieX[1] = PolozenieX[0] - 1;
					PolozenieY[1] = PolozenieY[0];
				}
				else if (TMPL == 2 || TMPL == 4)
				{
					PolozenieX[1] = PolozenieX[0];
					if (TMPL == 2)
					{
						PolozenieY[1] = PolozenieY[0] - 1;
					}
					else if (TMPL == 4)
					{
						PolozenieY[1] = PolozenieY[0] + 1;
					}
				}
				else if (TMPL == 3)
				{
					PolozenieX[1] = PolozenieX[0] + 1;
					PolozenieY[1] = PolozenieY[0];
				}
			}
			else if (PolozenieX[0] == 1 && PolozenieY[0] == 1)
			{
				TMPL = ((rand() % 2) + 1);
				if (TMPL == 1)
				{
					PolozenieX[1] = PolozenieX[0];
					PolozenieY[1] = PolozenieY[0] + 1;
				}
				else if (TMPL == 2)
				{
					PolozenieX[1] = PolozenieX[0] + 1;
					PolozenieY[1] = PolozenieY[0];
				}
			}
			else if (PolozenieX[0] == 7 && PolozenieY[0] == 1)
			{
				TMPL = ((rand() % 2) + 1);
				if (TMPL == 1)
				{
					PolozenieX[1] = PolozenieX[0];
					PolozenieY[1] = PolozenieY[0] + 1;
				}
				else if (TMPL == 2)
				{
					PolozenieX[1] = PolozenieX[0] - 1;
					PolozenieY[1] = PolozenieY[0];
				}
			}
			else if (PolozenieX[0] == 7 && PolozenieY[0] == 7)
			{
				TMPL = ((rand() % 2) + 1);
				if (TMPL == 1)
				{
					PolozenieX[1] = PolozenieX[0];
					PolozenieY[1] = PolozenieY[0] - 1;
				}
				else if (TMPL == 2)
				{
					PolozenieX[1] = PolozenieX[0] - 1;
					PolozenieY[1] = PolozenieY[0];
				}
			}
			else if (PolozenieX[0] == 1 && PolozenieY[0] == 7)
			{
				TMPL = ((rand() % 2) + 1);
				if (TMPL == 1)
				{
					PolozenieX[1] = PolozenieX[0];
					PolozenieY[1] = PolozenieY[0] - 1;
				}
				else if (TMPL == 2)
				{
					PolozenieX[1] = PolozenieX[0] + 1;
					PolozenieY[1] = PolozenieY[0];
				}
			}
			else if (PolozenieX[0] == 1 && (PolozenieY[0] == 2 || PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5 || PolozenieY[0] == 6))
			{
				TMPL = ((rand() % 3) + 1);
				if (TMPL == 1)
				{
					PolozenieX[1] = PolozenieX[0];
					PolozenieY[1] = PolozenieY[0] - 1;
				}
				else if (TMPL == 2)
				{
					PolozenieX[1] = PolozenieX[0] + 1;
					PolozenieY[1] = PolozenieY[0];
				}
				else if (TMPL == 3)
				{
					PolozenieX[1] = PolozenieX[0];
					PolozenieY[1] = PolozenieY[0] + 1;
				}
			}
			else if (PolozenieX[0] == 7 && (PolozenieY[0] == 2 || PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5 || PolozenieY[0] == 6))
			{
				TMPL = ((rand() % 3) + 1);
				if (TMPL == 1)
				{
					PolozenieX[1] = PolozenieX[0];
					PolozenieY[1] = PolozenieY[0] - 1;
				}
				else if (TMPL == 2)
				{
					PolozenieX[1] = PolozenieX[0] - 1;
					PolozenieY[1] = PolozenieY[0];
				}
				else if (TMPL == 3)
				{
					PolozenieX[1] = PolozenieX[0];
					PolozenieY[1] = PolozenieY[0] + 1;
				}
			}
			else if (PolozenieY[0] == 7 && (PolozenieX[0] == 2 || PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5 || PolozenieX[0] == 6))
			{
				TMPL = ((rand() % 3) + 1);
				if (TMPL == 1)
				{
					PolozenieX[1] = PolozenieX[0] - 1;
					PolozenieY[1] = PolozenieY[0];
				}
				else if (TMPL == 2)
				{
					PolozenieX[1] = PolozenieX[0] + 1;
					PolozenieY[1] = PolozenieY[0];
				}
				else if (TMPL == 3)
				{
					PolozenieX[1] = PolozenieX[0];
					PolozenieY[1] = PolozenieY[0] - 1;
				}
			}
			else if (PolozenieY[0] == 1 && (PolozenieX[0] == 2 || PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5 || PolozenieX[0] == 6))
			{
				TMPL = ((rand() % 3) + 1);
				if (TMPL == 1)
				{
					PolozenieX[1] = PolozenieX[0] - 1;
					PolozenieY[1] = PolozenieY[0];
				}
				else if (TMPL == 2)
				{
					PolozenieX[1] = PolozenieX[0] + 1;
					PolozenieY[1] = PolozenieY[0];
				}
				else if (TMPL == 3)
				{
					PolozenieX[1] = PolozenieX[0];
					PolozenieY[1] = PolozenieY[0] + 1;
				}
			}
		}

	} while (tmpl == false);
}

void Dwumasztowiec::SprawdzZatopienie()
{
	if (trafienie[0] == true)
	{
		if (trafienie[1] == true)
		{
			zatopiony = true;
		}
	}
	else
	{
		zatopiony = false;
	}
}

void Dwumasztowiec::ZatopCzesc(int x, int y)
{
	for (int n = 0; n < dlugosc; n++)
	{
		if (x == PolozenieX[n] && y == PolozenieY[n])
		{
			trafienie[n] = true;
			ZatopCalosc();
		}
	}
}

void Dwumasztowiec::ZatopCalosc()
{
	if (trafienie[0] == true && trafienie[1] == true)
	{
		cout << endl;
		cout << "---------------------------\n";
		cout << "Zatopiono dwumasztowiec!\n";
		cout << "---------------------------\n";
		zatopiony = true;
	}
}


