#include <iostream>
#define LENGTH 10

int GetFirstK(int* pNum, int nLength, int k)
{
    if (pNum == NULL || nLength <= 0)
    {
        return -1;
    }

    if (pNum[0] > k || pNum[nLength - 1] < k)
    {
        return -1;
    }

    int nHalfLength = 0;
    if (nLength % 2 == 0)
    {
        nHalfLength = nLength / 2;
    }
    else
    {
        nHalfLength = nLength / 2 + 1;
    }

    if (pNum[nLength / 2] == k)
    {
        if(pNum[nLength / 2 - 1] < k)
        {
            return nLength / 2;
        }
        else
        {
            return GetFirstK(pNum, nLength / 2, k);
        }
    }
    else if(pNum[nLength / 2] > k) 
    {
        return GetFirstK(pNum, nLength / 2, k);
    }
    else
    {
        if (GetFirstK(pNum + nLength / 2, nHalfLength, k) != -1)
        {
            return nLength / 2 + GetFirstK(pNum + nLength / 2, nHalfLength, k);
        }
        else
        {
            return -1;
        }
    }

}

int GetLastK(int* pNum, int nLength, int k)
{
    if (pNum == NULL || nLength <= 0)
    {
        return -1;
    }

    if (pNum[0] > k || pNum[nLength - 1] < k)
    {
        return -1;
    }

    if (nLength == 1)
    {
        if (pNum[0] == k)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }

    int nHalfLength = 0;
    if (nLength % 2 == 0)
    {
        nHalfLength = nLength / 2;
    }
    else
    {
        nHalfLength = nLength / 2 + 1;
    }

    if (pNum[nLength / 2] == k)
    {
        if(pNum[nLength / 2 + 1] < k)
        {
            return nLength / 2;
        }
        else
        {
            if (GetLastK(pNum + nLength / 2 , nHalfLength, k) != -1)
            {
                return nLength / 2 + GetLastK(pNum + nLength / 2 , nHalfLength, k);
            }
            else
            {
                return -1;
            }
        }
    }
    else if(pNum[nLength / 2] > k) 
    {
        return GetLastK(pNum, nLength / 2, k);
    }
    else
    {
        if (GetLastK(pNum + nLength / 2, nHalfLength, k) != -1)
        {
            return nLength / 2 + GetLastK(pNum + nLength / 2, nHalfLength, k);
        }
        else
        {
            return -1;
        }
    }

}

int GetNumberOfK(int* pNum, int nLength, int k)
{
    if (pNum == NULL || k <= 0)
    {
        return 0;
    }

    if (GetFirstK(pNum, nLength, k) != -1)
    {
        return GetLastK(pNum, nLength, k) - GetFirstK(pNum, nLength, k) + 1; 
    }
    else
    {
        return 0;
    }
}

int main()
{
    int pNum[LENGTH] = {0, 1, 3, 3, 3, 3, 4, 5, 13, 21};
    int k = 21;
    std::cout << "The number of k: " << GetNumberOfK(pNum, LENGTH, k) << "." << std::endl;

    return 0;
}
