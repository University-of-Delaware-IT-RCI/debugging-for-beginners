#include <stdio.h>
#include <math.h>

int
main()
{
    volatile int        zero = 0;
    int                 inf;
    
    printf("What happens if we force the compiler to let us do an\n"
           "integer division by zero?\n\n");
           
    inf = 1 / zero;
    
    printf("An infinite value for an int is %1$d (0x%1$08X).\n\n", inf);
    return 0;
}
