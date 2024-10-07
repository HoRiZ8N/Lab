#include <iostream>

const int SIZE = 1000;

char s[SIZE];

void moveStr(char* s, int pos) {
    for (int j = pos; j < SIZE - 1; j++)
    {
        s[j] = s[j+1];
    }   
}

int main() {
    std::cout << "Enter a string: ";
    std::cin.getline(s, SIZE);
    int arr[256] = {};
    for (int i = 0; i < SIZE; i++) {
        arr[s[i]]++;
    }
    
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[s[i]] == 1)
        {
            moveStr(s, i);
            i--;
        }
    }
    
    std::cout <<"\nNew string: " << s; 

    return 0;
}