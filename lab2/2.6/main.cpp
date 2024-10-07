#include <cstdio>
#include <cmath>

const int n = 3, xmin = 1, xmax = 2;
const double dx = 0.25;

void directSum() {
    for (double curx = xmin; curx <= xmax; curx += dx)
    {
        double sum = 10;
        int numOfSum = 0, numOfProd = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += (2 * i * pow(curx, 2 * i));
            numOfSum++;
            numOfProd += 1 + i;
        }
        printf("DirectSum for x = %.2lf: %lf\nNumber of products: %d\nNumber of sums: %d\n\n", curx, sum, numOfProd, numOfSum);
    }   
}

void hornerSum() { 
    for (double curx = xmin; curx <= xmax; curx += dx)
    {
        double sum = 2 * n * curx * curx;
        int numOfSum = 1, numOfProd = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            sum += 2 * i;
            sum *= pow(curx, 2);
            numOfSum++;
            numOfProd += 3;
        }
        sum += 10;
        printf("HornerSum for x = %.2lf: %lf\nNumber of products: %d\nNumber of sums: %d\n\n", curx, sum, numOfProd, numOfSum);
    }   
}

int main() {

    directSum();
    hornerSum();

    return 0;
}