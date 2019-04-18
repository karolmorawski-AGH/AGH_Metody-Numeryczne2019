#include "newton-cotes.h"
#include "Point.h"
#include <vector>
#include "MnMath.h"
#include <math.h>

//Kwadratury
double integrationNum(std::vector<double> x,  double(* fun)(double))
{
	double result = 0;
	for(int i = 0; i<x.size()-1; i++)
	{
		result = result + ((x[i + 1] - x[i]) / 2) * fun(x[i]) + ((x[i + 1] - x[i]) / 2) * fun(x[i+1]);
	}
	
	return result;
}

double nc_trapez(double a, double b, int precision, double(*fun)(double))
{
	std::vector<double> x;
	double dx = (b - a) / precision;
	for(int i = 0; i<precision; i++)
	{
		x.push_back(a+ dx * i);
	}

	double result = 0;

	for (int i = 0; i < x.size()-1; i++)
	{
		result = result + (dx / 2) * fun(x[i]) + (dx / 2) * fun(x[i+1]);
	}

	return result;
}

double nc_simpson(double a, double b, int precision, double(*fun)(double))
{
	std::vector<double> x;
	double dx = (b - a) / precision;
	for (int i = 0; i < precision; i++)
	{
		x.push_back(a + dx * i);
	}

	double result = 0;

	for (int i = 0; i < x.size() - 1; i++)
	{
		result = result + (dx / 6) * fun(x[i]) + 4 * (dx / 6) * fun((x[i] + x[i + 1]) / 2) + (dx / 6) * fun(x[i + 1]);
	}

	return result;
}

//Kwadratura Gaussa
double gauss_quad(double a, double b, int precision, double(*fun)(double)) {

	double c = -1;
	double d = 1;

	//mapowanie na przedzial
	double alfa = (b-a) / (d - c);
	double beta = (a * d - b * c) / (d - c);

	double table[4][4];
	
	std::vector<double> x = { -0.577350, 0.577350, -0.774597, 0, 0.774597, -0.861136, -0.339981, 0.339981,  0.861136, -0.906180, -0.538469, 0, 0.538469, 0.906180 };
	std::vector<double> A = { 1, 1, 0.555555, 0.888888, 0.555555,0.347855, 0.652145, 0.652145, 0.347855, 0.236927, 0.478629, 0.568889, 0.478629, 0.236927};

	for (int i = 0; i < 14; i++) {
		A[i] = A[i] * alfa;
		x[i] = (x[i] * alfa) + beta;
	}

	double result = 0.0;


	if (precision == 1) {
		//n=1
		for (int i = 0; i <= 1; i++) {
			result = result + A[i] * fun(x[i]);
		}
	}
	else if (precision == 2) {
		//n=2
		for (int i = 2; i <= 4; i++) {
			result = result + A[i] * fun(x[i]);
		}
	}
	else if (precision == 3) {
		//n=3
		for (int i = 5; i <= 8; i++) {
			result = result + A[i] * fun(x[i]);
		}
	}
	else if (precision == 4) {
		//n=4
		for (int i = 9; i <= 13; i++) {
			result = result + A[i] * fun(x[i]);
		}
	}
	else
	{
		std::cout << "WARNING: Precision must be: in range <1,4>" << std::endl;
	}

	return result;
}


//Main function (example)
void nc_main()
{
	//Coefficents
	std::vector<double> wsp1 = { 0.4, 5,-6,-2,55 };
	std::vector<double> wsp2 = { 1,-2,-6,5,0.4 };

	//read x-val from file
	std::vector<std::vector<double>> dataArray = doubleVector(readCSV("../DataFiles/NC_x_val.csv"));
	std::vector<double> x;
	for (int i = 0; i < dataArray.size(); i++)
	{
		x.push_back(dataArray[i][0]);
	}

	//Output (real value == 193.12)

	std::cout << integrationNum(x, math_wrapper("math_poly", wsp1)) << std::endl;
	std::cout << nc_trapez(-2, 2, 1000, math_wrapper("math_poly", wsp1));
	std::cout << std::endl;
	std::cout << nc_simpson(-2, 2, 1000, math_wrapper("math_poly", wsp1));
	std::cout << std::endl;
	std::cout << gauss_quad(-2, 2, 2, math_wrapper("math_poly", wsp1));
}
