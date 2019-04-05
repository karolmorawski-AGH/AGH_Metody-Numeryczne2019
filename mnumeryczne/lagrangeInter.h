#pragma once

#include "lagrangeInter.h"
#include "MnMath.h"
#include <iostream>

struct pnt
{
	double x;
	double y;
};

double lag_inter(double pval);
std::vector<std::vector<double>> lag_get_data(std::string filename);
