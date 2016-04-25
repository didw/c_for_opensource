#include <stdio.h>
void foo(void)
{
    printf("foo()\n");
}

int main()
{
    void (*p)(void) = foo;
    p();
    return 0;
}
