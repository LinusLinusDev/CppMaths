/**
 * @author Linus Palm
 */
#include <iostream>
#include <cmath>
using namespace std;

#include "matrix.h"

CMyVektor f(CMyVektor x)
{
    CMyVektor temp(2);
    temp[0] = x[0] * x[0] * x[0] * x[1] * x[1] * x[1] - 2 * x[1];
    temp[1] = x[0] - 2;
    return temp;
}

double h(CMyVektor x)
{
    return -(pow(x[1] * exp(-x[0]) - 0.3, 2) + pow(x[1] - 0.6, 2) + pow(x[1] * exp(2 * x[0]) - 1.5, 2));
}

double n(CMyVektor x)
{
    return -(pow(log(x[1]) - x[0] - log(0.3), 2) + pow(log(x[1]) - log(0.6), 2) + pow(log(x[1]) + 2 * x[0] - log(1.5), 2));//mit Logarithmus
}

int main()
{
    //Praktikumsaufgabe
    CMyVektor x(2);
    x[0] = 1;
    x[1] = 1;
    newton(x,f);

    //Ausgleichsfunktion ohne Logarithmus mit Newton
    CMyVektor start(2); //ohne Log
    start[0] = 0.1; // lambda
    start[1] = 1; // c
    //maximize_newton(start, h);

    //Ausgleichsfunktion mit Logarithmus und Newton
    CMyVektor start3(2); //mit log
    start3[0] = 0.5; // lambda
    start3[1] = 0.5; // c
    //maximize_newton(start3, n);

    return 0;
}