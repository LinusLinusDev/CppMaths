/*
*  Autor: Linus Palm
*  Matrikelnummer: 3271087
*  Datum: 28.05.2021
*/

#pragma once

#include <vector>
#include <time.h>
#include <stdlib.h>

class CZufall
{
public:
	int wert(int a, int b);
	void initialisiere(int s);
	std::vector<int> test(int a, int b, int N);
	std::vector<int> test_falsch(int a, int b, int N);
};