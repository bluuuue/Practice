#include <stdio.h>

#define swap(a, b) (a = a^b, b = a^b, a = a^b)

int main()
{
    int a = 3;
    int b = 4;

    swap(a, b);
    printf("%d\t%d\n",a,b);

    return 0;
}
