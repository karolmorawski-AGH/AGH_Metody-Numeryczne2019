#pragma once
#include <vector>
#include "Point.h"
#include <string>
#include <iostream>

//System of linear equations

//Matrix determinant
double matrixDeterminant(std::vector<std::vector<double>>);
//Gaussian elimination
std::vector<double> gaussianElimination(std::vector<std::vector<double>>, std::vector<double>);


void gauss_display(std::vector<double>);

//Main
void gauss_main();