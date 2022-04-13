/**
 * @author Linus Palm
 */
#include <iostream>
#include <fstream>
#include "DGLSolver.h"

using namespace std;

CMyVektor C_DGLSolver::ableitungen(CMyVektor y, double x)
{
	if (system)return f_System(y, x);
	else
	{
		int dimension = y.get_dimension();
		CMyVektor result(y.get_dimension());
		for (int i = 0; i < dimension - 1; i++)
		{
			result[i] = y[i + 1];
		}
		result[dimension - 1] = f_nterOrdnung(y, x);
		return result;
	}
}

void C_DGLSolver::euler(double x_start, double x_end, int steps, CMyVektor y_start)
{

	//Nur f�r Output
	fstream result;
	result.open("euler.csv",ios::out);
	int dimension = y_start.get_dimension();
	//

	double h = (x_end - x_start) / double(steps);
	cout << "h = " << h << endl << endl << endl;

	CMyVektor ableitung(ableitungen(y_start, x_start));
	for (int i = 0; i < steps; i++)
	{

		//Nur f�r Output
		for (int i = 0; i < dimension; i++)
		{
			result << y_start[i] << ";";
		}
		result << endl;
		//

		cout << "Schritt " << i << ":" << endl;
		cout << "x = " << x_start << endl;
		cout << "y = " << y_start << endl;
		cout << "y' = " << ableitung << endl << endl << endl;
		
		x_start += h;
		y_start = y_start + h * ableitung;
		ableitung = ableitungen(y_start, x_start);
	}
	cout << "Ende bei" << endl;
	cout << "x = " << x_start << endl;
	cout << "y = " << y_start << endl << endl << endl;

	//Nur f�r Output
	result.close();
	//

}

void C_DGLSolver::heun(double x_start, double x_end, int steps, CMyVektor y_start)
{

	//Nur f�r Output
	fstream result;
	result.open("heun.csv", ios::out);
	int dimension = y_start.get_dimension();
	//

	double h = (x_end - x_start) / double(steps);
	cout << "h = " << h << endl << endl << endl;

	CMyVektor ableitung(ableitungen(y_start, x_start));
	//for (int i = 0; i < steps; i++)
	while (x_start < x_end-h*0.5)
	{

		//Nur f�r Output
		for (int i = 0; i < dimension; i++)
		{
			result << y_start[i] << ";";
		}
		result << endl;
		//

		//cout << "Schritt " << i << ":" << endl;
		cout << "x = " << x_start << endl;
		cout << "y = " << y_start << endl;
		cout << "y'_orig = " << ableitung << endl << endl;

		CMyVektor y_test(y_start + h * ableitung);
		CMyVektor ableitung_test(ableitungen(y_test, x_start + h));

		cout << "y_Test = " << y_test << endl;
		cout << "y'_Test = " << ableitung_test << endl << endl;

		CMyVektor ableitung_mittel((ableitung + ableitung_test) * 0.5);

		cout << "y'_Mittel = " << ableitung_mittel << endl << endl << endl;

		x_start += h;
		y_start = y_start + h * ableitung_mittel;
		ableitung = ableitungen(y_start, x_start);
	}
	cout << "Ende bei" << endl;
	cout << "x = " << x_start << endl;
	cout << "y = " << y_start << endl << endl << endl;

	//Nur f�r Output
	result.close();
	//

}