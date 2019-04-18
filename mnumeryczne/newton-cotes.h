#pragma once
#include <vector>
#include "Point.h"
#include <string>
#include "MnMath.h"

//main functions
double integrationNum(std::vector<double> fx, double(*fun)(double));
double nc_trapez(double a, double b, int precision, double(*fun)(double));
double nc_simpson(double a, double b, int precision, double(*fun)(double));
double gauss_quad(double a, double b, int precision, double(*fun)(double));

//Main function (example)
void nc_main();