#include "praklib.h"
#include "matplotlib-cpp/matplotlibcpp.h"

namespace plt = matplotlibcpp;

int     main(void)
{
    int     number;
    int     a;
    int     b;
    int     i;
    double  *res_x;
    double  *res_y;
    double  *res_l;
    double  lag;
    std::vector<double> x, y, l,w;

    a = 0;
    b = 1;
    number = 100;
    res_x = x_coordinate_generator(a, b, number);
    res_y = y_coordinate_generator(res_x, number); // I'll use function "cos 5pix"
    res_l = l_coordinate_generator(res_x, res_y, number);
    for (i = 0; i < number; i++) 
    {
        x.push_back(res_x[i]);
        y.push_back(res_y[i]);
        l.push_back(res_l[i]);
        w.push_back(0);
    }
    plt::title("prak");
    plt::xlim(a, b);
    plt::ylim(-1.2, 1.2);
    plt::plot(x, w,"r--");
    plt::named_plot("cos(5pix)", x, y, "-y");
    plt::named_plot("L(x)", x, l, "-bo");
    plt::legend();
    plt::show();
    free(res_x);
    free(res_y);
    free(res_l);
    return (0);
}