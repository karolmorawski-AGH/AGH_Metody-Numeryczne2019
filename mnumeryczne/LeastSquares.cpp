#include "LeastSquares.h"
#include "Point.h"
#include <vector>
#include "MnMath.h"

//GOOD
double Legendr(double x, double k)
{
	if (k == 0) { return 1; }
	if (k == 1) { return x; }

	return (float)(((2.0 * k - 1) / k)* x *Legendr(x, k-1.0)-(((k-1.0))/k)*Legendr(x, k-2.0));
}

//BAD
std::vector<double> LegendrVec(std::vector<double> x, double k)
{
	std::vector<double> vectors;
	for(int i=0; i<x.size(); i++)
	{
		vectors.push_back(Legendr(x[i], k));
	}
	return vectors;
}


double scalarUnitary(std::vector<double> a, std::vector<double> b)
{
	double sum = 0.0;
	int length;
	if (a.size() > b.size()) { length = b.size(); }
	else if (b.size() > a.size()) { length = a.size(); }
	else { length = a.size();  }

	for(int i =0; i<length; i++)
	{
		sum = sum + a[i] * b[i];
	}
	return (float)sum;
}


double hWithStar(double x, std::string filename)
{
	std::vector<std::vector<double>> dataArray = doubleVector(readCSV("polynomial-4.csv"));

	//Polynomial degree
	double st = dataArray[0][0];
	const unsigned int n = static_cast<unsigned int>(st);

	//creating points
	std::vector<double> X;
	std::vector<double> Y;

	for (int i = 1; i < n+1; i++)
	{
		X.push_back(dataArray[i][0]);
		Y.push_back(dataArray[i][1]);
	}

	if ((n > X.size()+1) || (n > Y.size()+1))
	{
		std::cout << "error" << std::endl;
		exit(-1);
	}

	double sum = 0.0;
	double a, b;

	std::vector<double> lag(n);
	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			lag[j] = Legendr(X[j], i);
			a = scalarUnitary(Y, lag);
			b = scalarUnitary(lag, lag);
		}
		sum = sum + Legendr(x, i) * (a / b);
	}
	return sum;
}