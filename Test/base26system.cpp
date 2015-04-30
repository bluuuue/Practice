/*in Excel:
	A:1
	B:2
	C:3
	***
	Z:26
	AA:27
	AB:28
	***
	AZ:52
	***
	***
*/	

#include <iostream>
#include <math.h>

int printColumn(char str[])
{
	long long int lColumns = 0;

	size_t nDigitNum = strlen(str);
	if(nDigitNum <= 0)
	{
		std::cout << "Input is wrong." << std::endl;
		return -1;
	}

	bool bWrongChar = false;
	for(int i = 0; i < nDigitNum; ++i)
	{
		int nCharNum = str[i] - 'A' + 1;

		if(nCharNum < 1 || nCharNum > 26)
		{
			bWrongChar = true;
		}

		lColumns += pow(26, nDigitNum - i - 1) * nCharNum;
	}

	if(bWrongChar)
	{
		std::cout << "Input char is wrong." << std::endl;
		return -1;
	}

	std::cout << lColumns << std::endl;
	return 0;
}

int main()
{
	char cInput1[] = "";
	char cInput2[] = "Z";
	char cInput3[] = "BKZ";
	char cInput4[] = "DSLJFBKZ";
	char cInput5[] = "DSLJaBKZ";
	char cInput6[] = "234";
	char cInput7[] = "abc";
	printColumn(cInput1);
	printColumn(cInput2);
	printColumn(cInput3);
	printColumn(cInput4);
	printColumn(cInput5);
	printColumn(cInput6);
	printColumn(cInput7);

	return 0;
}

	
