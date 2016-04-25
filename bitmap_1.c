#include <stdio.h>
int main()
{
    int flags[32] = {0,};
    int i;

    flags[700/32] |= 1<<(700%32);
    flags[800/32] |= 1<<(800%32);
    for(i=0; i<1024; i++ )
        if( flags[i/32] & (1<<(i%32)) )
            printf("%d\n", i );

    flags[800/32] &= ~(1<<(800%32));
    printf("------\n");
    for(i=0; i<1024; i++ )
        if( flags[i/32] & (1<<(i%32)) )
            printf("%d\n", i );
    return 0;
}
