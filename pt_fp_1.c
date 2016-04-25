#include <stdio.h>
int (*foo(void))[2] 
{
    static int a[2][2];
    return a;
}

int main()
{
    foo()[1][1] = 10;
    return 0;
}
