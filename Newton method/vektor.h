/**
 * @author Linus Palm
 */
#pragma once

const int default_dimensions = 3;

class CMyVektor
{
private:
    int n;
    double* A;
public:
    CMyVektor(int dimensions = default_dimensions);
    CMyVektor(const CMyVektor& orig);
    ~CMyVektor() { delete [] A; }

    int get_dimension() const { return n; }
    double get_length() const;

    CMyVektor& operator = (const CMyVektor& orig);
    CMyVektor operator + (const CMyVektor& b);
    CMyVektor operator * (double lambda);
    double operator * (const CMyVektor& b);
    double& operator [] (int index) { return A[index]; }
};

CMyVektor operator* (double lambda, CMyVektor a);

std::ostream& operator<< (std::ostream& stream, const CMyVektor& x);

CMyVektor gradient(CMyVektor x, double (*funktion)(CMyVektor));

CMyVektor maximize(CMyVektor start, double (*funktion)(CMyVektor), double lambda = 1.0, int steps = 25);