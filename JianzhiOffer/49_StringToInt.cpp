#include <iostream>
#include <string>
using namespace std;

bool g_bInvalid = false;
int StringToInt(string strInput)
{
    int nLength = strInput.size();
    if (nLength == 0)
    {
        g_bInvalid = true;
        return 0;
    }

    bool bMinus = false;
    bool bChar = false;
    if (strInput[0] == '+')
    {
        bChar = true;
    }
    if (strInput[0] == '-')
    {
        bMinus = true;
        bChar = true;
    }

    int i = 0;
    if (bChar)
    {
        if (nLength == 1)
        {
            g_bInvalid = true;
            return 0;
        }
        i = 1;
    }

    int nNumber = 0;
    for (; i < nLength; ++i)
    {
        if (strInput[i] - '0' < 0 || strInput[i] - '0' > 9)
        {
            g_bInvalid = true;
            return 0;
        }

        nNumber = (nNumber * 10 + strInput[i] - '0');
    }

    return bMinus ? (0 - nNumber) : nNumber;
}

int main()
{
    g_bInvalid = false; 
    cout << StringToInt("") << "\t" << g_bInvalid << endl;
    g_bInvalid = false; 
    cout << StringToInt("+") << "\t" << g_bInvalid << endl;
    g_bInvalid = false; 
    cout << StringToInt("-") << "\t" << g_bInvalid << endl;
    g_bInvalid = false; 
    cout << StringToInt("0") << "\t" << g_bInvalid << endl;
    g_bInvalid = false; 
    cout << StringToInt("+13423") << "\t" << g_bInvalid << endl;
    g_bInvalid = false; 
    cout << StringToInt("-13423") << "\t" << g_bInvalid << endl;
    g_bInvalid = false; 
    cout << StringToInt("+0") << "\t" << g_bInvalid << endl;
    g_bInvalid = false; 
    cout << StringToInt("-0") << "\t" << g_bInvalid << endl;
    g_bInvalid = false; 
    cout << StringToInt("45") << "\t" << g_bInvalid << endl;
    g_bInvalid = false; 
    cout << StringToInt("4k5") << "\t" << g_bInvalid << endl;
    g_bInvalid = false; 
    cout << StringToInt("4+5") << "\t" << g_bInvalid << endl;

    return 0;
}
