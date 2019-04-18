#include "diffeq.h"
#include "Point.h"
#include <vector>
#include "MnMath.h"
#include "newton-cotes.h"


//Euler

double euler(double x, double y0, double h, double(*fun)(double)) {

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
		y1 = prevy + h * fun(prevy);

		prevx = x1;
		prevy = y1;
	}

	return y1;
}

//Heuna

double heune(double x, double y0, double h, double(*fun)(double)) {

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
		y1 = prevy + h * 0.5 * fun());

		prevx = x1;
		prevy = y1;
	}

	return y1;
}


//Main
void diffeq_main() {
	//std::cout << euler(300., 1200., 0.1, p_ciepln) << std::endl;
	std::cout << heune(300., 1200., 1., p_ciepln) << std::endl;
}