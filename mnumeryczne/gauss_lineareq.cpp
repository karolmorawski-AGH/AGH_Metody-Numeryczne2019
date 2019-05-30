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
	else if (matrixsize == 4) {
		return matrix[0][0] * (matrix[1][1] * matrix[2][2] * matrix[3][3] + matrix[1][2] * matrix[2][3] * matrix[3][1] + matrix[1][3] * matrix[2][1] * matrix[3][2] - matrix[1][3] * matrix[2][2] * matrix[3][1] - matrix[1][1] * matrix[2][3] * matrix[3][2] - matrix[1][2] * matrix[2][1] * matrix[3][3]) - matrix[0][1] * (matrix[1][0] * matrix[2][2] * matrix[3][3] + matrix[1][2] * matrix[2][3] * matrix[3][0] + matrix[1][3] * matrix[2][0] * matrix[3][2] - matrix[1][3] * matrix[2][2] * matrix[3][0] - matrix[1][0] * matrix[2][3] * matrix[3][2] - matrix[1][2] * matrix[2][0] * matrix[3][3]) + matrix[0][2] * (matrix[1][0] * matrix[2][1] * matrix[3][3] + matrix[1][1] * matrix[2][3] * matrix[3][0] + matrix[1][3] * matrix[2][0] * matrix[3][1] - matrix[1][3] * matrix[2][1] * matrix[3][0] - matrix[1][0] * matrix[2][3] * matrix[3][1] - matrix[1][1] * matrix[2][0] * matrix[3][3]) - matrix[0][3] * (matrix[1][0] * matrix[2][1] * matrix[3][2] + matrix[1][1] * matrix[2][2] * matrix[3][0] + matrix[1][2] * matrix[2][0] * matrix[3][1] - matrix[1][2] * matrix[2][1] * matrix[3][0] - matrix[1][0] * matrix[2][2] * matrix[3][1] - matrix[1][1] * matrix[2][0] * matrix[3][2]);
	}
	else {
		det = NAN;
	}

	return det;
}

std::vector<double> gaussianElimination(std::vector<std::vector<double>> A, std::vector<double> B)
{
	std::vector<std::vector<double>> wx;
	std::vector<std::vector<double>> wy;
	std::vector<std::vector<double>> wz;

	
	//Creates matrix which adds B vector as last column to A matrix
	std::vector<std::vector<double>> matrix = A;

	for (int i = 0; i < A.size(); i++) {
		matrix[i].push_back(B[i]);
	}

	//Eliminatinon
	int n = matrix.size();
	for (int i = 0; i < n - 1; i++)            
		for (int k = i + 1; k < n; k++)
		{
			double t = matrix[k][i] / matrix[i][i];
			for (int j = 0; j <= n; j++)
			matrix[k][j] = matrix[k][j] - t * matrix[i][j];
		}

	//Calculating result vector
	std::vector<double> results;

	for (int i = 0; i < n; i++) {
		results.push_back(0);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		results[i] = matrix[i][n];
		for (int j = i + 1; j < n; j++)
			if (j != i)
				results[i] = results[i] - matrix[i][j] * results[j];
		results[i] = results[i] / matrix[i][i];
	}
	
	std::cout << std::endl << std::endl << std::endl;

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			std::cout << matrix[i][j] << "\t ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl << std::endl;

	return results;

}

void gauss_display(std::vector<double> results) {
	
	for(int i = 0; i < results.size(); i++) {
		std::cout << "x" << i << ": " << results[i] << std::endl;
	}
}

void gauss_main() {
	std::vector<std::vector<double>> a = { {1,-3,4, 6.8, 9}, {-3,2,4.6, 6.3, -10}, {2, -1, 2.8, -8.4, -5} , {-6, 2, 7, -0.5, -0.9}, {5, -2, -0.5, 12, -4} };
	std::vector<double> b = {74.6, -40.26, -2.32, 12.6, -8.9};
	//std::vector<std::vector<double>> a = { {-1,2,1}, {1,-3,-2}, {3,-1,4} };
	//std::vector<double> b = { -1,-1,4 };

	//result 2 -1 3

	gauss_display(gaussianElimination(a, b));
}