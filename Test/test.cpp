#include <stdio.h>


char *GetStr()
{
    //char p[] = "abcde";
    char *p = new char[10];
    *p = 'c';
    *(p + 1) = 'd';

    printf("%s\n", p);
    return p;
}
void GetStr2()
{
    char ss[] = "aaaaaaaaaaaaaaaaaaaaaa";
}

int main()
{
    char *p = GetStr();
    printf("%s\n", p);
    GetStr2();
    printf("%s\n", p);
    return 0;
}
