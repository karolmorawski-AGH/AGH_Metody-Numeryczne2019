#include "InterNewton.h"
#include "Point.h"
#include <vector>
#include "MnMath.h"

int newtonlength = 0;
std::vector<newtonCache> cache;

double newton(int value, std::vector<double> x, std::vector<double> y) {

	//Check for data inconsistency
	if(x.size() != y.size())
	{
		return NAN;
	}

	//p0=1
	double ret = 1;

	//n-1
	int stopien = x.size() - 1;

	std::vector<double> coefficients;

	//calculating coefficients 
	for (int i = 0; i < stopien; i++) {
		coefficients.push_back(newtonCoeff(i + 1, x, y, 0));
	}

	//calculating value
	for (int i = 0; i < stopien; i++) {

		double temp = 1;
		for (int j = 0; j <= i; j++) {
			temp = temp*(value - x[j]);
		}

		ret = ret + coefficients[i] * temp;
	}
	return ret;
}

double newtonCoeff(int stopien, std::vector<double> x, std::vector<double> y, int pos) {

	if (stopien == 1)
	{
		double return_val = (y[pos + 1] - y[pos]) / (x[pos + 1] - x[pos]);
		return return_val;
	}

	for (int i = 0; i < newtonlength; i++)
	{
		if (cache[i].position == pos && cache[i].stopien == stopien)
		{
			return cache[i].value;
		}
	}

	double return_val = (newtonCoeff(stopien - 1, x, y, pos + 1) - newtonCoeff(stopien - 1, x, y, pos)) / (x[pos + stopien] - x[pos]);
	cache.push_back({ pos,stopien,return_val });
	newtonlength++;

	return return_val;
}