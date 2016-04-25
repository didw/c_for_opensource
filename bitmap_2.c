#include <stdio.h>

#define BIT_SET( index, x )    ((x)->data[index>>5] |=  1<<(index&31))
#define BIT_ISSET( index, x )  ((x)->data[index>>5] &   1<<(index&31))
#define BIT_CLR( index, x )    ((x)->data[index>>5] &= ~1<<(index&31))
#define BIT_ZERO(x)              \
    do {int i;                   \
        for(i=0; i<32; i++)      \
            (x)->data[i] = 0; } while(0)

typedef struct
{
    int data[32];
} bit_set;

int main()
{
    bit_set flags;
    int i;
    if (1)
        BIT_ZERO( &flags );
    else
        printf("...\n");

    BIT_SET( 700, &flags );
    BIT_SET( 800, &flags );
    for(i=0; i<1024; i++)
        if( BIT_ISSET( i, &flags ))
            printf("%d\n", i);

    BIT_CLR( 800, &flags );
    for(i=0; i<1024; i++)
        if( BIT_ISSET( i, &flags ))
            printf("%d\n", i);
    return 0;
}
