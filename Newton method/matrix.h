/**
 * @author Linus Palm
 */
#pragma once

#include "vektor.h"

const int default_lines = 2, default_columns = 2;

class CMyMatrix
{
private:
    int m, n;
    CMyVektor** A;
public:
    CMyMatrix(int lines = default_lines, int columns = default_columns);
    CMyMatrix(const CMyMatrix& orig);
    ~CMyMatrix();

    int get_lines() const { return m; }
    int get_columns() const { return n; }
    CMyMatrix invers();

    CMyVektor& operator [] (int index) { return *A[index]; }
};

std::ostream& operator<< (std::ostream& stream, const CMyMatrix& x);

CMyVektor operator*(CMyMatrix A, CMyVektor x);

CMyMatrix jacobi(CMyVektor x, CMyVektor(*funktion)(CMyVektor x));

CMyVektor newton(CMyVektor x, CMyVektor(*funktion)(CMyVektor x), int steps = 50);

CMyVektor maximize_newton(CMyVektor x, double(*funktion)(CMyVektor x), int steps = 25);