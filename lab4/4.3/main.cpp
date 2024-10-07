#include <iostream>

const int SIZE = 10000;

char s[SIZE];
char new_s[SIZE];
int currpos = 0;

const int sepSize = 11;
char separators[sepSize] = { ' ', ';', ':', '.', ',', '!', '?', '-', '(', ')', '\0'};

bool isInArray(char symb) {
    for (int i = 0; i < sepSize; i++) {
        if (symb == separators[i]) {
            return true;
        }
    }
    return false;
}   

void addWord(int l, int r) {
    for (int i = l; i < r; i++) {
        new_s[currpos] = *(s + i);
        currpos++;
    }
}

bool isEven(int size) {
    if (size % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

bool isSymetrical(int l, int r) {
    for (int i = 0; i < r - l; i++)
    {
        if (s[l + i] != s[r - i - 1])
        {
            return false;
        }
        
    }
    return true;
}

void printS() {
    int i = 0;
    printf("New string: ");
    while(s[i] != '\0') {
        std::cout << new_s[i];
        i++;
    }
}

int main()
{
    std::cout << "Enter a string: ";
    std::cin.get(s, SIZE);

    int l = 0, r = 0;
    while (s[l] != '\0' && s[r] != '\0') {
        while (isInArray(s[l])) {
            l++;
            if (s[l] == '\0') {
                printS();
                return 0;
            } 
        }
        r = l;
        while (!isInArray(s[r])) {
            r++;
        }
        if (!isSymetrical(l, r) && isEven(r - l)) {
            addWord(l, r);
        }  
        l = r;
    }
    
    printS();
  
    return 0;
}