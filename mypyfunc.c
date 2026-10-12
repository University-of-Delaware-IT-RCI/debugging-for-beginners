#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double
mypyfunc(
    int     n,
    double  v
)
{
    double  result = 0.0;
    
    if ( n < 5 ) {
        while ( n >= 0 ) result += pow(v, n) * pow(-1.0, n), n--;
        return ((1.0 / (double)(n*n))) * result;
    }
    return *((double*)0xCAFEBABEFEEDFACE);
}

