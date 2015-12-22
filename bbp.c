#include <stdio.h>
#include "pi_funs.h"
#include <math.h>

double pi_bbp (int n)
{
    double p = 0;
    double r = 1. / 16;
    int i;
    int q;
    double s = 1.;

    for (i = 0; i < n; i++)
    {
        q = 8 * i;
        p += s * ((4. / (q + 1)) - (2. / (q + 4)) - (1. / (q + 5)) -
            (1. / (q + 6)));
        s *= r;
    }
    return p;
}
/*
int main (void)
{
    int i = 1;
    double tol = (1. / 1000000);
    double a;

    do
    {
        double pi = pi_bbp (i);

        a = fabs (pi - M_PI);
        printf ("%8d %20.15f %20.15f\n", i, pi, a);
        i *= 2;
    }
    while (a > tol);
}
*/
