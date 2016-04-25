#include <stdio.h>

typedef int (*FP1)[2];
typedef FP1 (*FP2)(void);
typedef FP2 (*FP3)(void);
typedef FP3 (*FP4)[2];

FP1 aaa(void)
{
    static int a[2][2];
    printf("aaa()\n");
    return a;
}

FP2 bbb(void)
{
    printf("bbb()\n");
    return aaa;
}

int main()
{
    FP3 p[2][2] = {{bbb,bbb},{bbb,bbb}};
    FP4 q = p; 
    q[1][1]()()[1][1] = 10;
    return 0;
}
