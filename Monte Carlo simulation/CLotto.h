/*
*  Autor: Linus Palm
*  Matrikelnummer: 3271087
*  Datum: 28.05.2021
*/

#pragma once

#include "CZufall.h"
#include <vector>
#include <cassert>
#include <iostream>
#include <string>

class CLotto
{
private:
	CZufall zufall;
	int k, n;
	bool* tippzettel;
	std::vector<int> ziehung();
public:
	CLotto(int k, int n, int s);
	int getk() const { return k; }
	int getn() const { return n; }
	void setTippzettel();
	void setRandomTippzettel();
	int ergebnis();
};

bool getInt(int& x);