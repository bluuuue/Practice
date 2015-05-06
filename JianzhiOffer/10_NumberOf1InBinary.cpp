#include <iostream>
#include <bitset>

int numberOf1(int n)
{
//	if(n < 0)
//	{
//		n = 0 - n;
//	}
	unsigned int flag = 1;
	int count1 = 0;
	while(flag)
	{
		if(n & flag)
		{
			++count1;
		}
		flag = flag << 1;
	}
	return count1;
}

int numberOf1_faster(int n)
{
	int count = 0;
	while(n)
	{
		++count;
		n = (n & (n - 1));
	}
	return count;
}

int main()
{
	std::cout << numberOf1(0) << std::endl;
	std::cout << numberOf1(1023) << std::endl;
	std::cout << numberOf1(-1023) << std::endl;
	std::cout << numberOf1_faster(0) << std::endl;
	std::cout << numberOf1_faster(1023) << std::endl;
	std::cout << numberOf1_faster(-1023) << std::endl;
	return 0;
}


/*
001000
000111

010101
010100
010011


*/
