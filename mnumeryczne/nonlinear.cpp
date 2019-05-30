#include "nonlinear.h"
#include "Point.h"
#include <vector>
#include "MnMath.h"
#include "newton-cotes.h"
#include <iostream>
#include "diffeq.h"
#include "math.h"

//newton-raphson
double newtonRaphson(double a, double b, double(*fun)(double), double(*funD)(double)) {

	double middle = a + b;
	middle /= 2;

	if (fun(middle) == 0) {
		return middle;
	}

	double xn = a;

	while (abs(fun(xn)) >= 0.1) {
		xn = xn - (fun(xn) / funD(xn));
	}

	return xn;
	
}


double bisection(double a, double b, double(*fun)(double)) {


	double middle = a + b;
	middle /= 2;

	if (fun(middle) == 0) {
		return middle;
	}

	while (abs(a - b) >= 0.0001) {

		if (fun(middle) * fun(a) < 0) {
			b = middle;
		}

		if (fun(middle) * fun(b) < 0) {
			a = middle;
		}
		
		middle = (a + b) / 2;
	}

	return middle;
}

//falsi
double falsi(double a, double b, double(*fun)(double)) {


	double x1 = a, x0 = b;
	double f0;
	double fa = fun(a);
	double fb = fun(b);
	while (fabs(b - a) > 0.0001)
	{
		x1 = x0;
		x0 = a - fa * (b - a) / (fb - fa);
		f0 = fun(x0);
		if (fabs(f0) < 0.0001) break;
		if (fa * f0 < 0)
		{
			b = x0; fb = f0;
		}
		else
		{
			a = x0; fa = f0;
		}
	}
	return x0;
}

//false line
double false_line(double a, double b, double(*fun)(double)) {


	double q = floor(b - 2.);

	while (fun(b) * fun(q) < 0.) {
		q -= 1.;
	}

	double x1 = a, x0 = b;
	double f0;
	double fa = fun(a);
	double fb = fun(b);
	double fq = fun(q);
	while (fabs(b - a) > 0.0001)
	{
		x1 = x0;
		x0 = a - fa * (q - a) / (fq - fa);
		f0 = fun(x0);
		if (fabs(f0) < 0.0001) break;
		if (fa * f0 < 0)
		{
			b = x0; fb = f0;
		}
		else
		{
			a = x0; fa = f0;
		}
	}
	return x0;
}

double pegaz(double a, double b, double(*fun)(double)) {
	if (fun(a) * fun(b) >= 0) {
		return NAN;
	}

	return 0.0;
}

//x^3 + x^2 - 3x - 3 = 0
double first_func(double x) {
	return (x * x * x + x * x - 3 * x  -3);
}

double first_func_d(double x, double y) {
	return (x * x * x + x * x - 3 * x - 3);
}

double first_func_der(double x) {
	return (3 * x * x + 2 * x - 3);
}

double snd_func(double x) {
	return (sin(x * x) - x * x);
}

double snd_func_der(double x) {
	return (2*x * cos(x) - 2*x);
}



/*
double first_func(double x) {
	return (x * x - 1);
}

double first_func_der(double x) {
	return 2 * x;
}
*/

//main
void nonlinear_main() {
	std::cout << "Newton-Raphson: " << newtonRaphson(-1, 1, snd_func, snd_func_der) << std::endl;
	std::cout << "Bisection: " << bisection(-1, 1, snd_func) << std::endl;
	std::cout << "Regula Falsi: " << falsi(-0.01, 0.01, snd_func) << std::endl;
	std::cout << "False line: " << false_line(-0.01, 0.01, snd_func) << std::endl;
	std::cout << "Pegaza: " << pegaz(1, 100, first_func) << std::endl;

}