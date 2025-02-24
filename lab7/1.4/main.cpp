#include <iostream>
#include <cmath>
#include <iomanip>

double f1(double x)
{
    return (x - 1) * (x - 1) - 3;
}

double f2(double x, double s)
{
    return exp(x - s) - sqrt(x + 1);
}

double bisection_method(double a, double b, int &iterations, double (*func)(double, double),
                        double s = 0.0, double epsilon = 1e-6)
{
    iterations = 0;
    double mid;
    while ((b - a) / 2.0 > epsilon)
    {
        mid = (a + b) / 2.0;
        if (func(mid, s) * func(a, s) < 0)
        {
            b = mid;
        }
        else
        {
            a = mid;
        }
        iterations++;
    }
    return (a + b) / 2.0;
    if (iterations > 100)
    {
        std::cerr << "Error";
    }
    return 0;
}

double bisection_method(double a, double b, int &iterations, double (*func)(double),
                        double epsilon = 1e-6)
{
    iterations = 0;
    double mid;
    while ((b - a) / 2.0 > epsilon)
    {
        mid = (a + b) / 2.0;
        if (func(mid) * func(a) < 0)
        {
            b = mid;
        }   
        else
        {
            a = mid;
        }
        iterations++;
    }
    return (a + b) / 2.0;
    if (iterations > 100)
    {
        std::cerr << "Error";
    }
    return 0;
}

int main()
{
    int iterations = 0;
    double a = 1.0, b = 4.0, s = 0.3, delta_s = 0.1;

    std::cout << "  +----------+----------+-----------------+--------+" << std::endl;
    std::cout << "  |    s     |    x     |      f(x)       | k_iter |" << std::endl;
    std::cout << "  +----------+----------+-----------------+--------+" << std::endl;
    std::cout << std::fixed << std::setprecision(6);

    double x1 = bisection_method(a, b, iterations, f1);

    std::cout << "  | -------- | " << std::setw(8) << x1 << " | " << std::setw(15) << f1(x1) << " | " << std::setw(6) << iterations << " |" << std::endl;
    std::cout << "  +----------+----------+-----------------+--------+" << std::endl;

    a = 0.0, b = 2.0;

    for (; s <= 0.7; s += delta_s)
    {
        double x2 = bisection_method(a, b, iterations, f2, s);
        std::cout << "  | " << std::setw(4) << s << " | " << std::setw(8) << x2 << " | " << std::setw(15) << f2(x2, s)
                  << " | " << std::setw(6) << iterations << " |" << std::endl;
    }

    std::cout << "  +----------+----------+-----------------+--------+" << std::endl;

    return 0;
}
