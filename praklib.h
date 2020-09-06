#ifndef PRAKLIB_H
# define PRAKLIB_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>
# include <cmath>
# include <iostream>
//export DISPLAY=:0.0

double      *x_coordinate_generator(int a, int b, int number);
double      *y_coordinate_generator(double *mass_x, int number);
double      *l_coordinate_generator(double *mass_x, double *mass_y, int number);
double      lagrange(double *mass_x, double *mass_y, int number, double x);
void        quick_sort(double *array, int low, int high);
void        print_array(double *array, int n);

#endif