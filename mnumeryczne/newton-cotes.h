#pragma once
#include <vector>
#include "Point.h"
#include <string>
#include "MnMath.h"


double integrationNum(std::vector<double> fx, std::vector<double> wsp, double(*fun)(std::vector<double>, unsigned int, double));
