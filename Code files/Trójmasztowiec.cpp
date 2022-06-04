#include "Trójmasztowiec.h"

//Wyj¹tek
Trójmasztowiec::Trójmasztowiec(int _id)
{
	bool OdpowiednieKordynaty = false;
	bool tmpl = false;
	id = _id;
	dlugosc = 3;
	for (int n = 0; n < dlugosc; n++)
	{
		PolozenieX.push_back(0);
		PolozenieY.push_back(0);
	}
	do
	{
		try
		{
			cout << "Podaj poczatek trójmasztowca\n";
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
			cout << "Podano z³¹ wartoœæ pocz¹tku trójmasztowca\n";
		}
	} while (OdpowiednieKordynaty == false);
	OdpowiednieKordynaty = false;
	do
	{
		try
		{
			cout << "Podaj koniec trójmasztowca\n";
			cout << "Kolumna: ";
			PolozenieX[2] = Cin();
//			cin >> PolozenieX[2];
			cout << "Wiersz: ";
			PolozenieY[2] = Cin();
//			cin >> PolozenieY[2];
			if ((PolozenieX[2] < 1 || PolozenieX[2] > 7) || (PolozenieY[2] < 1 || PolozenieY[2] > 7))
			{
				throw 'x';
			}
			OdpowiednieKordynaty = true;
		}
		catch (char x)
		{
			cout << "Podano z³¹ wartoœæ koñca trójmasztowca\n";
		}
	} while (OdpowiednieKordynaty == false);
	do
	{
		if (PolozenieX[2] == PolozenieX[0])
		{
			if (PolozenieY[2] == (PolozenieY[0] + 2) || PolozenieY[2] == (PolozenieY[0] - 2))
			{
				tmpl = true;
			}
			else
			{
				cout << "Podano zla wartosc konca statku!\n";
				cout << "Podaj koniec trójmasztowca\n";
				cout << "Kolumna: ";
				PolozenieX[2] = Cin();
//				cin >> PolozenieX[2];
				cout << "Wiersz: ";
				PolozenieY[2] = Cin();
//				cin >> PolozenieY[2];
			}
		}
		else if (PolozenieY[2] == PolozenieY[0])
		{
			if (PolozenieX[2] == (PolozenieX[0] + 2) || PolozenieX[2] == (PolozenieX[0] - 2))
			{
					tmpl = true;
			}
			else
			{
				cout << "Podano zla wartosc konca statku!\n";
				cout << "Podaj koniec trójmasztowca\n";
				cout << "Kolumna: ";
				PolozenieX[2] = Cin();
//				cin >> PolozenieX[2];
				cout << "Wiersz: ";
				PolozenieY[2] = Cin();
//				cin >> PolozenieY[2];
			}
		}
		else
		{
			cout << "Podano zla wartosc konca statku!\n";
			cout << "Podaj koniec trójmasztowca\n";
			cout << "Kolumna: ";
			PolozenieX[2] = Cin();
//			cin >> PolozenieX[2];
			cout << "Wiersz: ";
			PolozenieY[2] = Cin();
//			cin >> PolozenieY[2];
		}

		if (PolozenieX[2] < 1 || PolozenieY[2] < 1 || PolozenieX[2] > 7 && PolozenieY[2] > 7)
		{
			tmpl = false;
			cout << "Podano zla wartosc konca statku!\n";
			cout << "Podaj koniec trójmasztowca\n";
			cout << "Kolumna: ";
			PolozenieX[2] = Cin();
			//			cin >> PolozenieX[2];
			cout << "Wiersz: ";
			PolozenieY[2] = Cin();
			//			cin >> PolozenieY[2];
		}
	} while (tmpl == false);
	PolozenieX[1] = (PolozenieX[0] + PolozenieX[2]) / 2;
	PolozenieY[1] = (PolozenieY[0] + PolozenieY[2]) / 2;
	for (int i = 0; i < dlugosc; i++)
	{
		trafienie.push_back(false);
	}
}

Trójmasztowiec::Trójmasztowiec(int _id, bool Bot)
{
	bool tmpl = false;
	int TMPL;
	id = _id;
	dlugosc = 3;
	for (int n = 0; n < dlugosc; n++)
	{
		PolozenieX.push_back(0);
		PolozenieY.push_back(0);
	}
	PolozenieX[0] = ((rand() % 7) + 1);
	PolozenieY[0] = ((rand() % 7) + 1);

	if (PolozenieX[0] != 1 && PolozenieX[0] != 2 && PolozenieX[0] != 6 && PolozenieX[0] != 7 && PolozenieY[0] != 1 && PolozenieY[0] != 2 && PolozenieY[0] != 6 && PolozenieY[0] != 7)
	{
		TMPL = ((rand() % 4) + 1);
		if (TMPL == 1)
		{
			PolozenieX[2] = PolozenieX[0] - 2;
			PolozenieY[2] = PolozenieY[0];
		}
		else if (TMPL == 2 || TMPL == 4)
		{
			PolozenieX[2] = PolozenieX[0];
			if (TMPL == 2)
			{
				PolozenieY[2] = PolozenieY[0] - 2;
			}
			else if (TMPL == 4)
			{
				PolozenieY[2] = PolozenieY[0] + 2;
			}
		}
		else if (TMPL == 3)
		{
			PolozenieX[2] = PolozenieX[0] + 2;
			PolozenieY[2] = PolozenieY[0];
		}
	}
	else if ((PolozenieX[0] == 1 && PolozenieY[0] == 1) || (PolozenieX[0] == 1 && PolozenieY[0] == 2) || (PolozenieX[0] == 2 && PolozenieY[0] == 1) || (PolozenieX[0] == 2 && PolozenieY[0] == 2))
	{
		TMPL = ((rand() % 2) + 1);
		if (TMPL == 1)
		{
			PolozenieX[2] = PolozenieX[0];
			PolozenieY[2] = PolozenieY[0] + 2;
		}
		else if (TMPL == 2)
		{
			PolozenieX[2] = PolozenieX[0] + 2;
			PolozenieY[2] = PolozenieY[0];
		}
	}
	else if ((PolozenieX[0] == 7 && PolozenieY[0] == 1) || (PolozenieX[0] == 7 && PolozenieY[0] == 2) || (PolozenieX[0] == 6 && PolozenieY[0] == 1) || (PolozenieX[0] == 6 && PolozenieY[0] == 2))
	{
		TMPL = ((rand() % 2) + 1);
		if (TMPL == 1)
		{
			PolozenieX[2] = PolozenieX[0];
			PolozenieY[2] = PolozenieY[0] + 2;
		}
		else if (TMPL == 2)
		{
			PolozenieX[2] = PolozenieX[0] - 2;
			PolozenieY[2] = PolozenieY[0];
		}
	}
	else if ((PolozenieX[0] == 7 && PolozenieY[0] == 7) || (PolozenieX[0] == 7 && PolozenieY[0] == 6) || (PolozenieX[0] == 6 && PolozenieY[0] == 7) || (PolozenieX[0] == 6 && PolozenieY[0] == 6))
	{
		TMPL = ((rand() % 2) + 1);
		if (TMPL == 1)
		{
			PolozenieX[2] = PolozenieX[0];
			PolozenieY[2] = PolozenieY[0] - 2;
		}
		else if (TMPL == 2)
		{
			PolozenieX[2] = PolozenieX[0] - 2;
			PolozenieY[2] = PolozenieY[0];
		}
	}
	else if ((PolozenieX[0] == 1 && PolozenieY[0] == 7) || (PolozenieX[0] == 1 && PolozenieY[0] == 6) || (PolozenieX[0] == 2 && PolozenieY[0] == 7) || (PolozenieX[0] == 2 && PolozenieY[0] == 6))
	{
		TMPL = ((rand() % 2) + 1);
		if (TMPL == 1)
		{
			PolozenieX[2] = PolozenieX[0];
			PolozenieY[2] = PolozenieY[0] - 2;
		}
		else if (TMPL == 2)
		{
			PolozenieX[2] = PolozenieX[0] + 2;
			PolozenieY[2] = PolozenieY[0];
		}
	}
	else if ((PolozenieX[0] == 1 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)) || (PolozenieX[0] == 2 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)))
	{
		TMPL = ((rand() % 3) + 1);
		if (TMPL == 1)
		{
			PolozenieX[2] = PolozenieX[0];
			PolozenieY[2] = PolozenieY[0] - 2;
		}
		else if (TMPL == 2)
		{
			PolozenieX[2] = PolozenieX[0] + 2;
			PolozenieY[2] = PolozenieY[0];
		}
		else if (TMPL == 3)
		{
			PolozenieX[2] = PolozenieX[0];
			PolozenieY[2] = PolozenieY[0] + 2;
		}
	}
	else if ((PolozenieX[0] == 7 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)) || (PolozenieX[0] == 6 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)))
	{
		TMPL = ((rand() % 3) + 1);
		if (TMPL == 1)
		{
			PolozenieX[2] = PolozenieX[0];
			PolozenieY[2] = PolozenieY[0] - 2;
		}
		else if (TMPL == 2)
		{
			PolozenieX[2] = PolozenieX[0] - 2;
			PolozenieY[2] = PolozenieY[0];
		}
		else if (TMPL == 3)
		{
			PolozenieX[2] = PolozenieX[0];
			PolozenieY[2] = PolozenieY[0] + 2;
		}
	}
	else if ((PolozenieY[0] == 7 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)) || (PolozenieY[0] == 6 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)))
	{
		TMPL = ((rand() % 3) + 1);
		if (TMPL == 1)
		{
			PolozenieX[2] = PolozenieX[0] - 2;
			PolozenieY[2] = PolozenieY[0];
		}
		else if (TMPL == 2)
		{
			PolozenieX[2] = PolozenieX[0] + 2;
			PolozenieY[2] = PolozenieY[0];
		}
		else if (TMPL == 3)
		{
			PolozenieX[2] = PolozenieX[0];
			PolozenieY[2] = PolozenieY[0] - 2;
		}
	}
	else if ((PolozenieY[0] == 1 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)) || (PolozenieY[0] == 2 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)))
	{
		TMPL = ((rand() % 3) + 1);
		if (TMPL == 1)
		{
			PolozenieX[2] = PolozenieX[0] - 2;
			PolozenieY[2] = PolozenieY[0];
		}
		else if (TMPL == 2)
		{
			PolozenieX[2] = PolozenieX[0] + 2;
			PolozenieY[2] = PolozenieY[0];
		}
		else if (TMPL == 3)
		{
			PolozenieX[2] = PolozenieX[0];
			PolozenieY[2] = PolozenieY[0] + 2;
		}
	}

	do
	{
		if (PolozenieX[2] == PolozenieX[0])
		{
			if (PolozenieY[2] == (PolozenieY[0] + 2) || PolozenieY[2] == (PolozenieY[0] - 2))
			{
				tmpl = true;
			}
			else
			{
				if (PolozenieX[0] != 1 && PolozenieX[0] != 2 && PolozenieX[0] != 6 && PolozenieX[0] != 7 && PolozenieY[0] != 1 && PolozenieY[0] != 2 && PolozenieY[0] != 6 && PolozenieY[0] != 7)
				{
					TMPL = ((rand() % 4) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0] - 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 2 || TMPL == 4)
					{
						PolozenieX[2] = PolozenieX[0];
						if (TMPL == 2)
						{
							PolozenieY[2] = PolozenieY[0] - 2;
						}
						else if (TMPL == 4)
						{
							PolozenieY[2] = PolozenieY[0] + 2;
						}
					}
					else if (TMPL == 3)
					{
						PolozenieX[2] = PolozenieX[0] + 2;
						PolozenieY[2] = PolozenieY[0];
					}
				}
				else if ((PolozenieX[0] == 1 && PolozenieY[0] == 1) || (PolozenieX[0] == 1 && PolozenieY[0] == 2) || (PolozenieX[0] == 2 && PolozenieY[0] == 1) || (PolozenieX[0] == 2 && PolozenieY[0] == 2))
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] + 2;
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] + 2;
						PolozenieY[2] = PolozenieY[0];
					}
				}
				else if ((PolozenieX[0] == 7 && PolozenieY[0] == 1) || (PolozenieX[0] == 7 && PolozenieY[0] == 2) || (PolozenieX[0] == 6 && PolozenieY[0] == 1) || (PolozenieX[0] == 6 && PolozenieY[0] == 2))
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] + 2;
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] - 2;
						PolozenieY[2] = PolozenieY[0];
					}
				}
				else if ((PolozenieX[0] == 7 && PolozenieY[0] == 7) || (PolozenieX[0] == 7 && PolozenieY[0] == 6) || (PolozenieX[0] == 6 && PolozenieY[0] == 7) || (PolozenieX[0] == 6 && PolozenieY[0] == 6))
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] - 2;
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] - 2;
						PolozenieY[2] = PolozenieY[0];
					}
				}
				else if ((PolozenieX[0] == 1 && PolozenieY[0] == 7) || (PolozenieX[0] == 1 && PolozenieY[0] == 6) || (PolozenieX[0] == 2 && PolozenieY[0] == 7) || (PolozenieX[0] == 2 && PolozenieY[0] == 6))
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] - 2;
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] + 2;
						PolozenieY[2] = PolozenieY[0];
					}
				}
				else if ((PolozenieX[0] == 1 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)) || (PolozenieX[0] == 2 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] - 2;
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] + 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] + 2;
					}
				}
				else if ((PolozenieX[0] == 7 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)) || (PolozenieX[0] == 6 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] - 2;
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] - 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] + 2;
					}
				}
				else if ((PolozenieY[0] == 7 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)) || (PolozenieY[0] == 6 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0] - 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] + 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] - 2;
					}
				}
				else if ((PolozenieY[0] == 1 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)) || (PolozenieY[0] == 2 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0] - 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] + 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] + 2;
					}
				}
			}
		}
		else if (PolozenieY[2] == PolozenieY[0])
		{
			if (PolozenieX[2] == (PolozenieX[0] + 2) || PolozenieX[2] == (PolozenieX[0] - 2))
			{
				tmpl = true;
			}
			else
			{
				if (PolozenieX[0] != 1 && PolozenieX[0] != 2 && PolozenieX[0] != 6 && PolozenieX[0] != 7 && PolozenieY[0] != 1 && PolozenieY[0] != 2 && PolozenieY[0] != 6 && PolozenieY[0] != 7)
				{
					TMPL = ((rand() % 4) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0] - 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 2 || TMPL == 4)
					{
						PolozenieX[2] = PolozenieX[0];
						if (TMPL == 2)
						{
							PolozenieY[2] = PolozenieY[0] - 2;
						}
						else if (TMPL == 4)
						{
							PolozenieY[2] = PolozenieY[0] + 2;
						}
					}
					else if (TMPL == 3)
					{
						PolozenieX[2] = PolozenieX[0] + 2;
						PolozenieY[2] = PolozenieY[0];
					}
				}
				else if ((PolozenieX[0] == 1 && PolozenieY[0] == 1) || (PolozenieX[0] == 1 && PolozenieY[0] == 2) || (PolozenieX[0] == 2 && PolozenieY[0] == 1) || (PolozenieX[0] == 2 && PolozenieY[0] == 2))
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] + 2;
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] + 2;
						PolozenieY[2] = PolozenieY[0];
					}
				}
				else if ((PolozenieX[0] == 7 && PolozenieY[0] == 1) || (PolozenieX[0] == 7 && PolozenieY[0] == 2) || (PolozenieX[0] == 6 && PolozenieY[0] == 1) || (PolozenieX[0] == 6 && PolozenieY[0] == 2))
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] + 2;
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] - 2;
						PolozenieY[2] = PolozenieY[0];
					}
				}
				else if ((PolozenieX[0] == 7 && PolozenieY[0] == 7) || (PolozenieX[0] == 7 && PolozenieY[0] == 6) || (PolozenieX[0] == 6 && PolozenieY[0] == 7) || (PolozenieX[0] == 6 && PolozenieY[0] == 6))
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] - 2;
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] - 2;
						PolozenieY[2] = PolozenieY[0];
					}
				}
				else if ((PolozenieX[0] == 1 && PolozenieY[0] == 7) || (PolozenieX[0] == 1 && PolozenieY[0] == 6) || (PolozenieX[0] == 2 && PolozenieY[0] == 7) || (PolozenieX[0] == 2 && PolozenieY[0] == 6))
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] - 2;
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] + 2;
						PolozenieY[2] = PolozenieY[0];
					}
				}
				else if ((PolozenieX[0] == 1 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)) || (PolozenieX[0] == 2 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] - 2;
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] + 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] + 2;
					}
				}
				else if ((PolozenieX[0] == 7 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)) || (PolozenieX[0] == 6 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] - 2;
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] - 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] + 2;
					}
				}
				else if ((PolozenieY[0] == 7 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)) || (PolozenieY[0] == 6 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0] - 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] + 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] - 2;
					}
				}
				else if ((PolozenieY[0] == 1 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)) || (PolozenieY[0] == 2 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0] - 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] + 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] + 2;
					}
				}
			}
		}
		else
		{
			if (PolozenieX[0] != 1 && PolozenieX[0] != 2 && PolozenieX[0] != 6 && PolozenieX[0] != 7 && PolozenieY[0] != 1 && PolozenieY[0] != 2 && PolozenieY[0] != 6 && PolozenieY[0] != 7)
			{
				TMPL = ((rand() % 4) + 1);
				if (TMPL == 1)
				{
					PolozenieX[2] = PolozenieX[0] - 2;
					PolozenieY[2] = PolozenieY[0];
				}
				else if (TMPL == 2 || TMPL == 4)
				{
					PolozenieX[2] = PolozenieX[0];
					if (TMPL == 2)
					{
						PolozenieY[2] = PolozenieY[0] - 2;
					}
					else if (TMPL == 4)
					{
						PolozenieY[2] = PolozenieY[0] + 2;
					}
				}
				else if (TMPL == 3)
				{
					PolozenieX[2] = PolozenieX[0] + 2;
					PolozenieY[2] = PolozenieY[0];
				}
			}
			else if ((PolozenieX[0] == 1 && PolozenieY[0] == 1) || (PolozenieX[0] == 1 && PolozenieY[0] == 2) || (PolozenieX[0] == 2 && PolozenieY[0] == 1) || (PolozenieX[0] == 2 && PolozenieY[0] == 2))
			{
				TMPL = ((rand() % 2) + 1);
				if (TMPL == 1)
				{
					PolozenieX[2] = PolozenieX[0];
					PolozenieY[2] = PolozenieY[0] + 2;
				}
				else if (TMPL == 2)
				{
					PolozenieX[2] = PolozenieX[0] + 2;
					PolozenieY[2] = PolozenieY[0];
				}
			}
			else if ((PolozenieX[0] == 7 && PolozenieY[0] == 1) || (PolozenieX[0] == 7 && PolozenieY[0] == 2) || (PolozenieX[0] == 6 && PolozenieY[0] == 1) || (PolozenieX[0] == 6 && PolozenieY[0] == 2))
			{
				TMPL = ((rand() % 2) + 1);
				if (TMPL == 1)
				{
					PolozenieX[2] = PolozenieX[0];
					PolozenieY[2] = PolozenieY[0] + 2;
				}
				else if (TMPL == 2)
				{
					PolozenieX[2] = PolozenieX[0] - 2;
					PolozenieY[2] = PolozenieY[0];
				}
			}
			else if ((PolozenieX[0] == 7 && PolozenieY[0] == 7) || (PolozenieX[0] == 7 && PolozenieY[0] == 6) || (PolozenieX[0] == 6 && PolozenieY[0] == 7) || (PolozenieX[0] == 6 && PolozenieY[0] == 6))
			{
				TMPL = ((rand() % 2) + 1);
				if (TMPL == 1)
				{
					PolozenieX[2] = PolozenieX[0];
					PolozenieY[2] = PolozenieY[0] - 2;
				}
				else if (TMPL == 2)
				{
					PolozenieX[2] = PolozenieX[0] - 2;
					PolozenieY[2] = PolozenieY[0];
				}
			}
			else if ((PolozenieX[0] == 1 && PolozenieY[0] == 7) || (PolozenieX[0] == 1 && PolozenieY[0] == 6) || (PolozenieX[0] == 2 && PolozenieY[0] == 7) || (PolozenieX[0] == 2 && PolozenieY[0] == 6))
			{
				TMPL = ((rand() % 2) + 1);
				if (TMPL == 1)
				{
					PolozenieX[2] = PolozenieX[0];
					PolozenieY[2] = PolozenieY[0] - 2;
				}
				else if (TMPL == 2)
				{
					PolozenieX[2] = PolozenieX[0] + 2;
					PolozenieY[2] = PolozenieY[0];
				}
			}
			else if ((PolozenieX[0] == 1 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)) || (PolozenieX[0] == 2 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)))
			{
				TMPL = ((rand() % 3) + 1);
				if (TMPL == 1)
				{
					PolozenieX[2] = PolozenieX[0];
					PolozenieY[2] = PolozenieY[0] - 2;
				}
				else if (TMPL == 2)
				{
					PolozenieX[2] = PolozenieX[0] + 2;
					PolozenieY[2] = PolozenieY[0];
				}
				else if (TMPL == 3)
				{
					PolozenieX[2] = PolozenieX[0];
					PolozenieY[2] = PolozenieY[0] + 2;
				}
			}
			else if ((PolozenieX[0] == 7 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)) || (PolozenieX[0] == 6 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)))
			{
				TMPL = ((rand() % 3) + 1);
				if (TMPL == 1)
				{
					PolozenieX[2] = PolozenieX[0];
					PolozenieY[2] = PolozenieY[0] - 2;
				}
				else if (TMPL == 2)
				{
					PolozenieX[2] = PolozenieX[0] - 2;
					PolozenieY[2] = PolozenieY[0];
				}
				else if (TMPL == 3)
				{
					PolozenieX[2] = PolozenieX[0];
					PolozenieY[2] = PolozenieY[0] + 2;
				}
			}
			else if ((PolozenieY[0] == 7 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)) || (PolozenieY[0] == 6 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)))
			{
				TMPL = ((rand() % 3) + 1);
				if (TMPL == 1)
				{
					PolozenieX[2] = PolozenieX[0] - 2;
					PolozenieY[2] = PolozenieY[0];
				}
				else if (TMPL == 2)
				{
					PolozenieX[2] = PolozenieX[0] + 2;
					PolozenieY[2] = PolozenieY[0];
				}
				else if (TMPL == 3)
				{
					PolozenieX[2] = PolozenieX[0];
					PolozenieY[2] = PolozenieY[0] - 2;
				}
			}
			else if ((PolozenieY[0] == 1 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)) || (PolozenieY[0] == 2 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)))
			{
				TMPL = ((rand() % 3) + 1);
				if (TMPL == 1)
				{
					PolozenieX[2] = PolozenieX[0] - 2;
					PolozenieY[2] = PolozenieY[0];
				}
				else if (TMPL == 2)
				{
					PolozenieX[2] = PolozenieX[0] + 2;
					PolozenieY[2] = PolozenieY[0];
				}
				else if (TMPL == 3)
				{
					PolozenieX[2] = PolozenieX[0];
					PolozenieY[2] = PolozenieY[0] + 2;
				}
			}
		}
	} while (tmpl == false);
	PolozenieX[1] = (PolozenieX[0] + PolozenieX[2]) / 2;
	PolozenieY[1] = (PolozenieY[0] + PolozenieY[2]) / 2;
	for (int i = 0; i < dlugosc; i++)
	{
		trafienie.push_back(false);
	}
}

Trójmasztowiec::~Trójmasztowiec()
{
	cout << "Usuniêto Trójmasztowiec! \n";
}

//Wyj¹tek
void Trójmasztowiec::ZmienPolozenie()
{
	bool OdpowiednieKordynaty = false;
	bool tmpl = false;
	cout << "Podano bledne wspolrzedne!\n";
	do
	{
		try
		{
			cout << "Podaj poczatek trójmasztowca\n";
			cout << "Kolumna: ";
			cin >> PolozenieX[0];
			cout << "Wiersz: ";
			cin >> PolozenieY[0];
			if ((PolozenieX[0] < 1 || PolozenieX[0] > 7) || (PolozenieY[0] < 1 || PolozenieY[0] > 7))
			{
				throw 'x';
			}
			OdpowiednieKordynaty = true;
		}
		catch (char x)
		{
			cout << "Podano z³¹ wartoœæ pocz¹tku trójmasztowca\n";
		}
	} while (OdpowiednieKordynaty == false);
	OdpowiednieKordynaty = false;
	do
	{
		try
		{
			cout << "Podaj koniec trójmasztowca\n";
			cout << "Kolumna: ";
			cin >> PolozenieX[2];
			cout << "Wiersz: ";
			cin >> PolozenieY[2];
			if ((PolozenieX[2] < 1 || PolozenieX[2] > 7) || (PolozenieY[2] < 1 || PolozenieY[2] > 7))
			{
				throw 'x';
			}
			OdpowiednieKordynaty = true;
		}
		catch (char x)
		{
			cout << "Podano z³¹ wartoœæ koñca trójmasztowca\n";
		}
	} while (OdpowiednieKordynaty == false);
	do
	{
		if (PolozenieX[2] == PolozenieX[0])
		{
			if (PolozenieY[2] == (PolozenieY[0] + 2) || PolozenieY[2] == (PolozenieY[0] - 2))
			{
				tmpl = true;
			}
			else
			{
				cout << "Podano zla wartosc konca statku!\n";
				cout << "Podaj koniec trójmasztowca\n";
				cout << "Kolumna: ";
				cin >> PolozenieX[2];
				cout << "Wiersz: ";
				cin >> PolozenieY[2];
			}
		}
		else if (PolozenieY[2] == PolozenieY[0])
		{
			if (PolozenieX[2] == (PolozenieX[0] + 2) || PolozenieX[2] == (PolozenieX[0] - 2))
			{
				tmpl = true;
			}
			else
			{
				cout << "Podano zla wartosc konca statku!\n";
				cout << "Podaj koniec trójmasztowca\n";
				cout << "Kolumna: ";
				cin >> PolozenieX[2];
				cout << "Wiersz: ";
				cin >> PolozenieY[2];
			}
		}
		else
		{
			cout << "Podano zla wartosc konca statku!\n";
			cout << "Podaj koniec trójmasztowca\n";
			cout << "Kolumna: ";
			cin >> PolozenieX[2];
			cout << "Wiersz: ";
			cin >> PolozenieY[2];
		}

		if (PolozenieX[2] < 1 || PolozenieY[2] < 1 || PolozenieX[2] > 7 && PolozenieY[2] > 7)
		{
			tmpl = false;
			cout << "Podano zla wartosc konca statku!\n";
			cout << "Podaj koniec trójmasztowca\n";
			cout << "Kolumna: ";
			PolozenieX[2] = Cin();
			//			cin >> PolozenieX[2];
			cout << "Wiersz: ";
			PolozenieY[2] = Cin();
			//			cin >> PolozenieY[2];
		}
	} while (tmpl == false);
	PolozenieX[1] = (PolozenieX[0] + PolozenieX[2]) / 2;
	PolozenieY[1] = (PolozenieY[0] + PolozenieY[2]) / 2;
}

void Trójmasztowiec::ZmienPolozenie(bool Bot)
{
	bool tmpl = false;
	int TMPL;
	PolozenieX[0] = ((rand() % 7) + 1);
	PolozenieY[0] = ((rand() % 7) + 1);
	if (PolozenieX[0] != 1 && PolozenieX[0] != 2 && PolozenieX[0] != 6 && PolozenieX[0] != 7 && PolozenieY[0] != 1 && PolozenieY[0] != 2 && PolozenieY[0] != 6 && PolozenieY[0] != 7)
	{
		TMPL = ((rand() % 4) + 1);
		if (TMPL == 1)
		{
			PolozenieX[2] = PolozenieX[0] - 2;
			PolozenieY[2] = PolozenieY[0];
		}
		else if (TMPL == 2 || TMPL == 4)
		{
			PolozenieX[2] = PolozenieX[0];
			if (TMPL == 2)
			{
				PolozenieY[2] = PolozenieY[0] - 2;
			}
			else if (TMPL == 4)
			{
				PolozenieY[2] = PolozenieY[0] + 2;
			}
		}
		else if (TMPL == 3)
		{
			PolozenieX[2] = PolozenieX[0] + 2;
			PolozenieY[2] = PolozenieY[0];
		}
	}
	else if ((PolozenieX[0] == 1 && PolozenieY[0] == 1) || (PolozenieX[0] == 1 && PolozenieY[0] == 2) || (PolozenieX[0] == 2 && PolozenieY[0] == 1) || (PolozenieX[0] == 2 && PolozenieY[0] == 2))
	{
		TMPL = ((rand() % 2) + 1);
		if (TMPL == 1)
		{
			PolozenieX[2] = PolozenieX[0];
			PolozenieY[2] = PolozenieY[0] + 2;
		}
		else if (TMPL == 2)
		{
			PolozenieX[2] = PolozenieX[0] + 2;
			PolozenieY[2] = PolozenieY[0];
		}
	}
	else if ((PolozenieX[0] == 7 && PolozenieY[0] == 1) || (PolozenieX[0] == 7 && PolozenieY[0] == 2) || (PolozenieX[0] == 6 && PolozenieY[0] == 1) || (PolozenieX[0] == 6 && PolozenieY[0] == 2))
	{
		TMPL = ((rand() % 2) + 1);
		if (TMPL == 1)
		{
			PolozenieX[2] = PolozenieX[0];
			PolozenieY[2] = PolozenieY[0] + 2;
		}
		else if (TMPL == 2)
		{
			PolozenieX[2] = PolozenieX[0] - 2;
			PolozenieY[2] = PolozenieY[0];
		}
	}
	else if ((PolozenieX[0] == 7 && PolozenieY[0] == 7) || (PolozenieX[0] == 7 && PolozenieY[0] == 6) || (PolozenieX[0] == 6 && PolozenieY[0] == 7) || (PolozenieX[0] == 6 && PolozenieY[0] == 6))
	{
		TMPL = ((rand() % 2) + 1);
		if (TMPL == 1)
		{
			PolozenieX[2] = PolozenieX[0];
			PolozenieY[2] = PolozenieY[0] - 2;
		}
		else if (TMPL == 2)
		{
			PolozenieX[2] = PolozenieX[0] - 2;
			PolozenieY[2] = PolozenieY[0];
		}
	}
	else if ((PolozenieX[0] == 1 && PolozenieY[0] == 7) || (PolozenieX[0] == 1 && PolozenieY[0] == 6) || (PolozenieX[0] == 2 && PolozenieY[0] == 7) || (PolozenieX[0] == 2 && PolozenieY[0] == 6))
	{
		TMPL = ((rand() % 2) + 1);
		if (TMPL == 1)
		{
			PolozenieX[2] = PolozenieX[0];
			PolozenieY[2] = PolozenieY[0] - 2;
		}
		else if (TMPL == 2)
		{
			PolozenieX[2] = PolozenieX[0] + 2;
			PolozenieY[2] = PolozenieY[0];
		}
	}
	else if ((PolozenieX[0] == 1 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)) || (PolozenieX[0] == 2 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)))
	{
		TMPL = ((rand() % 3) + 1);
		if (TMPL == 1)
		{
			PolozenieX[2] = PolozenieX[0];
			PolozenieY[2] = PolozenieY[0] - 2;
		}
		else if (TMPL == 2)
		{
			PolozenieX[2] = PolozenieX[0] + 2;
			PolozenieY[2] = PolozenieY[0];
		}
		else if (TMPL == 3)
		{
			PolozenieX[2] = PolozenieX[0];
			PolozenieY[2] = PolozenieY[0] + 2;
		}
	}
	else if ((PolozenieX[0] == 7 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)) || (PolozenieX[0] == 6 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)))
	{
		TMPL = ((rand() % 3) + 1);
		if (TMPL == 1)
		{
			PolozenieX[2] = PolozenieX[0];
			PolozenieY[2] = PolozenieY[0] - 2;
		}
		else if (TMPL == 2)
		{
			PolozenieX[2] = PolozenieX[0] - 2;
			PolozenieY[2] = PolozenieY[0];
		}
		else if (TMPL == 3)
		{
			PolozenieX[2] = PolozenieX[0];
			PolozenieY[2] = PolozenieY[0] + 2;
		}
	}
	else if ((PolozenieY[0] == 7 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)) || (PolozenieY[0] == 6 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)))
	{
		TMPL = ((rand() % 3) + 1);
		if (TMPL == 1)
		{
			PolozenieX[2] = PolozenieX[0] - 2;
			PolozenieY[2] = PolozenieY[0];
		}
		else if (TMPL == 2)
		{
			PolozenieX[2] = PolozenieX[0] + 2;
			PolozenieY[2] = PolozenieY[0];
		}
		else if (TMPL == 3)
		{
			PolozenieX[2] = PolozenieX[0];
			PolozenieY[2] = PolozenieY[0] - 2;
		}
	}
	else if ((PolozenieY[0] == 1 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)) || (PolozenieY[0] == 2 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)))
	{
		TMPL = ((rand() % 3) + 1);
		if (TMPL == 1)
		{
			PolozenieX[2] = PolozenieX[0] - 2;
			PolozenieY[2] = PolozenieY[0];
		}
		else if (TMPL == 2)
		{
			PolozenieX[2] = PolozenieX[0] + 2;
			PolozenieY[2] = PolozenieY[0];
		}
		else if (TMPL == 3)
		{
			PolozenieX[2] = PolozenieX[0];
			PolozenieY[2] = PolozenieY[0] + 2;
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
				if (PolozenieX[0] != 1 && PolozenieX[0] != 2 && PolozenieX[0] != 6 && PolozenieX[0] != 7 && PolozenieY[0] != 1 && PolozenieY[0] != 2 && PolozenieY[0] != 6 && PolozenieY[0] != 7)
				{
					TMPL = ((rand() % 4) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0] - 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 2 || TMPL == 4)
					{
						PolozenieX[2] = PolozenieX[0];
						if (TMPL == 2)
						{
							PolozenieY[2] = PolozenieY[0] - 2;
						}
						else if (TMPL == 4)
						{
							PolozenieY[2] = PolozenieY[0] + 2;
						}
					}
					else if (TMPL == 3)
					{
						PolozenieX[2] = PolozenieX[0] + 2;
						PolozenieY[2] = PolozenieY[0];
					}
				}
				else if ((PolozenieX[0] == 1 && PolozenieY[0] == 1) || (PolozenieX[0] == 1 && PolozenieY[0] == 2) || (PolozenieX[0] == 2 && PolozenieY[0] == 1) || (PolozenieX[0] == 2 && PolozenieY[0] == 2))
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] + 2;
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] + 2;
						PolozenieY[2] = PolozenieY[0];
					}
				}
				else if ((PolozenieX[0] == 7 && PolozenieY[0] == 1) || (PolozenieX[0] == 7 && PolozenieY[0] == 2) || (PolozenieX[0] == 6 && PolozenieY[0] == 1) || (PolozenieX[0] == 6 && PolozenieY[0] == 2))
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] + 2;
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] - 2;
						PolozenieY[2] = PolozenieY[0];
					}
				}
				else if ((PolozenieX[0] == 7 && PolozenieY[0] == 7) || (PolozenieX[0] == 7 && PolozenieY[0] == 6) || (PolozenieX[0] == 6 && PolozenieY[0] == 7) || (PolozenieX[0] == 6 && PolozenieY[0] == 6))
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] - 2;
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] - 2;
						PolozenieY[2] = PolozenieY[0];
					}
				}
				else if ((PolozenieX[0] == 1 && PolozenieY[0] == 7) || (PolozenieX[0] == 1 && PolozenieY[0] == 6) || (PolozenieX[0] == 2 && PolozenieY[0] == 7) || (PolozenieX[0] == 2 && PolozenieY[0] == 6))
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] - 2;
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] + 2;
						PolozenieY[2] = PolozenieY[0];
					}
				}
				else if ((PolozenieX[0] == 1 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)) || (PolozenieX[0] == 2 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] - 2;
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] + 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] + 2;
					}
				}
				else if ((PolozenieX[0] == 7 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)) || (PolozenieX[0] == 6 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] - 2;
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] - 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] + 2;
					}
				}
				else if ((PolozenieY[0] == 7 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)) || (PolozenieY[0] == 6 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0] - 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] + 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] - 2;
					}
				}
				else if ((PolozenieY[0] == 1 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)) || (PolozenieY[0] == 2 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0] - 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] + 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] + 2;
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
				if (PolozenieX[0] != 1 && PolozenieX[0] != 2 && PolozenieX[0] != 6 && PolozenieX[0] != 7 && PolozenieY[0] != 1 && PolozenieY[0] != 2 && PolozenieY[0] != 6 && PolozenieY[0] != 7)
				{
					TMPL = ((rand() % 4) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0] - 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 2 || TMPL == 4)
					{
						PolozenieX[2] = PolozenieX[0];
						if (TMPL == 2)
						{
							PolozenieY[2] = PolozenieY[0] - 2;
						}
						else if (TMPL == 4)
						{
							PolozenieY[2] = PolozenieY[0] + 2;
						}
					}
					else if (TMPL == 3)
					{
						PolozenieX[2] = PolozenieX[0] + 2;
						PolozenieY[2] = PolozenieY[0];
					}
				}
				else if ((PolozenieX[0] == 1 && PolozenieY[0] == 1) || (PolozenieX[0] == 1 && PolozenieY[0] == 2) || (PolozenieX[0] == 2 && PolozenieY[0] == 1) || (PolozenieX[0] == 2 && PolozenieY[0] == 2))
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] + 2;
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] + 2;
						PolozenieY[2] = PolozenieY[0];
					}
				}
				else if ((PolozenieX[0] == 7 && PolozenieY[0] == 1) || (PolozenieX[0] == 7 && PolozenieY[0] == 2) || (PolozenieX[0] == 6 && PolozenieY[0] == 1) || (PolozenieX[0] == 6 && PolozenieY[0] == 2))
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] + 2;
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] - 2;
						PolozenieY[2] = PolozenieY[0];
					}
				}
				else if ((PolozenieX[0] == 7 && PolozenieY[0] == 7) || (PolozenieX[0] == 7 && PolozenieY[0] == 6) || (PolozenieX[0] == 6 && PolozenieY[0] == 7) || (PolozenieX[0] == 6 && PolozenieY[0] == 6))
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] - 2;
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] - 2;
						PolozenieY[2] = PolozenieY[0];
					}
				}
				else if ((PolozenieX[0] == 1 && PolozenieY[0] == 7) || (PolozenieX[0] == 1 && PolozenieY[0] == 6) || (PolozenieX[0] == 2 && PolozenieY[0] == 7) || (PolozenieX[0] == 2 && PolozenieY[0] == 6))
				{
					TMPL = ((rand() % 2) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] - 2;
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] + 2;
						PolozenieY[2] = PolozenieY[0];
					}
				}
				else if ((PolozenieX[0] == 1 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)) || (PolozenieX[0] == 2 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] - 2;
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] + 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] + 2;
					}
				}
				else if ((PolozenieX[0] == 7 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)) || (PolozenieX[0] == 6 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] - 2;
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] - 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] + 2;
					}
				}
				else if ((PolozenieY[0] == 7 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)) || (PolozenieY[0] == 6 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0] - 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] + 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] - 2;
					}
				}
				else if ((PolozenieY[0] == 1 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)) || (PolozenieY[0] == 2 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)))
				{
					TMPL = ((rand() % 3) + 1);
					if (TMPL == 1)
					{
						PolozenieX[2] = PolozenieX[0] - 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 2)
					{
						PolozenieX[2] = PolozenieX[0] + 2;
						PolozenieY[2] = PolozenieY[0];
					}
					else if (TMPL == 3)
					{
						PolozenieX[2] = PolozenieX[0];
						PolozenieY[2] = PolozenieY[0] + 2;
					}
				}
			}
		}
		else
		{
			if (PolozenieX[0] != 1 && PolozenieX[0] != 2 && PolozenieX[0] != 6 && PolozenieX[0] != 7 && PolozenieY[0] != 1 && PolozenieY[0] != 2 && PolozenieY[0] != 6 && PolozenieY[0] != 7)
			{
				TMPL = ((rand() % 4) + 1);
				if (TMPL == 1)
				{
					PolozenieX[2] = PolozenieX[0] - 2;
					PolozenieY[2] = PolozenieY[0];
				}
				else if (TMPL == 2 || TMPL == 4)
				{
					PolozenieX[2] = PolozenieX[0];
					if (TMPL == 2)
					{
						PolozenieY[2] = PolozenieY[0] - 2;
					}
					else if (TMPL == 4)
					{
						PolozenieY[2] = PolozenieY[0] + 2;
					}
				}
				else if (TMPL == 3)
				{
					PolozenieX[2] = PolozenieX[0] + 2;
					PolozenieY[2] = PolozenieY[0];
				}
			}
			else if ((PolozenieX[0] == 1 && PolozenieY[0] == 1) || (PolozenieX[0] == 1 && PolozenieY[0] == 2) || (PolozenieX[0] == 2 && PolozenieY[0] == 1) || (PolozenieX[0] == 2 && PolozenieY[0] == 2))
			{
				TMPL = ((rand() % 2) + 1);
				if (TMPL == 1)
				{
					PolozenieX[2] = PolozenieX[0];
					PolozenieY[2] = PolozenieY[0] + 2;
				}
				else if (TMPL == 2)
				{
					PolozenieX[2] = PolozenieX[0] + 2;
					PolozenieY[2] = PolozenieY[0];
				}
			}
			else if ((PolozenieX[0] == 7 && PolozenieY[0] == 1) || (PolozenieX[0] == 7 && PolozenieY[0] == 2) || (PolozenieX[0] == 6 && PolozenieY[0] == 1) || (PolozenieX[0] == 6 && PolozenieY[0] == 2))
			{
				TMPL = ((rand() % 2) + 1);
				if (TMPL == 1)
				{
					PolozenieX[2] = PolozenieX[0];
					PolozenieY[2] = PolozenieY[0] + 2;
				}
				else if (TMPL == 2)
				{
					PolozenieX[2] = PolozenieX[0] - 2;
					PolozenieY[2] = PolozenieY[0];
				}
			}
			else if ((PolozenieX[0] == 7 && PolozenieY[0] == 7) || (PolozenieX[0] == 7 && PolozenieY[0] == 6) || (PolozenieX[0] == 6 && PolozenieY[0] == 7) || (PolozenieX[0] == 6 && PolozenieY[0] == 6))
			{
				TMPL = ((rand() % 2) + 1);
				if (TMPL == 1)
				{
					PolozenieX[2] = PolozenieX[0];
					PolozenieY[2] = PolozenieY[0] - 2;
				}
				else if (TMPL == 2)
				{
					PolozenieX[2] = PolozenieX[0] - 2;
					PolozenieY[2] = PolozenieY[0];
				}
			}
			else if ((PolozenieX[0] == 1 && PolozenieY[0] == 7) || (PolozenieX[0] == 1 && PolozenieY[0] == 6) || (PolozenieX[0] == 2 && PolozenieY[0] == 7) || (PolozenieX[0] == 2 && PolozenieY[0] == 6))
			{
				TMPL = ((rand() % 2) + 1);
				if (TMPL == 1)
				{
					PolozenieX[2] = PolozenieX[0];
					PolozenieY[2] = PolozenieY[0] - 2;
				}
				else if (TMPL == 2)
				{
					PolozenieX[2] = PolozenieX[0] + 2;
					PolozenieY[2] = PolozenieY[0];
				}
			}
			else if ((PolozenieX[0] == 1 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)) || (PolozenieX[0] == 2 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)))
			{
				TMPL = ((rand() % 3) + 1);
				if (TMPL == 1)
				{
					PolozenieX[2] = PolozenieX[0];
					PolozenieY[2] = PolozenieY[0] - 2;
				}
				else if (TMPL == 2)
				{
					PolozenieX[2] = PolozenieX[0] + 2;
					PolozenieY[2] = PolozenieY[0];
				}
				else if (TMPL == 3)
				{
					PolozenieX[2] = PolozenieX[0];
					PolozenieY[2] = PolozenieY[0] + 2;
				}
			}
			else if ((PolozenieX[0] == 7 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)) || (PolozenieX[0] == 6 && (PolozenieY[0] == 3 || PolozenieY[0] == 4 || PolozenieY[0] == 5)))
			{
				TMPL = ((rand() % 3) + 1);
				if (TMPL == 1)
				{
					PolozenieX[2] = PolozenieX[0];
					PolozenieY[2] = PolozenieY[0] - 2;
				}
				else if (TMPL == 2)
				{
					PolozenieX[2] = PolozenieX[0] - 2;
					PolozenieY[2] = PolozenieY[0];
				}
				else if (TMPL == 3)
				{
					PolozenieX[2] = PolozenieX[0];
					PolozenieY[2] = PolozenieY[0] + 2;
				}
			}
			else if ((PolozenieY[0] == 7 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)) || (PolozenieY[0] == 6 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)))
			{
				TMPL = ((rand() % 3) + 1);
				if (TMPL == 1)
				{
					PolozenieX[2] = PolozenieX[0] - 2;
					PolozenieY[2] = PolozenieY[0];
				}
				else if (TMPL == 2)
				{
					PolozenieX[2] = PolozenieX[0] + 2;
					PolozenieY[2] = PolozenieY[0];
				}
				else if (TMPL == 3)
				{
					PolozenieX[2] = PolozenieX[0];
					PolozenieY[2] = PolozenieY[0] - 2;
				}
			}
			else if ((PolozenieY[0] == 1 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)) || (PolozenieY[0] == 2 && (PolozenieX[0] == 3 || PolozenieX[0] == 4 || PolozenieX[0] == 5)))
			{
				TMPL = ((rand() % 3) + 1);
				if (TMPL == 1)
				{
					PolozenieX[2] = PolozenieX[0] - 2;
					PolozenieY[2] = PolozenieY[0];
				}
				else if (TMPL == 2)
				{
					PolozenieX[2] = PolozenieX[0] + 2;
					PolozenieY[2] = PolozenieY[0];
				}
				else if (TMPL == 3)
				{
					PolozenieX[2] = PolozenieX[0];
					PolozenieY[2] = PolozenieY[0] + 2;
				}
			}
		}
	} while (tmpl == false);
}

void Trójmasztowiec::SprawdzZatopienie()
{
	if (trafienie[0] == true)
	{
		if (trafienie[1] == true)
		{
			if (trafienie[2] == true)
			{
				zatopiony = true;
			}
		}
	}
	else
	{
		zatopiony = false;
	}
}

void Trójmasztowiec::ZatopCzesc(int x, int y)
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

void Trójmasztowiec::ZatopCalosc()
{
	if (trafienie[0] == true && trafienie[1] == true && trafienie[2] == true)
	{
		cout << endl;
		cout << "---------------------------\n";
		cout << "Zatopiono trójmasztowiec!\n";
		cout << "---------------------------\n";
		zatopiony = true;
	}
}


