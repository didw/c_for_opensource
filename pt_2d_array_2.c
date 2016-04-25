#include <stdio.h>
void foo(int (*p)[2])
{
    int i,j;
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("a[%d][%d]=%d\n", i, j, p[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a[2][2] = {1,2,3,4};
    foo(a);
    return 0;
}
