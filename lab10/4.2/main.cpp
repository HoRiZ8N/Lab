#include "LinkedList.h"
#include <fstream>

LinkedList<char> FormListWithTwoOccurrences(LinkedList<char>& L1) {
    const short charSize = 256;
    LinkedList<char> L2;
    int counts[charSize] = {0};

    for (size_t i = 0; i < L1.Size(); ++i) {
        char currentChar = L1.Search(i);
        counts[static_cast<unsigned char>(currentChar)]++;
    }

    for (int c = 0; c < charSize; ++c) {
        if (counts[c] == 2) {
            L2.PushBack(static_cast<char>(c));
        }
    }

    return L2;
}

int main()
{
    std::ifstream input;
    input.open("input.txt");
    
    LinkedList<char> list;
    input >> list;
    std::cout << FormListWithTwoOccurrences(list);
    input.close();

    return 0;
}