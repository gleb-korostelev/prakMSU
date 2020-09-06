#include "praklib.h"

double      lagrange(double *mass_x, double *mass_y, int number, double x)
{
    int     i;
    int     j;
    double  lagrange = 0;
    double  basic;

        for (i = 0; i < number; i++)
        {
            basic = 1;
            for (j = 0; j < number; j++)
            {
                if (j != i)
                    basic *= ((x - mass_x[j]) / (mass_x[i] - mass_x[j])); 
            }
            lagrange += basic * mass_y[i];
        }
    return (lagrange);
}