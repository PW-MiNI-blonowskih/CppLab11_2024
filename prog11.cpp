
#include <iostream>
using namespace std;
#include <ctime>
#include "slowko.h"
#include "slownik.h"
//------------------------------------------------------
   
int main()
{
	srand((unsigned)time(0));

	//te wybrane s��wka maj� by� zawsze w s�owniku
	slownik	S{ {"matrix","macierz"},{"number","liczba"},{"field","cialo"} };

	cout << "Starter slownika:" << endl;
	cout << S << endl;

	//-------------------------------------------------------------
	if (!S.slowka_zpliku("slowka_dnia.txt"))
	{
		cout << "Brak pliku" << endl;
		return 0;
	}

	int	K;
	do {
		cout << S;	//wypisanie slownika

		cout << "\nMENU:" << endl;
		cout << "1 - SORTOWANIE listy wg pola POL_ANG" << endl;
		cout << "2 - SORTOWANIE listy wg pola ANG_POL" << endl;
		cout << "3 - DOPISZ slowko" << endl;
		cout << "4 - TEST" << endl;
		cout << "5 - ZAPISZ slownik" << endl;
		cout << "0 - KONIEC" << endl;
		cout << "*** Podaj numer opcji:  ";

		cin >> K;
		switch (K)
		{
		case 1:	//SORTOWANIE slownika wg pola pol i ang
			S.jak_posortowany = slownik::klucz_slownika::POL_ANG;
			S.sortowanie();
			break;

		case 2:	//SORTOWANIE slownika wg pola ang i pol
			S.jak_posortowany = slownik::klucz_slownika::ANG_POL;
			S.sortowanie();
			break;

		case 3:	//DOPISZ slowko
			S.wstaw();
			break;

		case 4: //TEST
			S.test();
			break;

		case 5: //ZAPIS
			if (!S.zapisz_slowka()) cout << "Brak zapisu" << endl;
			break;
		}//switch
	} while (K != 0);
}

