#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

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


int GetNumberOf1(const int n)
{
	if (n <= 0)
	{
		return 0;
	}

    std::string str;
    ConvertIntToString(n, str);

	int nDigits = str.size();



	return nDigits;
}

int main()
{
	std::cout << "The number of 1 is: " << GetNumberOf1(12345) << std::endl;

	return 0;
}
