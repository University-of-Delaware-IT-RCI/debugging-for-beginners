#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double
mypyfunc(
    int     n,
    double  v
)
{
    #define IABS(I)     (((I) < 0) ? -I : I)
    #define COEFF_MAX   5
    
    static double *__expansion_coeffs = NULL;
    
    double  result = 0.0;
    
    if ( __expansion_coeffs == NULL ) {
        int     i, i_max = COEFF_MAX / 2;
        
        __expansion_coeffs = (double*)malloc(COEFF_MAX * sizeof(double));
        for ( i = 0; i < COEFF_MAX; i++ ) __expansion_coeffs[i] = (COEFF_MAX / 2) + 1 - IABS(i - i_max);
    }
    
    while ( n >= 0 ) {
        result += __expansion_coeffs[n*n] * pow(v, n) * pow(-1.0, n);
        n--;
    }
    return result;
    
    #undef IABS
}

