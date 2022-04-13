/**
 * @author Linus Palm
 */
#pragma once

class CKomplex
{
private:
	double a, b; // a = Re(z), b = Im(z)
public:
	CKomplex();
	CKomplex(double a, double b);
	CKomplex(double phi);

	double re() const { return a; }
	double im() const { return b; }
	CKomplex konj() const;

	void setkar(double a, double b);
	void setpol(double phi);

	CKomplex operator + (const CKomplex x) const;
	CKomplex operator * (const CKomplex x) const;
	CKomplex operator * (const double x) const;
	CKomplex operator - (const CKomplex x) const;

	double abs() const;
};