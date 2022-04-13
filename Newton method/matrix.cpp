/**
 * @author Linus Palm
 */
#include <iostream>
#include <cassert>
#include "matrix.h"

const double h_add = 1e-4;
const double h_mult = 1/h_add;

CMyMatrix::CMyMatrix(int lines, int columns) :m{ lines }, n{ columns }
{
    A = new CMyVektor * [m];
    for (int i = 0; i < m; i++)
    {
        A[i] = new CMyVektor(n);
    }
}

CMyMatrix::CMyMatrix(const CMyMatrix& orig) :m{ orig.m }, n{ orig.n }
{
    A = new CMyVektor * [m];
    for (int i = 0; i < m; i++)
    {
        A[i] = new CMyVektor(n);
        *A[i] = *orig.A[i];
    }
}

CMyMatrix::~CMyMatrix()
{
    for (int i = 0; i < m; i++)
    {
        delete A[i];
    }
    delete[] A;
}

CMyMatrix CMyMatrix::invers()
{

    assert(m == 2 && n == 2);
    double det = (*A[0])[0] * (*A[1])[1] - (*A[1])[0] * (*A[0])[1];
    assert(det != 0);
    CMyMatrix invers(2, 2);
    det = 1 / det;
    invers[0][0] = (*A[1])[1] * det;
    invers[1][1] = (*A[0])[0] * det;
    invers[0][1] = (*A[0])[1] * -det;
    invers[1][0] = (*A[1])[0] * -det;
    return invers;
}

std::ostream& operator<< (std::ostream& stream,const CMyMatrix& x)
{
    CMyMatrix temp = x;
    int lines = temp.get_lines(), columns = temp.get_columns();
    for (int i = 0; i < lines; i++)
    {
        stream << "( ";
        for (int j = 0; j < columns; j++)
        {
            stream << temp[i][j] << " ";
        }
        stream << ")\n";
    }
    return stream;
}

CMyVektor operator*(CMyMatrix A, CMyVektor x)
{
    int line_components = A.get_columns();
    assert(line_components == x.get_dimension());
    int result_lines = A.get_lines();
    CMyVektor result(result_lines);
    for (int i = 0; i < result_lines; i++)
    {
        result[i] = A[i] * x;
    }
    return result;
}

CMyMatrix jacobi(CMyVektor x, CMyVektor(*funktion)(CMyVektor x))
{
    CMyVektor temp = x;
    CMyVektor fx = funktion(x);
    int columns = x.get_dimension(), lines = fx.get_dimension();
    CMyMatrix result(lines, columns);
    for (int i = 0; i < columns; i++)
    {
        temp[i] += h_add;
        CMyVektor fxh = funktion(temp);
        for (int j = 0; j < lines; j++)
        {

            result[j][i] = (fxh[j] - fx[j]) * h_mult;
        }
        temp[i] = x[i];
    }
    return result;
}

CMyMatrix jacobi(CMyVektor x, double(*funktion)(CMyVektor x)) //jacobi matrix von grad(f(x)) bilden
{
    CMyVektor temp = x;
    CMyVektor fx = gradient(x,funktion);
    int columns = x.get_dimension(), lines = fx.get_dimension();
    CMyMatrix result(lines, columns);
    for (int i = 0; i < columns; i++)
    {
        temp[i] += h_add;
        CMyVektor fxh = gradient(temp,funktion);
        for (int j = 0; j < lines; j++)
        {

            result[j][i] = (fxh[j] - fx[j]) * h_mult;
        }
        temp[i] = x[i];
    }
    return result;
}

CMyVektor newton(CMyVektor x, CMyVektor(*funktion)(CMyVektor x), int steps)
{
    CMyVektor fx = funktion(x);
    double length = fx.get_length();
    assert(x.get_dimension() == 2 && fx.get_dimension() == 2);
    int i;
    for (i = 0; i < steps && length>1e-5; i++)
    {
        CMyMatrix jacobi_f= jacobi(x, funktion);
        CMyMatrix jacobi_inv = jacobi_f.invers();
        std::cout << "Schritt " << i << ":\n";
        std::cout << "x = " << x << std::endl;
        std::cout << "f(x) = " << fx << std::endl;
        std::cout << "f'(x) =\n" << jacobi_f;
        std::cout << "(f'(x))^(-1) =\n" << jacobi_inv;
        CMyVektor dx = jacobi_inv * (-1 * fx);
        std::cout << "dx = " << dx << std::endl;
        std::cout << "||f(x)|| = " << length << std::endl << std::endl;
        x = x + dx;
        fx = funktion(x);
        length = fx.get_length();
    }
    if (i == steps)
    {
        std::cout << "Ende, da maximale Schrittzahl erreicht wurde bei\n";
        std::cout << "x = " << x << std::endl;
        std::cout << "f(x) = " << fx << std::endl;
        std::cout << "||f(x)|| = " << length << std::endl << std::endl;
    }
    else
    {
        std::cout << "Ende wegen ||f(x)||<1e-5 bei\n";
        std::cout << "x = " << x << std::endl;
        std::cout << "f(x) = " << fx << std::endl;
        std::cout << "||f(x)|| = " << length << std::endl << std::endl;
    }
    return x;
}

CMyVektor maximize_newton(CMyVektor x, double(*funktion)(CMyVektor x), int steps)
{
    CMyVektor fx = gradient(x,funktion);
    double length = fx.get_length();
    assert(x.get_dimension() == 2 && fx.get_dimension() == 2);
    int i;
    for (i = 0; i < steps && length>1e-5; i++)
    {
        CMyMatrix jacobi_f = jacobi(x, funktion);
        CMyMatrix jacobi_inv = jacobi_f.invers();
        std::cout << "Schritt " << i << ":\n";
        std::cout << "x = " << x;
        std::cout << "f(x) = " << fx;
        std::cout << "f'(x) =\n" << jacobi_f;
        std::cout << "(f'(x))^(-1) =\n" << jacobi_inv;
        CMyVektor dx = jacobi_inv * (-1 * fx);
        std::cout << "dx = " << dx;
        std::cout << "||f(x)|| = " << length << std::endl << std::endl;
        x = x + dx;
        fx = gradient(x,funktion);
        length = fx.get_length();
    }
    if (i == steps)
    {
        std::cout << "Ende, da maximale Schrittzahl erreicht wurde bei\n";
        std::cout << "x = " << x;
        std::cout << "f(x) = " << fx;
        std::cout << "||f(x)|| = " << length << std::endl << std::endl;
        std::cout << "Result = " << funktion(x) << std::endl << std::endl;
    }
    else
    {
        std::cout << "Ende wegen ||f(x)||<1e-5 bei\n";
        std::cout << "x = " << x;
        std::cout << "f(x) = " << fx;
        std::cout << "||f(x)|| = " << length << std::endl << std::endl;
        std::cout << "Result = " << funktion(x) << std::endl << std::endl;
    }
    return x;
}