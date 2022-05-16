/**
 * @author Linus Palm
 */
#include <iostream>
#include "vektor.h"
#include "DGLSolver.h"

using namespace std;

CMyVektor DGL_system(CMyVektor y, double x)
{
    CMyVektor result(2);
    result[0] = 2 * y[1] - x * y[0];
    result[1] = y[0] * y[1] - 2 * x*x*x;
    return result;
}

double DGL_dritterOrdnung(CMyVektor y, double x)
{
    return 2 * x * y[1] * y[2] + 2 * y[0] * y[0] * y[1];
}

int main()
{
    C_DGLSolver systemTest(DGL_system);
    CMyVektor start1(2);
    start1[0] = 0;
    start1[1] = 1;
    //systemTest.euler(0, 2, 100, start1);
    //systemTest.heun(0, 2, 100, start1);

    C_DGLSolver dritterOrdnungTest(DGL_dritterOrdnung);
    CMyVektor start2(3);
    start2[0] = 1;
    start2[1] = -1;
    start2[2] = 2;
    //dritterOrdnungTest.euler(1, 2, 100, start2);
    //dritterOrdnungTest.heun(1, 2, 100, start2);

    return 0;
}