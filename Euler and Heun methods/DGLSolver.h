/**
 * @author Linus Palm
 */
#pragma once
#include "vektor.h"

class C_DGLSolver
{
private:
	bool system;
	CMyVektor(*f_System)(CMyVektor y, double x);
	double (*f_nterOrdnung)(CMyVektor y, double x);

	CMyVektor ableitungen(CMyVektor y, double x);
public:
	C_DGLSolver(CMyVektor(*f_DGL_System)(CMyVektor y, double x)) :system{ true }, f_System{ f_DGL_System }, f_nterOrdnung{ nullptr }{}
	C_DGLSolver(double(*f_DGL_nterOrdnung)(CMyVektor y, double x)) : system{ false }, f_System{ nullptr }, f_nterOrdnung{ f_DGL_nterOrdnung }{}

	void euler(double x, double end, int steps, CMyVektor y);
	void heun(double x, double end, int steps, CMyVektor y);
};