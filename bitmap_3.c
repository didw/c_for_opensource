#include <stdio.h>

#define __FD_SETSIZE        1024
#define __NFDBITS   (8 * (int) sizeof (__fd_mask))
#define __FD_ELT(d) ((d) / __NFDBITS)
#define __FD_MASK(d)    ((__fd_mask) (1UL << ((d) % __NFDBITS)))

typedef long int __fd_mask;
typedef struct
{
    __fd_mask __fds_bits[__FD_SETSIZE / __NFDBITS];
# define __FDS_BITS(set) ((set)->__fds_bits)
} fd_set;


#define __FD_SET(d, s) \
    ((void) (__FDS_BITS (s)[__FD_ELT(d)] |= __FD_MASK(d)))
#define __FD_CLR(d, s) \
    ((void) (__FDS_BITS (s)[__FD_ELT(d)] &= ~__FD_MASK(d)))
#define __FD_ISSET(d, s) \
    ((__FDS_BITS (s)[__FD_ELT (d)] & __FD_MASK (d)) != 0)

#define __FD_ZERO(s) \
    do {                                        \
        unsigned int __i;                                 \
        fd_set *__arr = (s);                              \
        for (__i = 0; __i < sizeof (fd_set) / sizeof (__fd_mask); ++__i)       \
        __FDS_BITS (__arr)[__i] = 0;                        \
    } while (0)

#define FD_SET(fd, fdsetp)  __FD_SET (fd, fdsetp)
#define FD_CLR(fd, fdsetp)  __FD_CLR (fd, fdsetp)
#define FD_ISSET(fd, fdsetp)    __FD_ISSET (fd, fdsetp)
#define FD_ZERO(fdsetp)     __FD_ZERO (fdsetp)
//-------------------------------------------------------------------
int main()
{
    fd_set flags;
    int i;

    if( 1 )
        FD_ZERO( &flags );
    else
        printf("...\n");

    FD_SET( 700, &flags );
    FD_SET( 800, &flags );
    for(i=0; i<1024; i++ )
        if( FD_ISSET( i, &flags ) )
            printf("%d\n", i );

    FD_CLR( 800, &flags );
    printf("------\n");
    for(i=0; i<1024; i++ )
        if( FD_ISSET( i, &flags ) )
            printf("%d\n", i );
    return 0;
}
