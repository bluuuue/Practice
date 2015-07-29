#include <iostream>
#include <string>
using namespace std;

string ReverseSentence(string strSentence)
{
	string strReverse = "";
	int nLeft = strSentence.size() - 1;
	int nRight = strSentence.size() - 1;
	for (; nLeft >= 0; )
	{
		while (nLeft >= 0 && strSentence[nLeft] != ' ')
			--nLeft;

		string strWord(strSentence, nLeft + 1, nRight - nLeft);
		strReverse += strWord;
		if (nLeft != -1)
		{
			strReverse += ' ';
		}
		--nLeft;
		nRight = nLeft;
	}
	return strReverse;
}

void Reverse(char *pA, char *pB)
{
	if (pA == NULL || pB == NULL)
		return;

	while (pA < pB)
	{
		char cTemp = *pA;
		*pB = *pA;
		*pA = cTemp;
		++pA;
		--pB;
	}
	return;
}

char* ReverseSentence(char *pData)
{
	if (pData == NULL)
		return pData;

	char *pHead = pData;
	char *pTail = pData;
	while (*pTail != '\0')
		++pTail;
	--pTail;

	Reverse(pHead, pTail);
	cout << *pData << endl;

	pTail = pHead;
	while (*pHead != '\0')
	{
		while (*pTail != ' ' && *pTail != '\0')
			++pTail;
		--pTail;
		Reverse(pHead, pTail);
		pHead = pTail + 2;
		pTail = pHead;

		if (*(--pHead) == '\0')
			break;
		else
			++pHead;
	}

	return pData;
}

int main()
{
	//string test("I am a student.");
	//cout << ReverseSentence(test) << endl;
	
	char sentence[] = {"I am a student."};
	cout << ReverseSentence(sentence);

	return 0;
}
