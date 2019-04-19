#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <typeinfo>

//Read as CSV file - default separator is ';'
std::vector<std::vector<std::string>> readCSV(std::string);
//Read as CSV file - specifies separator
std::vector<std::vector<std::string>> readCSV(std::string, char);
//Casts vector of strings from readCSV() as doubles
std::vector<std::vector<double>> doubleVector(std::vector<std::vector<std::string>>);

//Wrapper for math functions
double (*math_wrapper(std::string, double))(double);
double (*math_wrapper(std::string))(double);
double (*math_wrapper(std::string, std::vector<double>))(double);

//Math functions
double horner(std::vector<double>, unsigned int, double);
double hornerR(std::vector<double>, unsigned int, double);
double math_pow(double);
double math_exp(double);
double math_linear(double);
double math_const_func(double);
double math_poly(double);
double p_ciepln(double x, double y);