#include "diffeq.h"
#include "Point.h"
#include <vector>
#include "MnMath.h"
#include "newton-cotes.h"


//Euler

double euler(double x, double y0, double h, double(*fun)(double, double)) {

	double n = x / h;

	double result = 0;

	if (h == 0) {
		return 0;
	}

	double prevx = 0;
	double prevy = y0;

	double x1, y1;

	for (double i = 0; i < x; i=i+h) {
		x1 = prevx + h;
		y1 = prevy + h * fun(prevx, prevy);

		prevx = x1;
		prevy = y1;
	}

	return y1;
}

//Heuna

double heune(double x, double y0, double h, double(*fun)(double, double)) {

	double n = x / h;

	double result = 0;

	if (h == 0) {
		return 0;
	}

	double prevx = 0;
	double prevy = y0;

	double x1, y1;

	for (double i = 0; i < x; i = i + h) {
		x1 = prevx + h;
		y1 = prevy + h * 0.5 * (fun(prevx, prevy) + fun(prevx + h, prevy + h*fun(prevx, prevy)));

		prevx = x1;
		prevy = y1;
	}

	return y1;
}

//Modified Euler
double euler_mod(double x, double y0, double h, double(*fun)(double, double))
{
	double n = x / h;

	double result = 0;

	if (h == 0) {
		return 0;
	}

	double prevx = 0;
	double prevy = y0;

	double x1, y1;

	for (double i = 0; i < x; i = i + h) {
		x1 = prevx + h;
		y1 = prevy + h * fun(prevx + 0.5 * h, prevy + 0.5 * h * fun(prevx, prevy));

		prevx = x1;
		prevy = y1;
	}

	return y1;
}

//Runge-Kutta 4th degree
double runge_kutta(double x, double y0, double h, double(*fun)(double, double))
{
	double n = x / h;

	double result = 0;

	if (h == 0) {
		return 0;
	}

	double prevx = 0;
	double prevy = y0;

	double x1, y1;
	double k1, k2, k3, k4;

	for (double i = 0; i < x; i = i + h) {
		x1 = prevx + h;
		y1 = fun(prevx, prevy);

		prevx = x1;
		prevy = y1;
		std::cout << y1 << std::endl;
	}

	k1 = fun(x, prevy);
	k2 = fun(x + (0.5 * h), prevy + (0.5 * k1 * h));
	k3 = fun(x + (0.5 * h), prevy + (0.5 * k2 * h));
	k4 = fun(x + h, prevy + (k3 * h));

	return prevy + (h * (k1 + k4 + 2.0 * (k2 + k3)) / 6.0);
}


//Runge-Kutta 4th and 3th:
/*
inline double frungek4(double* y, double x, double h, int i)
{
	double	k1 = foo(x, y[i - 1]);
	double	k2 = foo(x + (0.5 * h), y[i - 1] + (0.5 * k1 * h));
	double	k3 = foo(x + (0.5 * h), y[i - 1] + (0.5 * k2 * h));
	double	k4 = foo(x + h, y[i - 1] + (k3 * h));
	return y[i - 1] + (h * (k1 + k4 + 2.0 * (k2 + k3)) / 6.0);
}
inline double frungek3(double* y, double x, double h, int i)
{
	double	k1 = foo(x, y[i - 1]);
	double	k2 = foo(x + (0.5 * h), y[i - 1] + (0.5 * k1 * h));
	double	k3 = foo(x + h, y[i - 1] + (2.0 * k2 - k1) * h);
	return y[i - 1] + (h * (k1 + k3 + 4.0 * k2) / 6.0);
}
*/

//Main
void diffeq_main() {
	std::cout << "Euler: " << std::endl << euler(300., 1200., 0.01, p_ciepln) << std::endl;
	std::cout << "Heune: " << std::endl << heune(300., 1200., 1., p_ciepln) << std::endl;
	std::cout << "Modified Euler: " << std::endl << euler_mod(300., 1200., 1., p_ciepln) << std::endl;
	std::cout << "Runge-Kutta: " << std::endl << runge_kutta(300., 1200., 1., p_ciepln) << std::endl;
}