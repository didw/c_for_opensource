#include <stdio.h>
void bbb(void (*p)(void))
{
    p();
    printf("bbb()\n");
}

void aaa(void)
{
    printf("aaa()\n");
}

int main()
{
    bbb(aaa);
    return 0;
}
