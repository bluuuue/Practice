#include "stdio.h"
#include "string.h"
#include "stdlib.h"

const int g_nMaxNumberLength = 10;

char *g_StrCombine1 = new char[g_nMaxNumberLength * 2 + 1];
char *g_StrCombine2 = new char[g_nMaxNumberLength * 2 + 1];

int Compare(const void *strNumber1, const void *strNumber2)
{
	strcpy(g_StrCombine1, *(const char **)strNumber1);
	strcat(g_StrCombine1, *(const char **)strNumber2);

	strcpy(g_StrCombine2, *(const char **)strNumber2);
	strcat(g_StrCombine2, *(const char **)strNumber1);

	return strcmp(g_StrCombine1, g_StrCombine2);
}

int PrintMinNumberOfArray(int *numbers, int nLength)
{
	if (numbers == NULL || nLength <= 0)
	{
		return -1;
	}

	char **strNumbers = (char**)(new int[nLength]);
	for (int i = 0; i < nLength; ++i)
	{
		strNumbers[i] = new char[g_nMaxNumberLength + 1];
		sprintf(strNumbers[i], "%d", numbers[i]);
	}

	qsort(strNumbers, nLength, sizeof(char*), Compare);

	for (int i = 0; i < nLength; ++i)
	{
		printf("%s", strNumbers[i]);
	}
	printf("\n");

	for (int i = 0; i < nLength; ++i)
	{
		delete[] strNumbers[i];
	}
	delete[] strNumbers;

	return 0;
}

int main()
{
	int data[3] = {3, 32, 321};
	PrintMinNumberOfArray(data, 3);
	return 0;
}

