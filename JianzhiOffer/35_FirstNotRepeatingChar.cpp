#include <iostream>

char FirstNotRepeatingChar(char *pString)
{
    if (pString == NULL)
    {
        return '\0';
    }

    //The max size number of char(which occupy 1 byte, 8 bits) is 256.
    const int nHashTableSize = 256; 
    unsigned int HashTable[nHashTableSize] = {0};

    char* pHashKey = pString;
    while (*pHashKey != '\0')
    {
        ++HashTable[*(pHashKey++)]; 
    }

    pHashKey = pString;
    while (*pHashKey != '\0')
    {
        if (HashTable[*pHashKey] == 1)
        {
            return *pHashKey;
        }
        ++pHashKey;
    }

    return '\0';
}

int main()
{
    char *pString = "sdlfjkoirsdlfnsdlfw;sfuweslfsdflsabaccdeff";
    std::cout << "The first not repeating char is: " << FirstNotRepeatingChar(pString) << std::endl;

    return 0;
}
