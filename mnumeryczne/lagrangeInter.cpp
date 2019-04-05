#include "lagrangeInter.h"

typedef unsigned int uint;

double lag_inter(double pval)
{
	std::vector<std::vector<double>> dataArray = doubleVector(readCSV("data.txt"));

	//Polynomial degree
	double st = dataArray[0][0];
	const uint n = static_cast<unsigned int>(st);

	//Creating points
	std::vector<pnt> point;

	for (int i = 1; i < dataArray.size(); i++)
	{
		pnt temp;
		temp.x = dataArray[i][0];
		temp.y = dataArray[i][1];
		point.push_back(temp);
	}

	//Error handling
	if(point.size()>n+1)
	{
		std::cout << "WARNING: Polynomial degree equals " << n << " but there are " << point.size() << " (x,y) points" << std::endl;
	}
	else if(point.size()<n+1)
	{
		std::cout << "ERROR: Polynomial degree equals " << n << " which is greater than number of (x,y) points" << std::endl;
		exit(-1);
	}

	//Lagrange interpolation
	double result = 0;

	for (uint i = 0; i < n+1; i++)
	{
		double value = point[i].y;
		for (uint j = 0; j < n+1; j++)
		{
			if (j != i)
				value = value * (pval - point[j].x) / double(point[i].x - point[j].x);
		}
		result = result + value;
	}

	return result;
}