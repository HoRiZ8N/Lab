#include <iostream>
#include <cmath> 

using namespace std;

double taylor_exp(double x) {
    double curr = 1.0; 
    double sum = curr; 
    int n = 1; 
    
    while (abs(curr) > 1e-6) {
        curr *= x / n;
        sum += curr;
        n++;
    }
    
    return sum;
}

int main() {
    double x0 = -4.0;
    double xn = 6.0;
    double dx = 0.5;


    cout << "Taylor row solution: " << endl;
    for (double x = x0; x <= xn; x += dx) {
        cout << "x = " << x << ", y (Taylor) = " << taylor_exp(x) - 1 << endl;
    }

    cout << "\nExp funcion solution: \n";
    for (double x = x0; x <= xn; x += dx) {
        cout << "x = " << x << ", y (exp) = " << exp(x) - 1 << endl;
    }

    return 0;
}
