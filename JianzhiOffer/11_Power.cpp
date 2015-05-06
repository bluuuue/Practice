#include <iostream>

bool equal(double num1, double num2);

double Power(double base, int exponent)
{
	double dResult = 1.0;

	if(exponent < 0)
	{
		for(int i = 0; i != -exponent; ++i)
		{
			dResult *= base;
		}

		if( equal(dResult, 0.0) )
		{
			dResult = 0;
		}
		else
		{
			dResult = 1 / dResult;
		}

		if( equal(base, 0.0) )
		{
			dResult = 0;
		}
	}
	else
	{
		for(int i = 0; i != exponent; ++i)
		{
			dResult *= base;
		}

		if( equal(base, 0.0) )
		{
			dResult = 0;
		}
	}

	return dResult;
}

bool equal(double num1, double num2)
{
	if( (num1 - num2 < 0.0000001) &&
		(num2 - num1 < 0.0000001) )
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	std::cout << Power(0,0) << std::endl;
	std::cout << Power(0,-2) << std::endl;
	std::cout << Power(0,2) << std::endl;
	std::cout << Power(-10,2) << std::endl;
	std::cout << Power(-10,3) << std::endl;
	std::cout << Power(-10,0) << std::endl;
	std::cout << Power(-10,-2) << std::endl;
	std::cout << Power(-10,-3) << std::endl;
	std::cout << Power(10,2) << std::endl;
	std::cout << Power(10,0) << std::endl;
	std::cout << Power(10,-2) << std::endl;
	return 0;
}
