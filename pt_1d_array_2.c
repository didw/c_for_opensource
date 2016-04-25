#include <stdio.h>
int main()
{
    int a[4] = {1,2,3,4};
    int (*p) = a;
    p[3] = 10;
    return 0;
}
