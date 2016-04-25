#include <stdio.h>
int main()
{
    int a[2][2] = {1,2,3,4};
    int (*p)[2] = a;
    p[1][1] = 10;
    return 0;
}
