#include <iostream>
using namespace std;

void FormatString(char str[], int nLength)
{
    if (str == NULL || nLength <= 0)
        return;

    int nStart = 0;
    while(str[nStart] == ' ')
        ++nStart;

    int nNewLength = nLength - 1 - nStart;

    int i = nStart;
    int j = 0;
    bool bBlankOccured = false;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            if (!bBlankOccured)
            {
                bBlankOccured = true;
                str[j] = ' ';
                ++j;
                ++i;
            }
            else
            {
                ++i;
                --nNewLength;
            }
            continue;
        }

        bBlankOccured = false;
        str[j] = str[i];
        ++j;
        ++i;
    }

    if (str[nLength - 2] == ' ')
        --nNewLength;

    str[nNewLength] = '\0';
}

void PrintString(char str[], int nLength)
{
    if (str == NULL || nLength <= 0)
    {
        return ;
    }

    int i = 0;
    while (str[i] != '\0')
    {
        cout << str[i];
        ++i;
    }
    cout << endl;
}

int main()
{
    char sentence[21] = "  i am   a   boy.   ";
    PrintString(sentence, 21);

    FormatString(sentence, 21);

    PrintString(sentence, 21);

    return 0;
} 
