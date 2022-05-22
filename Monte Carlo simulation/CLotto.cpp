/*
*  Autor: Linus Palm
*  Matrikelnummer: 3271087
*  Datum: 28.05.2021
*/

#include "CLotto.h"

using namespace std;

CLotto::CLotto(int k, int n, int s) :k{ k }, n{ n }, tippzettel{ nullptr }
{
	assert(k <= n);
	if (s < 0)s = int(time(NULL));
	zufall.initialisiere(s);
}

void CLotto::setTippzettel()
{
	if (tippzettel != nullptr)delete[]tippzettel;
	tippzettel = new bool[n]{ 0 };
	int temp;
	cout << "Tippzettel ausfuellen fuer " << k << " aus " << n << " Ziehung:\n";
	for (int i = 0; i < k; i++)
	{
        do
        {
            while(true)
            {
                cout << "Bitte " << i + 1 << ". Zahl auswaehlen: ";
                if (getInt(temp) && temp > 0 && temp <= n)break;
            }
        } while (tippzettel[temp - 1]);
        tippzettel[temp - 1] = true;
	}
}

void CLotto::setRandomTippzettel()
{
	if (tippzettel != nullptr)delete[]tippzettel;
	tippzettel = new bool[n] {0};
	int temp;
	for (int i = 0; i < k; i++)
	{
		do
		{
			temp = zufall.wert(1, n);
		} while (tippzettel[temp - 1]);
		tippzettel[temp - 1] = true;
	}
}

vector<int> CLotto::ziehung()
{
	bool* gezogen = new bool[n]{ 0 };
	int temp;
	vector<int> ziehung(k);
	for (int i = 0; i < k; i++)
	{
        do
        {
            temp = zufall.wert(1, n);
        } while (gezogen[temp-1]);
        ziehung[i] = temp;
        gezogen[temp-1] = true;
	}
	delete[] gezogen;
	return ziehung;
}

int CLotto::ergebnis()
{
	if (tippzettel == nullptr)setTippzettel();
	vector<int> gewinn = ziehung();
	int count = 0;
	for (int i = 0; i < k; i++)
	{
		if (tippzettel[gewinn[i] - 1])count++;
	}
	return count;
}

bool getInt(int& x)
{
	string input, int_string = "";
	getline(cin, input);
	for (int i = 0; i < input.length() && input.at(i) >= '0' && input.at(i) <= '9'; i++)int_string += input.at(i);
	if (int_string == "")return false;
	else
	{
		x = stoi(int_string);
		return true;
	}
}