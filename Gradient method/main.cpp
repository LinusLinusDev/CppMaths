/**
 * @author Linus Palm
 */
#include <iostream>
#include <cmath>
using namespace std;

#include "vektor.h"

double f(CMyVektor x)
{
    return sin(x[0]*x[1])+sin(x[0])+cos(x[1]);
}

double g(CMyVektor x)
{
    return -2*x[0]*x[0]+2*x[0]*x[1]-x[1]*x[1]-x[2]*x[2]+2*x[0]+4*x[2];
}

double m(CMyVektor x)
{
    return -(pow(-2 * x[0] + x[1], 2) + pow(x[1] - 1, 2) + pow(x[0] + x[1] - 2, 2));
}

double h(CMyVektor x)
{
    return -(pow(x[1] * exp(-x[0]) - 0.3, 2) + pow(x[1] - 0.6, 2) + pow(x[1] * exp(2 * x[0]) - 1.5, 2));//ohne Logarithmus
}

double n(CMyVektor x)
{
    return -(pow(log(x[1]) - x[0] - log(0.3), 2) + pow(log(x[1]) - log(0.6), 2) + pow(log(x[1]) + 2 * x[0] - log(1.5), 2));//mit Logarithmus
}

int main()
{
    CMyVektor test1(2);
    test1[0] = 0.2;
    test1[1] = -2.1;
    maximize(test1,f);

    CMyVektor test2(3);
    test2[0] = 0;
    test2[1] = 0;
    test2[2] = 0;
    //maximize(test2,g,0.1);

    CMyVektor start1(2); // Lösung ( 9/14 , 17/14 )
    start1[0] = 0.1; //m
    start1[1] = 1; //a
    //maximize(start1, m);

    CMyVektor start2(2); //ohne Log
    start2[0] = 0.1; // lambda
    start2[1] = 1; // c
    //maximize(start2, h, 1.0, 75);

    CMyVektor start3(2); //mit log
    start3[0] = 0.5; // lambda
    start3[1] = 0.5; // c
    //maximize(start3, n);

    return 0;
}