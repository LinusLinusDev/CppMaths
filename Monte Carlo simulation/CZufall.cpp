/*
*  Autor: Linus Palm
*  Matrikelnummer: 3271087
*  Datum: 28.05.2021
*/

#include "CZufall.h"

int CZufall::wert(int a, int b)
{
	return rand() % (b - a + 1) + a;
}

void CZufall::initialisiere(int s)
{
	srand(s);
}

std::vector<int> CZufall::test(int a, int b, int N)
{
	std::vector<int> ergebnis;
	ergebnis.resize(b - a + 1, 0);
	for (int i = 0; i < N; i++)
	{
		ergebnis[wert(a, b) - a]++;
	}
	return ergebnis;
}

std::vector<int> CZufall::test_falsch(int a, int b, int N)
{
	std::vector<int> ergebnis;
	ergebnis.resize(b - a + 1, 0);
	for (int i = 0; i < N; i++)
	{
		initialisiere(time(NULL));
		ergebnis[wert(a, b) - a]++; //Wert gibt immer die gleiche Zufallszahl zurück, außer im Debugger
	}
	return ergebnis;
}