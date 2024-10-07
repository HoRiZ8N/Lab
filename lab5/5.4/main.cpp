#include <iostream>
#include <cstring>

const int SIZE = 1000;

char str[SIZE];
const char toInsert[] = "EXAMPLE, ";

void insert(char* s, const char* ss, int n) {
    int ssSize = 0;
    while (ss[ssSize] != '\0') {
        ssSize++;
    }
    for (int i = SIZE - 1; i >= n + ssSize; i--) {
        s[i] = s[i - ssSize];
    }
    for (int i = 0; i < ssSize; i++) {
        s[n + i] = ss[i];
    }
    
}

int main()
{

    std::cout << "Enter new string: ";
    std::cin.getline(str, SIZE);

    int pos = 0;
    while (str[pos] != '\0') {
        if (str[pos] == ',' && str[pos + 1] == ' ') {
            pos += 2;
            insert(str, toInsert, pos);
            pos += std::strlen(toInsert) - 1;
        }
        pos++;
    }
    
    std::cout << "New string: " << str;

    return 0;
}