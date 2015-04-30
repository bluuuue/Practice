#include <iostream>

long long Fibonacci(unsigned int n)
{
	if(n <= 0)
	{
		return 0;
	}

	if(n == 1)
	{
		return 1;
	}

	long long num1 = 1;
	long long num2 = 1;
	long long num_temp = num2;
	unsigned int i = 2;
	while(i < n)
	{
		num2 += num1;
		num1 = num_temp;
		num_temp = num2;
		++i;
	}
	return num2;
}

int main()
{
	std::cout << Fibonacci(1) << std::endl;
	std::cout << Fibonacci(2) << std::endl;
	std::cout << Fibonacci(3) << std::endl;
	std::cout << Fibonacci(4) << std::endl;
	std::cout << Fibonacci(5) << std::endl;
	std::cout << Fibonacci(6) << std::endl;
	std::cout << Fibonacci(100) << std::endl;
	return 0;
}
