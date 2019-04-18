#include "MnMath.h"
#include <iterator>

// required global parameters
//math_poly
std::vector<double> poly_coeff = { 0 };
//math_pow()
double power_of = 2.0;
//math_linear
double lin_tan = 1.0;
//math_const_funcs
double const_val = 1.0;
//e
const double _E = 2.71828;

double horner(std::vector<double> wsp, unsigned int st, double x)
{
	double wynik = wsp[0];

	for (unsigned int i = 1; i <= st; i++)
		wynik = wynik * x + wsp[i];

	return wynik;
}

double hornerR(std::vector<double> wsp, unsigned int st, double x)
{
	if (st == 0)
		return wsp[0];

	return x * hornerR(wsp, st - 1, x) + wsp[st];
}

std::vector<std::vector<std::string>> readCSV(std::string path, char del)
{
	const char delimeter = del;

	std::ifstream fh(path, std::ifstream::binary);
	if (!fh.is_open())
	{
		std::cout << "ERROR: File " << path << " cannot be opened" << std::endl;
		exit(-1);
	}

	/*Buffered read*/
	fh.seekg(0, fh.end);
	int length = fh.tellg();
	fh.seekg(0, fh.beg);

	char* buffer = new char[length + 1];

	fh.read(buffer, length);
	//NULL terminator
	buffer[length] = '\0';
	fh.close();

	if (!fh)
	{
		std::cout << "ERROR: Only " << fh.gcount() << "could be read in " << path << std::endl;
	}

	std::string fileContent(buffer);
	delete[] buffer;

	/*String parsing and putting into vector*/
	std::vector<std::vector<std::string>> content;
	std::string temp;
	std::vector<std::string> tempVector;


	while (true)
	{
		if (fileContent.find(delimeter) < fileContent.find("\r\n"))
		{
			temp = fileContent.substr(0, fileContent.find(delimeter));
			fileContent = fileContent.substr(fileContent.find(delimeter) + 1);
			tempVector.push_back(temp);
		}
		else if (fileContent.find(delimeter) > fileContent.find("\r\n"))
		{
			temp = fileContent.substr(0, fileContent.find("\r\n"));
			fileContent = fileContent.substr(fileContent.find("\r\n") + 2);
			tempVector.push_back(temp);
			content.push_back(tempVector);
			tempVector.clear();
		}
		else
		{
			temp = fileContent;
			tempVector.push_back(temp);
			content.push_back(tempVector);
			tempVector.clear();
			break;
		}
	}

	return content;
}

std::vector<std::vector<std::string>> readCSV(std::string path)
{
	return readCSV(path, ';');
}

std::vector<std::vector<double>> doubleVector(std::vector<std::vector<std::string>> stringvector)
{
	std::vector<std::vector<double>> casted;

	if(stringvector[0][0].empty())
	{
		std::cout << "ERROR: Vector of strings is empty, cannot cast it to double\n";
		exit(-1);
	}

	for(unsigned int i=0; i<stringvector.size(); i++)
	{
		std::vector<std::string> tocast = stringvector[i];
		std::vector<double> temp;
		temp.reserve(stringvector.size());
		transform(tocast.begin(), tocast.end(), back_inserter(temp),
			[](std::string const& val) {return stod(val); });

		casted.push_back(temp);
	}
	return casted;
}


//Wrappers for math functions
double (*math_wrapper(std::string func_name, double param))(double)
{
	if (func_name == "math_pow")
	{
		power_of = param;
		return *math_pow;
	}
	else if (func_name == "math_linear")
	{
		lin_tan = param;
		return *math_linear;
	}
	else if (func_name == "math_const_func")
	{
		const_val = param;
		return *math_const_func;
	}
	else
	{
		return nullptr;
	}
}

double (*math_wrapper(std::string func_name))(double)
{
	if (func_name == "math_exp") { return *math_exp; }
	else { return nullptr; }
}

double (*math_wrapper(std::string func_name, std::vector<double> param))(double)
{
	if (func_name == "math_poly")
	{
		poly_coeff = param;
		return *math_poly;
	}
	else
	{
		return nullptr;
	}
}



//Quadratic function
double math_pow(double x)
{
	const double result = pow(x, power_of);
	return result;
}

//e^x
double math_exp(double x)
{
	const double result = pow(_E, x);
	return result;
}

//linear ax
double math_linear(double x)
{
	const double result = lin_tan * x;
	return result;
}

//Constant value
double math_const_func(double x)
{
	const double result = const_val;
	return result;
}

//Polynomial
double math_poly(double x)
{
	double st = poly_coeff.size() - 1;
	const double result = horner(poly_coeff, st, x);
	return result;
}

//Przewodnictwo cieplne
double p_ciepln(double x, double y) {
	//double alfa = -0.0000000000101;
	double alfa = -0.000000000001;
	double beta = 0;
	return alfa * (y * y * y * y - beta);
}

