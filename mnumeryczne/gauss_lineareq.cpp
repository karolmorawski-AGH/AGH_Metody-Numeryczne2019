#include "gauss_lineareq.h"
#include "Point.h"
#include <vector>
#include "MnMath.h"
#include "newton-cotes.h"
#include <iostream>
















double matrixDeterminant(std::vector<std::vector<double>> matrix)
{
	int matrixsize = matrix.size();

	double det = NULL;

	if (matrixsize == 1) {
		det = matrix[0][0];
	}
	else if (matrixsize == 2) {
		det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}
	else if(matrixsize == 3){
		det = matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[0][2] * matrix[1][0] * matrix[2][1] - (matrix[0][2] * matrix[1][1] * matrix[2][0] + matrix[0][0] * matrix[1][2] * matrix[2][1] + matrix[0][1] * matrix[1][0] * matrix[2][2]);
	}
	else {
		det = NAN;
	}

	return det;
}

std::vector<double> gaussianElimination(std::vector<std::vector<double>> A, std::vector<double> B)
{
	std::vector<double> results;
	
	//1st 
	if (A.size() == 1) {
		results.push_back(B[0]/A[0][0]);
		return results;
	}

	std::cout << A.size() << std::endl;


	return results;
}

void gauss_display(std::vector<double> results) {
	
	std::cout <
	for (int i = 0; i < results.size(); i++) {

		std::cout << "x" << i << ": " << results[i] << std::endl;
	}
}

void gauss_main() {
	std::vector<std::vector<double>> a = { {10,-7,0}, {-3,2,6}, {5,-1,5} };
	std::vector<double> b = {6,4,3};

	gauss_display(gaussianElimination(a, b));
}