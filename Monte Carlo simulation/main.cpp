/**
 * @author Linus Palm
 */
#include <iostream>
#include <cmath>
#include "CZufall.h"
#include "CLotto.h"

using namespace std;

double MonteCarlo1(int r, int N, CLotto lotto);
double MonteCarlo2(int r, int N, CLotto lotto);
double standartabweichung1(int r, int k, int n, int N_MC, int N_Beo);
double standartabweichung2(int r, int k, int n, int N_MC, int N_Beo);

int main()
{
    for (int i = 1; i <= 1e6; i *= 10)
    {
        cout << "Standartabweichung bei N = " << i << ": " << standartabweichung2(2, 8, 34, i, 10) << endl;
    }

    return 0;
}

double MonteCarlo1(int r,int N,CLotto lotto)
{
    int k = lotto.getk(), n = lotto.getn();
    lotto.setRandomTippzettel();
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (r == lotto.ergebnis())count++;
    }
    return double(count) / N;
}

double MonteCarlo2(int r,int N,CLotto lotto)
{
    int k = lotto.getk(), n = lotto.getn();
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        lotto.setRandomTippzettel();
        if (r == lotto.ergebnis())count++;
    }
    return double(count) / N;
}

double standartabweichung1(int r, int k, int n, int N_MC, int N_Beo)
// N_MC = Monte-Carlo-Simulationen
// N_Beo = Anzahl der Beobachtungen
{
    CLotto lotto(k, n, time(NULL));
    double x, summeA = 0, summeB = 0;
    for (int i = 0; i < N_Beo; i++)
    {
        x = MonteCarlo1(r, N_MC, lotto);
        cout << x << endl;
        summeB += x;
        summeA += x * x;
    }
    double varianz = (summeA - (summeB * summeB) / N_Beo)/(N_Beo-1);

    return sqrt(varianz); // Standartabweichung der Stichprobe
}

double standartabweichung2(int r, int k, int n, int N_MC, int N_Beo)
// N_MC = Monte-Carlo-Simulationen
// N_Beo = Anzahl der Beobachtungen
{
    CLotto lotto(k, n, time(NULL));
    double x, summeA = 0, summeB = 0;
    for (int i = 0; i < N_Beo; i++)
    {
        x = MonteCarlo2(r, N_MC, lotto);
        // cout << x << endl;
        summeB += x;
        summeA += x * x;
    }
    double varianz = (summeA - (summeB * summeB) / N_Beo) / (N_Beo - 1);

    return sqrt(varianz); // Standartabweichung der Stichprobe
}