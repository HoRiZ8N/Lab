#include <iostream>
#include <algorithm>
#include <cstring>

const int MAX_TEXT_SIZE = 10000;
const int SEP_SIZE = 11;
const int MAX_WORD_SIZE = 1000;
const int MAX_WORDS_IN_ARRAY = 100;

char separators[SEP_SIZE] = {' ', ';', ':', '.', ',', '!', '?', '-', '(', ')', '\0'};

bool isSeparator(char symb)
{
    for (int i = 0; i < SEP_SIZE; i++)
    {
        if (symb == separators[i])
        {
            return true;
        }
    }
    return false;
}

char **getWordsFromText(char *text, char **wordArray, int &wordCount)
{
    int l = 0, r = 0;
    int numOfWords = 0;
    
    while (text[l] != '\0')
    {
        while (isSeparator(text[l]) && text[l] != '\0') // Проверяем конец строки
        {
            l++;
        }
        
        r = l;
        while (!isSeparator(text[r]) && text[r] != '\0') // Проверяем конец строки
        {
            r++;
        }

        if (r > l)
        {
            int wordLength = r - l;
            strncpy(wordArray[numOfWords], text + l, wordLength);
            wordArray[numOfWords][wordLength] = '\0';
            numOfWords++;

            if (numOfWords >= MAX_WORDS_IN_ARRAY) // Защита от переполнения массива
                break;
        }
        l = r;
    }
    wordCount = numOfWords;
    return wordArray;
}

void printWordArray(char **wordArray, int wordCount)
{
    for (int i = 0; i < wordCount; i++)
    {
        std::cout << wordArray[i] << ' ';
    }
    std::cout << '\n';
}

char **createWordArray()
{
    char **wordArray = new char *[MAX_WORDS_IN_ARRAY];
    for (int i = 0; i < MAX_WORDS_IN_ARRAY; i++)
    {
        wordArray[i] = new char[MAX_WORD_SIZE];
        wordArray[i][0] = '\0';
    }
    return wordArray;
}

void freeWordArray(char **wordArray)
{
    for (int i = 0; i < MAX_WORDS_IN_ARRAY; i++)
    {
        delete[] wordArray[i];
    }
    delete[] wordArray;
}

char* findAnagramWords(char **words, int wordCount)
{
    char *result = new char[MAX_TEXT_SIZE];
    result[0] = '\0'; // Очищаем строку

    char** sortedWords = createWordArray();
    bool *used = new bool[wordCount](); // Динамический массив флагов

    for (int i = 0; i < wordCount; i++)
    {
        strcpy(sortedWords[i], words[i]);
        std::sort(sortedWords[i], sortedWords[i] + strlen(sortedWords[i]));
    }

    bool foundAnyAnagram = false;
    for (int i = 0; i < wordCount; i++)
    {
        if (used[i])
            continue;
        bool foundAnagram = false;
        for (int j = i + 1; j < wordCount; j++)
        {
            if (!used[j] && strcmp(sortedWords[i], sortedWords[j]) == 0)
            {
                if (!foundAnagram)
                {
                    std::cout << words[i] << ' ';
                    foundAnagram = true;
                    strcat(result, words[i]);
                    strcat(result, " ");
                }
                std::cout << words[j] << ' ';
                strcat(result, words[j]);
                strcat(result, " ");
                used[j] = true;
                foundAnyAnagram = true;
            }
        }
        if (foundAnagram)
        {
            std::cout << '\n';
        }
    }

    if (!foundAnyAnagram)
    {
        std::cout << "No anagram words found.\n";
    }

    freeWordArray(sortedWords);
    delete[] used; // Освобождаем динамический массив флагов

    return result; // Теперь корректно возвращаем динамически выделенную память
}

int main()
{
    int wordCount = 0;
    char text[MAX_TEXT_SIZE];
    char** wordArray = createWordArray();

    std::cout << "Enter your text: ";
    std::cin.getline(text, MAX_TEXT_SIZE);

    wordArray = getWordsFromText(text, wordArray, wordCount);

    std::cout << "\nWords:\n";
    printWordArray(wordArray, wordCount);

    std::cout << "\nAnagrams:\n";
    char* result = findAnagramWords(wordArray, wordCount);

    std::cout << "\nFinal string: " << result << '\n';

    freeWordArray(wordArray);
    delete[] result;

    return 0;
}
