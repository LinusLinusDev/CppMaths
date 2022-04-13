/**
 * @author Linus Palm
 */
#include <math.h>
#include "CKomplex.h"

CKomplex::CKomplex() :a{ 0 }, b{ 0 }{}

CKomplex::CKomplex(double a, double b) :a{ a }, b{ b }{}

CKomplex::CKomplex(double phi) : a{ cos(phi) }, b{ sin(phi) }{}

CKomplex CKomplex::konj() const
{
	CKomplex z(a, -b);
	return z;
}

void CKomplex::setkar(double a, double b)
{
	this->a = a;
	this->b = b;
}

void CKomplex::setpol(double phi)
{
	a = cos(phi);
	b = sin(phi);
}

CKomplex CKomplex::operator + (const CKomplex x) const
{
	CKomplex result(a + x.a, b + x.b);
	return result;
}

CKomplex CKomplex::operator * (const CKomplex x) const
{
	CKomplex result(a * x.a - b * x.b, a * x.b + b * x.a);
	return result;
}

CKomplex CKomplex::operator * (const double x) const
{
	CKomplex result(x * a, x * b);
	return result;
} 

double CKomplex::abs() const
{
	return sqrt(a * a + b * b);
}

CKomplex CKomplex::operator - (const CKomplex x) const
{
	CKomplex result(a - x.a, b - x.b);
	return result;
}