/**
 * @author Linus Palm
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "CKomplex.h"

using namespace std;

vector<CKomplex>  werte_einlesen(const char* dateiname);
void werte_ausgeben(const char* dateiname, vector<CKomplex> werte, double epsilon = -1.0);
void fouriertransformation_reell(vector<CKomplex>& f);
void fouriertransformation(vector<CKomplex>& f);
void fourierrücktransformation(vector<CKomplex> &werte);
double maximale_Abweichung(vector<CKomplex> a, vector<CKomplex> b);
void fastfouriertransformation(vector<CKomplex>& f);
void fastfourierrücktransformation(vector<CKomplex>& c);
vector<CKomplex> fft(vector<CKomplex> f);
vector<CKomplex> ifft(vector<CKomplex> c);

const double pi = acos(-1);
const double div_sqrt_two = 1 / sqrt(2);

int main()
{

    vector<CKomplex> original = werte_einlesen("mario.txt");
    original = fft(original);

    werte_ausgeben("mariofourierstandard.txt",original);
    werte_ausgeben("mariofourier1.txt",original,1);
    werte_ausgeben("mariofourier10.txt",original,10);
    werte_ausgeben("mariofourier100.txt",original,100);
    werte_ausgeben("mariofourier300.txt",original,300);
    werte_ausgeben("mariofourier1000.txt",original,1000);


    vector<CKomplex> standard = werte_einlesen("mariofourierstandard.txt");
    standard = ifft(standard);
    werte_ausgeben("mariotransformedstandard.txt",standard);

    vector<CKomplex> m1 = werte_einlesen("mariofourier1.txt");
    m1 = ifft(m1);
    werte_ausgeben("mariotransformed1.txt",m1);

    vector<CKomplex> m10 = werte_einlesen("mariofourier10.txt");
    m10 = ifft(m10);
    werte_ausgeben("mariotransformed10.txt",m10);

    vector<CKomplex> m100 = werte_einlesen("mariofourier100.txt");
    m100 = ifft(m100);
    werte_ausgeben("mariotransformed100.txt",m100);

    vector<CKomplex> m300 = werte_einlesen("mariofourier300.txt");
    m300 = ifft(m300);
    werte_ausgeben("mariotransformed300.txt",m300);

    vector<CKomplex> m1000 = werte_einlesen("mariofourier1000.txt");
    m1000 = ifft(m1000);
    werte_ausgeben("mariotransformed1000.txt",m1000);

    /*
    vector<CKomplex> original = werte_einlesen("Daten_original.txt");

    vector<CKomplex> daten0 = werte_einlesen("Daten0.txt");
    fourierrücktransformation(daten0);
    cout << "Maximale Abweichung bei Standard-Epsilon: " << maximale_Abweichung(original,daten0) << endl;

    vector<CKomplex> daten1 = werte_einlesen("Daten1.txt");
    fourierrücktransformation(daten1);
    cout << "Maximale Abweichung bei epsilon=0.001: " << maximale_Abweichung(original, daten1) << endl;

    vector<CKomplex> daten2 = werte_einlesen("Daten2.txt");
    fourierrücktransformation(daten2);
    cout << "Maximale Abweichung bei epsilon=0.01: " << maximale_Abweichung(original, daten2) << endl;

    vector<CKomplex> daten3 = werte_einlesen("Daten3.txt");
    fourierrücktransformation(daten3);
    cout << "Maximale Abweichung bei epsilon=0.1: " << maximale_Abweichung(original, daten3) << endl;

    vector<CKomplex> daten4 = werte_einlesen("Daten4.txt");
    fourierrücktransformation(daten4);
    cout << "Maximale Abweichung bei epsilon=1: " << maximale_Abweichung(original, daten4) << endl;
    */
    return 0;
}

vector<CKomplex> werte_einlesen(const char* dateiname)
{
    int i, N, idx;
    double re, im;
    vector<CKomplex> werte;
    // File oeffnen
    ifstream fp;
    fp.open(dateiname);
    // Dimension einlesen
    fp >> N;
    // Werte-Vektor anlegen
    werte.resize(N);
    CKomplex null(0, 0);
    for (i = 0; i < N; i++)
        werte[i] = null;
    // Eintraege einlesen und im Werte-Vektor ablegen
    while (!fp.eof())
    {
        fp >> idx >> re >> im;
        CKomplex a(re, im);
        werte[idx] = a;
    }
    // File schliessen
    fp.close();

    return werte;
}

void werte_ausgeben(const char* dateiname, vector<CKomplex> werte, double epsilon)
{
    int i;
    int N = werte.size();
    // File oeffnen
    ofstream fp;
    fp.open(dateiname);
    // Dimension in das File schreiben
    fp << N << endl;
    // Eintraege in das File schreiben
    fp.precision(16);
    for (i = 0; i < N; i++)
        if (werte[i].abs() > epsilon)
            fp << i << "\t" << werte[i].re() << "\t" << werte[i].im() << endl;
    // File schliessen
    fp.close();
}

void fouriertransformation_reell(vector<CKomplex>& f)
{
    //funktioniert wegen C(N-n)=C(n)* nur mit reellen Datenpunkten
    int N = f.size();
    vector<CKomplex> result(N);
    CKomplex sum(0, 0), temp;

    double lnw = -2 * pi / N, faktor = 1 / sqrt(N);

    for (int j = 0; j < N; j++)
    {
        sum = sum + f[j];
    }
    result[0] = sum * faktor;

    for (int i = 1; i < N / 2 + 1; i++)
    {
        sum.setkar(0, 0);
        for (int j = 0; j < N; j++)
        {
            temp.setpol(lnw * j * i);
            sum = sum + f[j] * temp;
        }
        result[i] = sum * faktor;
        result[N - i] = result[i].konj();
    }
    f = result;
}

void fouriertransformation(vector<CKomplex>& f)
{
    int N = f.size();
    vector<CKomplex> result(N);
    CKomplex sum, temp;

    double lnw = -2. / N * pi, faktor = 1 / sqrt(N);

    for (int i = 0; i < N; i++)
    {
        sum.setkar(0, 0);
        for (int j = 0; j < N; j++)
        {
            temp.setpol(lnw * j * i);
            sum = sum + f[j] * temp;
        }
        result[i] = sum * faktor;
    }
    f = result;
}

void fourierrücktransformation(vector<CKomplex> &c)
{
    int N = c.size();
    vector<CKomplex> result(N);
    CKomplex sum, temp;

    double lnw = 2 * pi / N, faktor = 1 / sqrt(N);

    for (int i = 0; i < N; i++)
    {
        sum.setkar(0, 0);
        for (int j = 0; j < N; j++)
        {
            temp.setpol(lnw * j * i);
            sum = sum + c[j] * temp;
        }
        result[i] = sum * faktor;
    }
    c = result;
}

double maximale_Abweichung(vector<CKomplex> a, vector<CKomplex> b)
{
    int N = a.size();
    if (N != b.size())return -1;
    double result = 0, temp;
    for (int i = 0; i < N; i++)
    {
        temp = (a[i]-b[i]).abs();
        if (temp > result)result = temp;
    }
    return result;
}

vector<CKomplex> fft(vector<CKomplex> f)
{
    int N = f.size();
    vector<CKomplex> result(N);

    if (N == 2){
        result[0] = (f[0] + f[1]) * div_sqrt_two;
        result[1] = (f[0] - f[1]) * div_sqrt_two;
        return result;
    }

    int M = N / 2;
    vector<CKomplex> g(M), u(M);

    for(int i = 0; i<M; i++){
        g[i] = f[2*i];
        u[i] = f[2*i+1];
    }

    g = fft(g);
    u = fft(u);

    const double lnw = -2 * pi / N;
    CKomplex temp;

    for (int m = 0; m < M; m++){
        temp.setpol(lnw * m);
        result[m] = (g[m] + temp * u[m]) * div_sqrt_two;
        result[m + M] = (g[m] - temp * u[m]) * div_sqrt_two;
    }

    return result;
}

vector<CKomplex> ifft(vector<CKomplex> c)
{
    int N = c.size();
    vector<CKomplex> result(N);

    if (N == 2){
        result[0] = (c[0] + c[1]) * div_sqrt_two;
        result[1] = (c[0] - c[1]) * div_sqrt_two;
        return result;
    }

    int M = N / 2;
    vector<CKomplex> g(M), u(M);

    for(int i = 0; i<M; i++){
        g[i] = c[2 * i];
        u[i] = c[2 * i + 1];
    }

    g = ifft(g);
    u = ifft(u);

    const double lnw = 2 * pi / N;
    CKomplex temp;

    for (int m = 0; m < M; m++){
        temp.setpol(lnw * m);
        result[m] = (g[m] + temp * u[m]) * div_sqrt_two;
        result[m + M] = (g[m] - temp * u[m]) * div_sqrt_two;
    }

    return result;
}