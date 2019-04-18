#pragma once
#include <vector>
#include "Point.h"
#include <string>

double euler(double x, double y0, double h, double(*fun)(double));
void diffeq_main();
double heune(double x, double y0, double h, double(*fun)(double));

//Wrapper for math functions
double (*math_wrapper(std::string, double))(double);
double (*math_wrapper(std::string))(double);
double (*math_wrapper(std::string, std::vector<double>))(double);

//Math functions
double math_pow(double);
double math_exp(double);
double math_linear(double);
double math_const_func(double);
double math_poly(double);