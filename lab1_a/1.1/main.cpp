#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x;
    cin >> x;
    if (x == 0 || (sin(M_PI * x * x) + sin(x) + log(x * x) + (x * x) + pow(M_E, cos(x))) == 0)
    {
        cout << "Function is undefined";
    } else {
        cout << ((sin(M_PI * x * x) + log(x * x)) / (sin(M_PI * x * x) + sin(x) + log(x * x) + (x * x) + pow(M_E, cos(x))));
    }
    

    return 0;
}