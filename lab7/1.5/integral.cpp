#include <iostream>
#include <cmath>
#include "integral.h"

double f(double x, double s, double t)
{
    return sqrt(1 + x * x) * exp(-sin(x) - s - t);
}

double testFunc(double x, double, double)
{
    return x;
}

double leftRectangleMethod(double a, double b, double s, double t, double epsilon, int &k_iter, double (*func)(double, double, double))
{
    int n = 10;
    double prev_integral = 0.0, integral;
    k_iter = 0;

    do
    {
        k_iter++;
        prev_integral = integral;
        integral = 0.0;
        double h = (b - a) / n;

        for (int i = 0; i < n; i++)
        {
            double x = a + i * h;
            integral += func(x, s, t);
        }

        integral *= h;
        n *= 2;
    } while (fabs(integral - prev_integral) > epsilon);

    return integral;
}
