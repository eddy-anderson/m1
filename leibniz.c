#include <stdio.h>
#include "pi_funs.h"
#include <math.h>

double pi_leibniz (int n)
{
    double p = 0;
    int q = 1;
    int i;

    for (i = 0; i < n; i++)
    {
        p += q * (1. / (2 * i + 1));
        q *= -1;
    }
    return 4 * p;
}
/*
int main (void)
{
    int i = 1;
    double tol = (1. / 1000000);
    double a;

    do
    {
        double pi = pi_leibniz (i);

        a = fabs (pi - M_PI);
        printf ("%8d %20.15f %20.15f\n", i, pi, a);
        i *= 2;
    }
    while (a > tol);
}
*/
