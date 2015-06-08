#include <iostream>
#include <vector>

void PrintVectorChar(std::vector<char> vecChar)
{
    if (vecChar.empty() )
    {
        return;
    }

    for (std::vector<char>::iterator it = vecChar.begin(); \
            it != vecChar.end(); ++it)
    {
        std::cout << *it;
    }
    std::cout << std::endl;
}

void Permutation(std::string sInput, std::vector<char> vecChar)
{
    if (sInput.empty())
    {
        return;
    }

    size_t nLength = sInput.size();
    for (int nIndex = 0; nIndex != nLength; ++nIndex)
    {
        std::string sTemp(sInput);
        char cSelectedChar = *(sTemp.begin() + nIndex);
        vecChar.push_back(cSelectedChar);
        sTemp.erase(sTemp.begin() + nIndex);
        //std::cout << cSelectedChar;
        Permutation(sTemp, vecChar);
        if (nLength == 1)
        {
            PrintVectorChar(vecChar);
        }
        vecChar.pop_back();
    }
}

int main()
{
    std::string sTest("abcd");
    std::vector<char> vecDisplay;
    Permutation(sTest, vecDisplay);

    return 0;
}
