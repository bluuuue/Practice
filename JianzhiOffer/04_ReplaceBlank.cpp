#include<iostream>
#include<string.h>

/*
//the basic of character string
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

/*
//put the result into a new char array
int main()
{
	char input[] = "We are happy.";
	int blank_count = 0;
	for (int i = 0; i != strlen(input); ++i)
	{
		if (input[i] == ' ')
			++blank_count;
	}
	char *output = new char[strlen(input) + 2 * blank_count];

	int j = 0;
	for (int i = 0; i != strlen(input); ++i,++j)
	{
		if (input[i] != ' ')
		{
			output[j] = input[i];
		}
		else
		{
			output[j] = '2';
			output[++j] = '0';
			output[++j] = '%';
		}
	}

	for (int i = 0; i != strlen(output); ++i)
	{
		std::cout << output[i];
	}
	std::cout << std::endl;

	return 0;
}
*/

int ReplaceBlank(char str[], int length)
{
	if (str == NULL || length < 0)
		return -1;

	int old_length = strlen(str);
	int number_of_blank = 0;
	for (int i = 0; i != strlen(str); ++i)
	{
		if (str[i] == ' ')
			++number_of_blank;
	}

	int new_length = strlen(str) + 2 * number_of_blank;
	if (new_length > length)
		return -1;

	while (new_length >= 0 && new_length != old_length)
	{
		if (str[old_length] != ' ')
		{
			str[new_length--] = str[old_length--];
		}
		else
		{
			str[new_length--] = '%';
			str[new_length--] = '0';
			str[new_length--] = '2';
			--old_length;
		}
	}

	return 0;

}

int main()
{
	char str[20] = "We are happy.";
	int length = 20;

	if (ReplaceBlank(str, length) == -1)
		std::cout << "wrong" << std::endl;

	for(int i = 0; i != strlen(str); ++i)
	{
		std::cout << str[i];
	}
	std::cout << std::endl;

	return 0;
}

//待考虑：如果将空格改为20%后超过原字符串大小，如何扩充原字符串
