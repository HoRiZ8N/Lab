#include <iostream>

int main() {

    long long const size = 1'000'000'000;
    bool* a = new bool[size];
    

    for (long long i = 2; i <= (size + 1) / 2; i++)
    {
        for (long long j = i * i; j <= size + 1; j += i)
        {
            a[j] = true;
        }
        
    }

    long long max = 0;
    for (long long i = 0; i < size; i++)
    {
        if (!a[i])
        {
            max = std::max(max, i);
        }
        
    }
    
    std::cout << max;

    delete[] a;
    return 0;
}