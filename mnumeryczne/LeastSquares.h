#pragma once
#include <vector>
#include "Point.h"
#include <string>
#include "lagrangeInter.h"

double Legendr(double x, double k);

double scalarUnitary(std::vector<double>, std::vector<double>);

double hWithStar(double x, std::string filename);

std::vector<Point> getPoints(std::string);

double get_degree(std::string);