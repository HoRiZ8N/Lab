#include <iostream>

int main() {
    int a[100] = {};
    a[0] = 5; 

    for (int i = 0; i < 99; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            a[j] *= 5;
        }
        
        for (int j = 0; j < 100; j++)
        {
            while (a[j] >= 10) {
                a[j+1]++;
                a[j] -= 10;
            }
        }

    }
    
    bool zero = true;

    for (int i = 99; i >= 0; i--)
    {
        if (a[i] || !zero)
        {
            std::cout << a[i];
            zero = false;
        } 
    }
    
    return 0;
}