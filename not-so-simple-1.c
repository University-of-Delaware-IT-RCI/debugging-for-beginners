#include <stdio.h>
#include <math.h>

#if defined(__APPLE__)
#   include "baseaddr.h"

__attribute__((constructor))
void
apple_vm_info(void)
{
    show_vmaddr_base_offset();
}

#endif

double f(double);
double g(double);
double h(double);
double H(double);

//

double f(double x)
{
    return pow(h(x), 1.5); 
}

double g(double x)
{
    return sin(f(x)+M_PI_4) + cos(f(x)+M_PI_4); 
}

double h(double x)
{
    return exp(g(x) - pow(x, 2.0) * 1.380649E-23);
}

double H(double x)
{
    return 2.0 * x * x - sqrt(3.0) * x + 10.0;
}

//

double  table_of_x[] = {
    0.27885, -0.94998, -0.44994, -0.55358,  0.47294,  0.35340,  0.78436, 
   -0.82612, -0.15616, -0.94041, -0.56272,  0.01071, -0.94693, -0.60232,
    0.29977,  0.08988, -0.55912,  0.17853,  0.61886, -0.98700,  0.61164,
    0.39628, -0.31950, -0.68904,  0.91443, -0.32681, -0.81451, -0.80657,
    0.69499,  0.20745,  0.61426,  0.45946,  0.07246,  0.94623, -0.24293,
    0.10408,  0.65881,  0.23704,  0.72341,  0.15470,  0.40914, -0.90835,
   -0.54420, -0.42122, -0.84042, -0.53442, -0.79800, -0.44405,  0.27137,
   -0.27034,
    0
};

int
main()
{
    double      *x = table_of_x;
    
    /* Loop over the elements of the table_of_x list, watching for
       the sentinel value (0) signalling the end-of-list: */
    while ( x ) {
        printf("%12.5g %12.5g\n", *x, h(*x));
        x++;
    }
    return 0;
}
