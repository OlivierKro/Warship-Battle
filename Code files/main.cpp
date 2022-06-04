#include "Gra.h"
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <locale.h>

/*
W klasach Dwumasztowiec oraz Tr�jmasztowiec istniej� zabezpieczenia przeciw wylosowaniu warto�ci, kt�ra uniemo�liwi roz�o�enie statku.
Zabezpieczenia s� przekopiowane kilka krotnie w zale�no�ci od wybrania roz�o�enia statku w tej samej linii po osi X i Y co powoduje tak d�ugi kod
*/



void menu();
void Drukuj();
void DrukujZasadyGry();
int Cin();


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Polish");
	menu();
	return 0;
}

void menu()
{
	int wybor;
	do
	{
		do
		{
			Drukuj();
			wybor = Cin();
//			cin >> wybor;
			switch (wybor)
			{
			case 1:
			{
				Gra G;
				break;
			}
			case 2:
			{
				DrukujZasadyGry();
				system("PAUSE");
				break;
			}
			case 3:
			{
				break;
			}
			}
		} while (wybor == 1 || wybor == 2);
	} while (wybor != 3);

}

void Drukuj()
{
	system("cls");
	cout << "MENU\n";
	cout << "-------------------------------------------\n";
	cout << "1.Graj\n2.Zasady Gry\n3.Wyjd� z gry\n";
	cout << "-------------------------------------------\n";
	cout << "Wybierz opcje z menu (numery z zakresu 1-3)\n";
	cout << "Wyb�r zatwierdz enterem\n\n";
}

void DrukujZasadyGry()
{
	ifstream ZasadyGry;
	ZasadyGry.open("ZasadyGry.txt", ifstream::in);
	if (ZasadyGry.is_open())
	{
		while (ZasadyGry.eof() == false)
		{
			string tmpl;
			getline(ZasadyGry, tmpl);
			cout << tmpl << endl;
		}
	}
	else
	{
		cout << "Nie uda�o si� otworzy� pliku!" << endl;
	}
	ZasadyGry.close();
}

int Cin()
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
 