#pragma once
#include <vector>
#include "Point.h"
#include <string>

double rectangular_integration(std::vector<double>, int, int, unsigned int);
double rectangular_integration(std::string);

double trapezoidal_integration(std::vector<double>, int, int, unsigned int);
double trapezoidal_integration(std::string);
