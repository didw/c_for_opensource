#include <stdio.h>
void aaa(void)
{
    printf("aaa()\n");
}

void (*bbb(void))(void)
{
    printf("bbb()\n");
    return aaa;
}

int main()
{
    bbb()();
    return 0;
}
