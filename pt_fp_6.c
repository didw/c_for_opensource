#include <stdio.h>

typedef int FP1[2];
typedef FP1* FP2;
typedef FP2 FP3(void);
typedef FP3* FP4;
typedef FP4 FP5(void);
typedef FP5* FP6;
typedef FP6 FP7[2];
typedef FP7* FP8;

FP2 aaa(void)
{
    static int a[2][2];
    printf("aaa()\n");
    return a;
}

FP4 bbb(void)
{
    printf("bbb()\n");
    return aaa;
}

int main()
{
    FP6 p[2][2] = {{bbb,bbb},{bbb,bbb}};
    FP8 q = p; 
    q[1][1]()()[1][1] = 10;
    return 0;
}
