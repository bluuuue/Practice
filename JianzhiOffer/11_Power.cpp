#include <iostream>
#include <time.h>

#ifndef _CLOCK_T_DEFINED
typedef long clock_t;
#define _CLOCK_T_DEFINED
#endif

bool g_InvalidInput = false;

bool equal(double num1, double num2);

double Power(double base, int exponent)
{
	double dResult = 1.0;

	if( equal(base, 0.0) && exponent <= 0)
	{
		g_InvalidInput = true;
		return 0;
	}

	if(exponent < 0)
	{
		for(int i = 0; i != -exponent; ++i)
		{
			dResult *= base;
		}

		dResult = 1 / dResult;
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

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	if(exponent == 0)
	{return 1;}

	if(exponent == 1)
	{return base;}

	double dResult = PowerWithUnsignedExponent(base, exponent >> 1);
	dResult *= dResult;

	if(exponent & 0x1 == 1)
	{dResult *= base;}

	return dResult;
}

double PowerFaster(double base, int exponent)
{
	if( equal(base, 0.0) && exponent <= 0)
	{
		g_InvalidInput = true;
		return 0;
	}

	if(exponent < 0)
	{
		exponent = 0 - exponent;
	}

	double dResult = PowerWithUnsignedExponent(base, exponent);

	if(exponent < 0)
	{
		dResult = 1 /  dResult;
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
	clock_t start, finish1, finish2;
	start = clock();
	std::cout << Power(0,0) << std::endl;
	std::cout << Power(0,-22) << std::endl;
	std::cout << Power(0,22) << std::endl;
	std::cout << Power(-10,22) << std::endl;
	std::cout << Power(-10,32) << std::endl;
	std::cout << Power(-10,0) << std::endl;
	std::cout << Power(-10,-22) << std::endl;
	std::cout << Power(-10,-32) << std::endl;
	std::cout << Power(10,22) << std::endl;
	std::cout << Power(10,0) << std::endl;
	std::cout << Power(10,-22) << std::endl;
	finish1 = clock();
	std::cout << "Time: " << static_cast<double>(finish1 - start) << std::endl;
	start = clock();
	std::cout << PowerFaster(0,0) << std::endl;
	std::cout << PowerFaster(0,-22) << std::endl;
	std::cout << PowerFaster(0,22) << std::endl;
	std::cout << PowerFaster(-10,22) << std::endl;
	std::cout << PowerFaster(-10,32) << std::endl;
	std::cout << PowerFaster(-10,0) << std::endl;
	std::cout << PowerFaster(-10,-22) << std::endl;
	std::cout << PowerFaster(-10,-32) << std::endl;
	std::cout << PowerFaster(10,22) << std::endl;
	std::cout << PowerFaster(10,0) << std::endl;
	std::cout << PowerFaster(10,-22) << std::endl;
	finish2 = clock();
	std::cout << "Time: " << static_cast<double>(finish2 - start) << std::endl;
	return 0;
}
