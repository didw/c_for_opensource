#include <stdio.h>

int (*aaa(void))[2]
{
    static int a[2][2];
    printf("aaa()\n");
    return a;
}

int (*(*bbb(void))(void))[2]
{
    printf("bbb()\n");
    return aaa;
}

int main()
{
    int (*(*(*p[2][2])(void))(void))[2] = {{bbb,bbb},{bbb,bbb}};
    int (*(*(*(*q)[2])(void))(void))[2] = p;
    q[1][1]()()[1][1] = 10;

    return 0;
}
