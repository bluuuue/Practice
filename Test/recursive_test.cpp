#include <iostream>

int AddFrom1ToN_recursive(int n)
{
	return n <= 0 ? 0 : n + AddFrom1ToN_recursive(n - 1);
}

int main()
{
	std::cout << AddFrom1ToN_recursive(1000000) << std::endl;
	return 0;
}

