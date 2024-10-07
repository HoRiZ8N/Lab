#include <iostream>

int zero_count(int num)
{
    int count = 0;

    do {
        if (num % 2 == 0) {
            count++;
        }
        num /= 2;
    } while (num);

    return count;
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    bool a[n+1] = {};
    

    for (int i = 2; i <= (n + 1) / 2; i++)
    {
        for (int j = i * i; j <= n + 1; j += i)
        {
            a[j] = true;
        }
        
    }

    int max0 = 0;
    int maxi = 0;

    for (int i = 2; i <= n; i++)
    {
        if (!a[i])
        {
            if (max0 < zero_count(i))
            {
                max0 = zero_count(i);
                maxi = i;
            }            
        }
    }
    
    std::cout << "Prime number: " << maxi << "\nZero count: " << max0;

    return 0;
}