#include "praklib.h"

void print_array(double *array, int n)
{
    for (int i = 0; i < n; ++i)
        std::cout << array[i] << std::endl;
}

void quick_sort(double *array, int low, int high)
{
    int i = low;
    int j = high;
    double pivot = array[(i + j) / 2];
    double temp;

    while (i <= j)
    {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quick_sort(array, low, j);
    if (i < high)
        quick_sort(array, i, high);
}