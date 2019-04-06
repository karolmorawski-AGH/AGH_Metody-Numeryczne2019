#include "newton-cotes.h"
#include "Point.h"
#include <vector>
#include "MnMath.h"
#include <math.h>

//required global parameters
//math_poly
std::vector<double> poly_coeff = { 0 };
//math_pow()
double power_of = 2.0;
//math_linear
double lin_tan = 1.0;
//math_const_funcs
double const_val = 1.0;
//e
const double _E = 2.71828;

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

//Wrappers for math functions
double (*math_wrapper(std::string func_name, double param))(double)
{
	if(func_name == "math_pow")
	{
		power_of = param;
		return *math_pow;
	}
	else if(func_name == "math_linear")
	{
		lin_tan = param;
		return *math_linear;
	}
	else if(func_name == "math_const_func")
	{
		const_val = param;
		return *math_const_func;
	}
	else
	{
		return nullptr;
	}
}

double (*math_wrapper(std::string func_name))(double)
{
	if (func_name == "math_exp") { return *math_exp;  }
	else { return nullptr;  }
}

double (* math_wrapper(std::string func_name, std::vector<double> param))(double)
{
	if(func_name == "math_poly")
	{
		poly_coeff = param;
		return *math_poly;
	}
	else
	{
		return nullptr;
	}
}


//Quadratic function
double math_pow(double x)
{
	const double result = pow(x, power_of);
	return result;
}

//e^x
double math_exp(double x)
{
	const double result = pow(_E, x);
	return result;
}

//linear ax
double math_linear(double x)
{
	const double result = lin_tan * x;
	return result;
}

//Constant value
double math_const_func(double x)
{
	const double result = const_val;
	return result;
}

//Polynomial
double math_poly(double x)
{
	double st = poly_coeff.size() - 1;
	const double result = horner(poly_coeff, st, x);
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
}
