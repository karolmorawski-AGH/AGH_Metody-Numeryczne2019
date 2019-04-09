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

//Main function (example)
void nc_main();