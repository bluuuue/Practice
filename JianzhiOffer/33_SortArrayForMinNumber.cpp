#include <iostream>
#include <iostream>

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

int PrintMinNUmberOfArray(int *numbers, int nLength)
{
}

int main()
{
	int data[3] = {3, 32, 321};
	PrintMinNumberOfArray(data);
    return 0;
}
}
