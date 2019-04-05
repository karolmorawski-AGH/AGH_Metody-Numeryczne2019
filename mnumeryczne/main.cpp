#include <iostream>
#include "MnMath.h"
#include "lagrangeInter.h"
#include "LeastSquares.h"
#include "InterNewton.h"
#include <vector>
#include "Integration.h"
#include "newton-cotes.h"

using namespace std;

int main() {
	
	//vector<double> wsp1 = {55,-2,-6,5,0.4};
	vector<double> wsp1 = { 0.4, 5,-6,-2,55 };
	//read data from file
	vector<double> x = { -2,-1.75,-1.35,-1.1,-0.9,-0.85,-0.8,-0.6,-0.5,-0.45,-0.4,-0.05,0,0.05,0.1,0.5,0.55,0.6,0.65,0.7,0.75,0.8,0.85,0.9,0.95,1,1.1,1.15,1.2,1.25,1.3,1.5,1.55,1.6,1.7,1.85,2 };

	double wsp2[] = { 1,-2,-6,5,0.4 };

	cout << integrationNum(x, wsp1, horner) << endl;



	//{-2,2} 49, 
}
