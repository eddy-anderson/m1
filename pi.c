#include <stdio.h>
#include <math.h>

#include "timer.h"
#include "pi_funs.h"

int adjust_rep_count (int count, double time, double tmin, double tmax);
double pi_leibniz (int n);
double bbp (int n);

int main (void)
{                               //Define variables
    double a;
    double tol = (1. / 1000000);
    int i, ileibniz, ibbp;
    double tmin = 1., tmax = 2.;
    double pi;
    double time, time1, time2;
    int count;

    i = 1;

    //Run the leibniz series until acceptible error is reached
    do
    {
        pi = pi_leibniz (i);
        a = fabs (pi - M_PI);
        printf ("%8d %20.15f %20.15f\n", i, pi, a);
        i *= 2;
    }
    while (a > tol);
    ileibniz = i / 2;


    i = 1;

    //Run the Bailey-Borwein-Ploufe series until an acceptible error is reached
    do
    {
        pi = pi_bbp (i);
        a = fabs (pi - M_PI);
        printf ("%8d %20.15f %20.15f\n", i, pi, a);
        i *= 2;
    }
    while (a > tol);
    ibbp = i / 2;

    count = 1000;

//Time the Bailey-Borwein-Ploufe series requires to reach acceptible error
    do
    {
        timer_start ();

        for (i = 0; i < count; i++)
        {
            pi = pi_bbp (ibbp);
        }
        time = timer_stop ();
        time1 = time / count;
        printf (" %10.2f usec %10.6f sec %10d\n", time1 * 1.e6, time, count);

        count = adjust_rep_count (count, time, tmin, tmax);
    }
    while ((time > tmax) || (time < tmin));
    printf (" %10.2f usec %10.6f sec %10d\n", time1 * 1.e6, time, count);

    count = 1000;

//Time for the Leibniz series to reach an acceptible error
    do
    {
        timer_start ();

        for (i = 0; i < count; i++)
        {
            pi = pi_leibniz (ileibniz);
        }
        time = timer_stop ();
        time2 = time / count;
        printf ("%10.2f usec %10.6f sec %10d \n", time2 * 1.e6, time, count);

        count = adjust_rep_count (count, time, tmin, tmax);
    }
    while ((time > tmax) || (time < tmin));
    printf (" %10.2f usec %10.6f sec %10d\n", time2 * 1.e6, time, count);


    time1 *= 1.e6;              //convert time to seconds
    time2 *= 1.e6;
    double ratio = time2 / time1;

    //Print results
    printf
        (" tLeibniz: %5.0f usec \n tBBP: %5.2f usec \n tLeibniz/tBBP: %5.0f \n",
        time2, time1, ratio);

    return 0;
}
