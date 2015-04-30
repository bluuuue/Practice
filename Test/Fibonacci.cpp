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

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
	std::cout << Fibonacci(15) << std::endl;
	return 0;
}
