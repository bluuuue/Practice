#include "IntToStr.h"

void ConvertIntToString(const int nNum, std::string &strString)
{
    if (nNum < 0)
    {
        return ;
    }

    int num = nNum;
    std::stringstream ss;
    
    if (num == 0)
    {
        ss << 0;
    }
    else
    {
        while (num > 0)
        {
            ss << (num - (num / 10) * 10);
            num /= 10;
        }
    }

    strString = ss.str();
    reverse(strString.begin(), strString.end());
}

