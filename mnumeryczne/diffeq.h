#pragma once
#include <vector>
#include "Point.h"
#include <string>

double euler(double x, double y0, double h, double(*fun)(double, double));
double heune(double x, double y0, double h, double(*fun)(double, double));
double euler_mod(double x, double y0, double h, double(*fun)(double, double));
double runge_kutta(double x, double y0, double h, double(*fun)(double, double));

void diffeq_main();
