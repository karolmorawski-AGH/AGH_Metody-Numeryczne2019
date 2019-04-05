#pragma once
#include <vector>
#include "Point.h"
#include <string>


struct newtonCache {
	int stopien;
	int position;
	double value;
};

double newton(int value, std::vector<double> x, std::vector<double> y);
double newtonCoeff(int, std::vector<double>, std::vector<double>, int);