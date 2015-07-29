#include <iostream>
#include <string>
using namespace std;

void Reverse(char *pA, char *pB)
{
	if (pA == NULL || pB == NULL)
		return;

	while (pA < pB)
	{
		char cTemp = *pA;
		*pA = *pB;
		*pB = cTemp;
		++pA;
		--pB;
	}
	return;
}

void PrintString(char *str)
{
    if ( str == NULL)
        return;

    char *pPrint = str;
    while (*pPrint != '\0')
        cout << *(pPrint++);
    cout << endl;
    return;
}

char* LeftRotateString(char *pData, int nPos)
{
	if (pData == NULL || nPos <= 0)
		return pData;

	char *pHead = pData;
	char *pTail = pData + nPos - 1;
	Reverse(pHead, pTail);
    //PrintString(pHead);

	pHead = pData + nPos;
	pTail = pData + nPos;
    while (*pTail != '\0')
        ++pTail;
    --pTail;
	Reverse(pHead, pTail);
    //PrintString(pHead);

    pHead = pData;
    Reverse(pHead, pTail);

	return pData;
}

int main()
{
	//string test("I am a student.");
	//cout << ReverseSentence(test) << endl;
	
	char sentence[] = {"abcdefghi"};
	cout << LeftRotateString(sentence, 3) << endl;

	return 0;
}
