#include "Integration.h"
#include "Point.h"
#include <vector>
#include "MnMath.h"


double rectangular_integration(std::vector<double> coefficients, int start, int end, unsigned int precision)
{
	//Setting desired "width" of rectangle (dx)
	double dx = end - start;
	dx = dx / precision;
	double x = start;

	//For loop for "moving" through x axis
	double result = 0;
	for(int i = 0; i< precision; i++)
	{
		x = x + dx;

		//calculating size under function
		for(int j =0; j<coefficients.size(); j++)
		{
			result = result + coefficients[j] * pow(x, coefficients.size() - j - 1);
		}
	}

	return result * dx;	
}

double rectangular_integration(std::string filename)
{
	std::vector<std::vector<double>> dataArray = doubleVector(readCSV(filename));
	double start = dataArray[0][0];
	double end = dataArray[1][0];
	double precision = dataArray[2][0];
	

	return 0.0;
}

double trapezoidal_integration(std::vector<double> coefficients, int start, int end, unsigned int precision)
{
	//Setting desired "width" of rectangle (dx)
	double dx = end - start;
	dx = dx / precision;
	double x = start;

	double result = 0;

	//stores f(x_i) and f(x_(i-1)) values
	double cache = 0;

	for(int i = 0; i < precision; i++)
	{
		cache = 0;
		//f(X_i)
		for(int j = 0; j<coefficients.size(); j++)
		{
			cache = cache + coefficients[j] * pow(x, coefficients.size() - 1 - j);
		}

		//i+1
		x = x + dx;

		//f(X_i+1)
		for(int k=0; k<coefficients.size(); k++)
		{
			cache = cache + coefficients[k] * pow(x, coefficients.size() - k - 1);
		}
		result = result + cache / 2;
	}

	return result * dx;
 }

double trapezoidal_integration(std::string filename)
{
	return 0.0;
}

//trapezy przyjmuje wezly (tablica wezlow i wskaznik do funkcji dla ktorej chcemy policzyc calke)
//zaimplementowanie kwadratow newtona-cotsa 
