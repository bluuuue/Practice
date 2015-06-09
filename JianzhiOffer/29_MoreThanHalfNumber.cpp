#include <iostream>
#include <map>

int MoreThanHalfNum1(int* num, int nLength)
{
    //the method using map to create hash table
    if ( num == NULL || nLength <= 0)
    {
        return -1;
    }
    else if (nLength == 1)
    {
       return num[0];
    } 

    std::map<int, int> mapHash;
    for (int nIndex = 0; nIndex != nLength; ++nIndex)
    {
        std::map<int, int>::iterator it = mapHash.find(*(num + nIndex));
        if (it == mapHash.end())
        {
            mapHash.insert(std::pair<int, int>(*(num + nIndex), 1));
        }
        else
        {
            mapHash.insert(std::pair<int, int>(*(num + nIndex), ++mapHash[*(num + nIndex)] ));
            if (mapHash[*(num + nIndex)] > nLength / 2)
            {
                return *(num + nIndex);
            }
        }
    }

    return -1;
}

bool CheckMoreThanHalf(int *numbers, int length, int num)
{
    int times = 0;
    for (int i = 0; i < length; ++i)
    {
        if ( numbers[i] == num)
        {
            ++times;
        }
    }

    bool bIsMoreThanHalf = true;
    if (2 * times <= length)
    {
        bIsMoreThanHalf = false;
    }

    return bIsMoreThanHalf;
}

int MoreThanHalfNum2(int *num , int nLength)
{
    if ( num == NULL || nLength <= 0)
    {
        return -1;
    }

    int result = num[0];
    int times = 1;
    for (int i = 1; i < nLength; ++i)
    {
        if (times == 0)
        {
            result = num[i];
            times = 1;
        }
        else if (num[i] == result)
        {
            ++times;
        }
        else 
        {
            --times;
        }
    }
    
    if (!CheckMoreThanHalf(num, nLength, result))
    {
        result = 0;
    }

    return result;    
}

int main()
{
    int num[9] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    int num2[1] = {1};

    clock_t tStart1, tStart2, tFinish1, tFinish2;
    tStart1 = clock();

    std::cout << MoreThanHalfNum1(num, 9) << std::endl;
    std::cout << MoreThanHalfNum1(num2, 1) << std::endl;

    tFinish1 = clock();
    std::cout << "Method 1 time consume: " << (tFinish1 - tStart1) << "us." << std::endl;

    tStart2 = clock();

    std::cout << MoreThanHalfNum2(num, 9) << std::endl;
    std::cout << MoreThanHalfNum2(num2, 1) << std::endl;

    tFinish2 = clock();

    std::cout << "Method 2 time consume: " << (tFinish2 - tStart2) << "us." << std::endl;

    return 0;
}
