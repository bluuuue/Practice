#include <iostream>
#include "QuickSort.h"
#include <set>
#include <vector>
typedef std::multiset<int, std::greater<int> > intSet;
typedef std::multiset<int, std::greater<int> >::iterator setIterator;

void GetKLeastNumbers_1(int *numbers, int nLength, int *output, int k)
{
    //use quick sort to get k least numbers
    if (numbers == NULL || nLength <= 0 || k <= 0 || k > nLength)
    {
        return ;
    }

    QuickSort(numbers, nLength);

    for (int nIndex = 0; nIndex != k; ++nIndex)
    {
        output[nIndex] = numbers[nIndex];
    }
}

void GetKLeastNumbers_2(const std::vector<int> &data, intSet &setKNum, int k)
{
    if (k <= 0 || k > data.size() )
    {
        return ;
    }

    setKNum.clear();

    for (std::vector<int>::const_iterator iter = data.begin(); \
            iter != data.end(); ++iter)
    {
        if (setKNum.size() < k)
        {
            setKNum.insert(*iter);
        }
        else
        {
            setIterator iterGreatest = setKNum.begin();
            if (*iter < *(setKNum.begin()))
            {
                setKNum.erase(iterGreatest);
                setKNum.insert(*iter);
            }
        }
    }
}

void PrintSet(intSet setData)
{
    if (setData.size() <= 0)
    {
        return ;
    }

    for (setIterator iter = setData.begin();\
            iter != setData.end(); ++iter)
    {
        std::cout << *iter << "\t";
    }
    std::cout << std::endl;

    return ;
}

int main()
{
    clock_t tStart1, tStart2, tEnd1, tEnd2;

    int data[8] = {19, 32, 33, 13, 5, 11, 3, 0};
    int kNumbers[4] = {};
    tStart1 = clock();
    GetKLeastNumbers_1(data, 8, kNumbers, 4);
    tEnd1 = clock();
    PrintArray(kNumbers, 4);
    std::cout << "Quick sort time consume: " << (tEnd1 - tStart1) << "us." << std::endl;

    std::vector<int> vecData;
    vecData.push_back(19);
    vecData.push_back(32);
    vecData.push_back(33);
    vecData.push_back(13);
    vecData.push_back(5);
    vecData.push_back(11);
    vecData.push_back(3);
    vecData.push_back(0);
    intSet setKNumbers;
    tStart2 = clock();
    GetKLeastNumbers_2(vecData, setKNumbers, 4);
    tEnd2 = clock();
    PrintSet(setKNumbers);
    std::cout << "Red black tree time consume: " << (tEnd2 - tStart2) << "us." << std::endl;


    return 0;
}
