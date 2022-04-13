/**
 * @author Linus Palm
 */
#include <iostream>
#include <cassert>
#include <math.h>
#include "vektor.h"

const double h = 1e-8;

CMyVektor::CMyVektor(int dimensions) :n{ dimensions }
{
    A = new double[n];
}

CMyVektor::CMyVektor(const CMyVektor& orig) : n{ orig.n }
{
    A = new double[n];
    for (int i = 0; i < n; i++)A[i] = orig.A[i];
}

double CMyVektor::get_length() const
{
    double sum = 0;
    for (int i = 0; i < n; i++)sum += A[i]*A[i];
    return sqrt(sum);
}

CMyVektor& CMyVektor::operator = (const CMyVektor& orig)
{
    delete[] A;
    n = orig.n;
    A = new double[n];
    for (int i = 0; i < n; i++)A[i] = orig.A[i];
    return *this;
}

CMyVektor CMyVektor::operator + (const CMyVektor& b)
{
    if (n == b.n)
    {
        CMyVektor temp(n);
        for (int i = 0; i < n; i++)temp[i] = A[i] + b.A[i];
        return temp;
    }
    else
    {
        std::cout << "Error: Addition with different dimensions\n";
        system("PAUSE");
        return *this;
    }
}

CMyVektor CMyVektor::operator * (double lambda)
{
    CMyVektor temp(n);
    for (int i = 0; i < n; i++)temp[i] = A[i] * lambda;
    return temp;
}

double CMyVektor::operator * (const CMyVektor& b)
{
    assert(n == b.n);
    double result = 0;
    for (int i = 0; i < n; i++)result += A[i] * b.A[i];
    return result;
}

CMyVektor operator* (double lambda, CMyVektor a)
{
    CMyVektor temp(a.get_dimension());
    for (int i = 0; i < a.get_dimension(); i++)temp[i] = a[i] * lambda;
    return temp;
}

std::ostream& operator<< (std::ostream& stream,const CMyVektor& x)
{
    CMyVektor temp = x;
    stream << "( " << temp[0];
    for (int i = 1; i < x.get_dimension(); i++)stream << "; " << temp[i];
    stream << ")";
    return stream;
}

CMyVektor gradient(CMyVektor x, double (*funktion)(CMyVektor))
{
    double a = (*funktion)(x);
    CMyVektor temp = x;
    CMyVektor gradient(x.get_dimension());
    for (int i = 0; i < x.get_dimension(); i++)
    {
        temp[i] += h;
        gradient[i] = ((*funktion)(temp)-a);
        temp[i] = x[i];
    }
    return (1/h)*gradient;
}

CMyVektor maximize(CMyVektor start, double (*funktion)(CMyVektor), double lambda,int steps)
{
    int i;
    double current_value;
    CMyVektor grad(start.get_dimension());
    for (i = 0; i < steps && gradient(start, funktion).get_length()>1e-5; i++)
    {
        current_value = funktion(start);
        grad = gradient(start, funktion);
        std::cout << "Schritt " << i << ":\n\n";
        std::cout << "x = " << start << std::endl;
        std::cout << "lambda = " << lambda << std::endl;
        std::cout << "f(x) = " << current_value << std::endl;
        std::cout << "grad f(x) = " << grad << std::endl;
        std::cout << "||grad f(x)|| = " << grad.get_length() << std::endl << std::endl;

        CMyVektor x_neu = start + lambda * grad;
        double x_neu_value = funktion(x_neu);
        std::cout << "x_neu = " << x_neu << std::endl;
        std::cout << "f(x_neu) = " << x_neu_value << std::endl << std::endl;
        if (x_neu_value > current_value)
        {

            std::cout << "Test mit doppelter Schrittweite (lambda = " << 2 * lambda << "):\n";
            CMyVektor x_test = start + 2 * lambda * grad;
            double x_test_value = funktion(x_test);
            std::cout << "x_test = " << x_test << std::endl;
            std::cout << "f(x_test) = " << x_test_value << std::endl;
            if (x_neu_value < x_test_value)
            {
                std::cout << "verdoppele Schrittweite!\n\n";
                lambda *= 2;
                start = x_test;
            }
            else
            {
                std::cout << "behalte alte Schrittweite!\n\n";
                start = x_neu;
            }
        }
        else
        {
            while (x_neu_value < current_value)
            {
                lambda *= 0.5;
                std::cout << "halbiere Schrittweite (lambda = " << lambda << "):\n";
                x_neu = start + (lambda * grad);
                x_neu_value = funktion(x_neu);
                std::cout << "x_neu = " << x_neu << std::endl;
                std::cout << "f(x_neu) = " << x_neu_value << std::endl << std::endl;
            }
            start = x_neu;
        }
    }
    current_value = funktion(start);
    grad = gradient(start, funktion);
    if (i == steps)
    {
        std::cout << "Ende wegen Schrittanzahl = " << steps << " bei\n";
        std::cout << "x = " << start << std::endl;
        std::cout << "lambda = " << lambda << std::endl;
        std::cout << "f(x) = " << current_value << std::endl;
        std::cout << "grad f(x) = " << grad << std::endl;
        std::cout << "||grad f(x)|| = " << grad.get_length() << std::endl << std::endl;
        return start;
    }
    else
    {
        std::cout << "Ende wegen ||grad f(x)||<1e-5 bei\n";
        std::cout << "x = " << start << std::endl;
        std::cout << "lambda = " << lambda << std::endl;
        std::cout << "f(x) = " << current_value << std::endl;
        std::cout << "grad f(x) = " << grad << std::endl;
        std::cout << "||grad f(x)|| = " << grad.get_length() << std::endl << std::endl;
        return start;
    }
}