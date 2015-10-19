#include <iostream>
using namespace std;

int ViolentMatch(char const *s, char const *p)
{
    if (s == NULL || p == NULL)
        return -1;

    int sLen = strlen(s);
    int pLen = strlen(p);
    
    int i = 0;
    int j = 0;
    while (i < sLen && j < pLen)
    {
        if (s[i] == p[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }

    if (j == pLen)
        return (i - j);
    else
        return -1;
}

void GetNext(char const *p, int next[])
{
    if (p == NULL || next == NULL)
        return;

    int pLen = strlen(p);
    //next = new int[pLen];
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < pLen - 1)
    {
        if (k == -1 || p[j] == p[k])
        {
            ++k;
            ++j;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}

int KMPSearch(char const *s, char const *p, int next[])
{
    if (s == NULL || p == NULL)
        return -1;

    int sLen = strlen(s);
    int pLen = strlen(p);
    
    int i = 0;
    int j = 0;
    while (i < sLen && j < pLen)
    {
        if (s[i] == p[j] || j == -1)
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }

    if (j == pLen)
        return (i - j);
    else
        return -1;
}

int main()
{
    char const *s = "bbc abcdab abcdabcdabde";
    //char const *p = "abcdabd";
    char const *p = "ababcaabc";
    cout << ViolentMatch(s, p) << endl;

    int pLen = strlen(p);
    int *next = new int[pLen]; 
    GetNext(p, next);
    for (int i = 0; i < pLen; i++)
        cout << next[i];
    cout << endl;
    cout << KMPSearch(s, p, next) << endl;
    
    delete next;
    next = NULL;
    return 0;
}
