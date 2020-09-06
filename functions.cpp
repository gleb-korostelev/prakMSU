#include "praklib.h"
#define _USE_MATH_DEFINES

double   *x_coordinate_generator(int a, int b, int number)
{
    double      *mass_x;
    int         i;
    int         hold;

    i = 0;
    hold = number;
    mass_x = (double*)malloc(sizeof(double) * (number + 1));
    srand((unsigned int)time(NULL));
    while (number--)
    {
        mass_x[i] = a + (b - a) * ((double)rand()) / ((double)(RAND_MAX));
        i++;
    }
    quick_sort(mass_x, 0, hold);
    mass_x[0] = a;
    mass_x[hold - 1] = b;
    return (mass_x);
}

double   *y_coordinate_generator(double *mass_x, int number)
{
    double   *mass_y;
    int     i;

    i = 0;
    mass_y = (double*)malloc(sizeof(double) * (number + 1));
    while (number--)
    {
        mass_y[i] = cos(5*M_PI*mass_x[i]);
        i++;
    }
    return (mass_y);
}

double  *l_coordinate_generator(double *mass_x, double *mass_y, int number)
{
    double  *mass_l;
    mass_l = (double*)malloc(sizeof(double) * (number + 1));
    for (int i = 0; i < number; i++)
        mass_l[i] = lagrange(mass_x, mass_y, number, mass_x[i] + 0.1);
    return (mass_l);
}