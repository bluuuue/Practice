#include<iostream>

/*
int main()
{
	//the difference between char array and char pointer
	char str1[] = "test";
	char str2[] = "test";
	
	char *str3 = "test";
	char *str4 = "test";
	
	if (str1 == str2)
		std::cout << "1" << std::endl;
	else
		std::cout << "0" << std::endl;
		
	if (str3 == str4)
		std::cout << "1" << std::endl;
	else
		std::cout << "0" << std::endl;
		
	str3[3] = '1';		//error: const char cann't be alter
	
	return 0;
}
*/

int main()
{
	char input[] = "We are happy.";
	
	//put the result into a new char array
	int blank_count = 0;
	for (int i = 0; i != strlen(input); ++i)
	{
		if (input[i] == " ")
			++blank_count;
	}
	char *output = new char[](strlen(input) + 2 * blank_count);
	
	for (int i = 0; i != strlen(input); ++i)
	{
		if (input[i] != " ")
			output[i] = input[i];

	}


	return 0;
}
