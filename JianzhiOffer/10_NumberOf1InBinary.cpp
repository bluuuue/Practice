#include <iostream>

int numberOf1(int n)
{
	int flag = 1;
	while(flag)
	{
		flag = flag << 1;
		std::cout << flag << std::endl;
	}
	return 0;
}

int main()
{
	numberOf1(8);
	return 0;
}



