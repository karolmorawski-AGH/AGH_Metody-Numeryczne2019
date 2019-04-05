#include "newton-cotes.h"
#include "Point.h"
#include <vector>
#include "MnMath.h"

double integrationNum(std::vector<double> x, std::vector<double> wsp,  double(* fun)(std::vector<double>, unsigned int, double))
{
	double result = 0;
	for(int i = 0; i<x.size()-1; i++)
	{
		result = result + ((x[i + 1] - x[i]) / 2) * fun(wsp, wsp.size() - 1, x[i]) + ((x[i + 1] - x[i]) / 2) * fun(wsp, wsp.size() - 1, x[i+1]);
	}
	
	return result;
}

//przedzial a, b, precyzje, ab
double nc_trapez(double a, double b, int precision, double (*fun)(std::vector<double> x, std::vector<double> wsp, double(*fun2)(std::vector<double>, unsigned int, double)))
{
	std::vector<double> x;
	double dx = (b - a) / precision;
	for(int i = 0; i<precision; i++)
	{
		x.push_back(dx * a + i);
	}

	return 0;
}